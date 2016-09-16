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

using namespace std;

const int inf = (1 << 30);
vector <int> L, pre, to, ptr, cap, flow, level, parent;

void init(int n) {
    parent = level = L = vector <int> (n, -1);
    pre.clear();
    to.clear();
    ptr.clear();
    cap.clear();
    flow.clear();
}

void add(int u, int v, int c = 1) {
    to.push_back(v);
    pre.push_back(L[u]);
    cap.push_back(c);
    flow.push_back(0);
    L[u] = to.size()-1;
}

void add_edge(int u, int v, int c = 1) {
    add(u, v, c);
    add(v, u, 0);
}

bool bfs(int s, int t) {
    int fr = 0, bk = 0;
    level = vector <int> (L.size(), -1);
    level[s] = 0;
    parent[s] = -1;
    vector <int> Q(L.size());
    Q[bk++] = s;
    while (fr < bk) {
        int u = Q[fr++];
        for (int e = L[u]; e != -1; e = pre[e]) {
            if (flow[e] < cap[e]) {
                int v = to[e];
                if (level[v] == -1) {
                    level[v] = level[u] + 1;
                    parent[v] = e;
                    Q[bk++] = v;
                }

            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int f, int t) {
    if (u == t || f == 0) {
        return f;
    }
    for (int & e = ptr[u]; e != -1; e = pre[e]) {
        int v = to[e];
        if (flow[e] < cap[e] && level[v] == level[u] + 1) {
            int pushed = dfs(v, min(f, cap[e] - flow[e]), t);
            if (pushed > 0) {
                flow[e] += pushed;
                flow[e ^ 1] -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int mf(int s, int t) {
    int ret = 0;
    while (bfs(s, t)) {
        ptr = L;
        while (int f = dfs(s, inf, t)) {
            ret += f;
        }
    }
    return ret;
}

bool augment(int s, int t) {
  if (!bfs(s, t)) {
    return false;
  }
  while (parent[t] != -1) {
    flow[parent[t]] ++;
    flow[parent[t]^1] --;
    t = to[parent[t]^1];
  }
  return true;
}

int main () {
  int tst, cas = 0;
  scanf("%d", &tst);
  while (tst --) {
    int m, n;
    scanf("%d%d", &m, &n);
    vector <int> r(m), c(n);
    rep(i, m) {
      scanf("%d", &r[i]);
    }
    rep(i, n) {
      scanf("%d", &c[i]);
    }
    init(m+n+2);
    int s = m+n, t = s+1;
    vector <int> S(m), T(n);
    rep(i, m) {
      S[i] = sz(pre);
      add_edge(s, i, r[i]);
    }
    rep(j, n) {
      T[j] = sz(pre);
      add_edge(j+m, t, c[j]);
    }
    vector <vector <int> > ans(m, vector <int> (n, 0));
    rep(i, m) {
      rep(j, n) {
        ans[i][j] = sz(pre);
        add_edge(i, j+m, 1);
      }
    }
    printf("Case %d:", ++ cas);
    int sa = accumulate(all(r), 0);
    int sb = accumulate(all(c), 0);
    if (sa != sb || mf(s, t) != sa) {
      printf(" impossible\n");
    } else {
      printf("\n");
      vector <string> d(m, string(n, '0'));
      rep(i, m) {
        rep(j, n) {
          if (flow[ans[i][j]] == 1) {
            cap[ans[i][j]] = 0;
            flow[ans[i][j]] --;
            flow[1^ans[i][j]] ++;
            flow[S[i]] --;
            flow[1^S[i]] ++;
            flow[T[j]] --;
            flow[1^T[j]] ++;
            if (!augment(s, t)) {
              cap[ans[i][j]] = 1;
              flow[ans[i][j]] ++;
              flow[1^ans[i][j]] --;
              flow[S[i]] ++;
              flow[1^S[i]] --;
              flow[T[j]] ++;
              flow[1^T[j]] --;
              d[i][j] = '1';
            }
          } else {
            cap[ans[i][j]] = 0;
          }
        }
      }
      rep(i, m) {
        printf("%s\n", d[i].c_str());
      }
    }
  }
  return 0;
}
