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
vector <int> L, pre, to, ptr, cap, flow, level;

void init(int n) {
  level = L = vector <int> (n, -1);
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
  vector <int> Q(L.size());
  Q[bk++] = s;
  while (fr < bk) {
    int u = Q[fr++];
    for (int e = L[u]; e != -1; e = pre[e]) {
      if (flow[e] < cap[e]) {
        int v = to[e];
        if (level[v] == -1) {
          level[v] = level[u] + 1;
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


int main () {
  std::ios_base::sync_with_stdio(false);
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int m, n;
    cin >> m >> n;
    vector <string> B(m);
    rep(i, m) {
      cin >> B[i];
    }
    vector <vector <int> > row(m, vector <int> (n)), col(m, vector <int> (n));
    int l = 0, r = 0;
    rep(i, m) {
      rep(j, n) {
        if (i > 0 && B[i-1][j] != 'W') {
          col[i][j] = col[i-1][j];
        } else if (B[i][j] != 'W'){
          col[i][j] = r ++;
        }
        if (j > 0 && B[i][j-1] != 'W') {
          row[i][j] = row[i][j-1];
        } else if (B[i][j] != 'W') {
          row[i][j] = l ++;
        }
      }
    }
    int s = l+r, t = s+1;
    init(t+1);
    rep(i, l) {
      add_edge(s, i, 1);
    }
    rep(i, r) {
      add_edge(i+l, t, 1);
    }
    rep(i, m) {
      rep(j, n) {
        if (B[i][j] == '.') {
          add_edge(row[i][j], col[i][j]+l, 1);
        }
      }
    }
    cout << "Case " << ++ cas << ": " << mf(s, t) << "\n";
    vector <int> xy(l, -1);
    rep(i, l) {
      for (int e = L[i]; e != -1; e = pre[e]) {
        if (flow[e] == 1) {
          xy[i] = to[e]-l;
        }
      }
    }
    rep(i, m) {
      rep(j, n) {
        if (B[i][j] == '.') {
          if (xy[row[i][j]] == col[i][j]) {
            B[i][j] = 'T';
          }
        }
      }
      cout << B[i] << "\n";
    }
  }
  return 0;
}
