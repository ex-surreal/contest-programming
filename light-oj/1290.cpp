#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))

typedef int type;

const int N = 105;
type inf = 1<<29;

type cost[N][N];
type lx[N], ly[N];
int xy[N], yx[N];
bool S[N], T[N];
int slack[N], slackx[N];
int Q[N], pre[N];
int n;

void init() {
  fill(xy, xy+n, -1);
  fill(yx, yx+n, -1);
  fill(ly, ly+n, 0);
  rep(x, n) {
    lx[x] = 0;
    rep(y, n) {
      lx[x] = max(lx[x], cost[x][y]);
    }
  }
}

void update_labels() {
  type delta = inf;
  rep(y, n) {
    if (!T[y]) {
      delta = min(delta, slack[y]);
    }
  }
  rep(x, n) {
    if (S[x]) {
      lx[x] -= delta;
    }
  }
  rep(y, n) {
    if (T[y]) {
      ly[y] += delta;
    }
  }
  rep(y, n) {
    if (!T[y]) {
      slack[y] -= delta;
    }
  }
}

void add_to_tree(int x, int prex) {
  S[x] = true;
  pre[x] = prex;
  rep(y, n) {
    if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
      slack[y] = lx[x] + ly[y] - cost[x][y];
      slackx[y] = x;
    }
  }
}

void augment(int match) {
  if (match == 0) {
    return;
  }
  int fr = 0, bk = 0, root;
  fill(S, S+n, false);
  fill(T, T+n, false);
  fill(pre, pre+n, -1);
  rep(x, n) {
    if (xy[x] == -1) {
      S[x] = true;
      Q[bk ++] = root = x;
      pre[x] = -2;
      break;
    }
  }
  rep(y, n) {
    slack[y] = lx[root] + ly[y] - cost[root][y];
    slackx[y] = root;
  }
  try {
    while (true) {
      while (fr < bk) {
        int x = Q[fr ++];
        rep(y, n) {
          if (lx[x]+ly[y] == cost[x][y] && !T[y]) {
            if (yx[y] == -1) {
              throw mp(x, y);
            }
            T[y] = true;
            Q[bk ++] = yx[y];
            add_to_tree(yx[y], x);
          }
        }
      }
      update_labels();
      fr = bk = 0;
      rep(y, n) {
        if (!T[y] && slack[y] == 0) {
          if (yx[y] == -1) {
            throw mp(slackx[y], y);
          } else {
            T[y] = true;
            if (!S[yx[y]]) {
              Q[fr ++] = yx[y];
              add_to_tree(yx[y], slackx[y]);
            }
          }
        }
      }
    }
  } catch (pair <int, int> e) {
    for (int cx = e.x, cy = e.y, ty; cx != -2; cx = pre[cx], cy = ty) {
      ty = xy[cx];
      yx[cy] = cx;
      xy[cx] = cy;
    }
    augment(match-1);
  }
}

type hungarian() {
  type ret = 0;
  if (n == 0) {
    return ret;
  }
  init();
  augment(n);
  rep(x, n) {
    ret += cost[x][xy[x]];
  }
  return ret;
}

int dp[105][105];
vector <vector <int> > A, B;
vector <int> cntA, cntB;

int solve(int a, int b) {
  int &ret = dp[a][b];
  if (ret == -1) {
    rep(i, sz(A[a])) {
      rep(j, sz(B[b])) {
        solve(A[a][i], B[b][j]);
      }
    }
    n = max(sz(A[a]), sz(B[b]));
    rep(i, sz(A[a])) {
      rep(j, sz(B[b])) {
        cost[i][j] = -solve(A[a][i], B[b][j]);
      }
    }
    if (sz(A[a]) > sz(B[b])) {
      rep(i, sz(A[a])) {
        repi(j, sz(B[b]), sz(A[a])) {
          cost[i][j] = -cntA[A[a][i]];
        }
      }
    } else {
      repi(i, sz(A[a]), sz(B[b])) {
        rep(j, sz(B[b])) {
          cost[i][j] = -cntB[B[b][j]];
        }
      }
    }
    ret = -hungarian();
  }
  return ret;
}

int dfs(int u, vector <vector <int> > &adj, vector <int> &cnt) {
  int ret = 1;
  rep(i, sz(adj[u])) {
    ret += dfs(adj[u][i], adj, cnt);
  }
  cnt[u] = ret;
  return ret;
}

int main () {
  int tst, cas = 0;
  scanf("%d", &tst);
  while (tst --) {
    int m, n;
    scanf("%d", &m);
    A.clear(), A.resize(m+1);
    cntA.clear(), cntA.resize(m+1);
    rep(i, m) {
      int x;
      scanf("%d", &x);
      A[x].push_back(i+1);
    }
    dfs(0, A, cntA);
    scanf("%d", &n);
    B.clear(), B.resize(n+1);
    cntB.clear(), cntB.resize(n+1);
    rep(i, n) {
      int x;
      scanf("%d", &x);
      B[x].push_back(i+1);
    }
    dfs(0, B, cntB);
    mem(dp, -1);
    printf("Case %d: %d\n", ++ cas, solve(0, 0));
  }
  return 0;
}
