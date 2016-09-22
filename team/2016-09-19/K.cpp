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
  int tst;
  cin >> tst;
  while (tst --) {
    int n;
    cin >> n;
    vector <int> w(n), d(n), a(n*n);
    rep(i, n) {
      cin >> w[i] >> d[i];
    }
    rep(i, n*n) {
      cin >> a[i];
    }
    string sp = "";
    rep(i, n) {
      int c = n, s = n*(n+1)/2, t = s+1, need = 0;
      int p = accumulate(a.begin()+i*n, a.begin()+i*n+n, 0)+w[i];
      bool ok = true;
      rep(j, n) {
        if (w[j] > p) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      init(n*(n+1)/2+2);
      rep(y, n) {
        if (y == i) {
          continue;
        }
        add_edge(s, y, p-w[y]);
        rep(x, y) {
          if (x == i) {
            continue;
          }
          add_edge(x, c, inf);
          add_edge(y, c, inf);
          add_edge(c ++, t, a[x*n+y]);
          need += a[x*n+y];
        }
      }
      if (mf(s, t) == need) {
        cout << sp << i+1;
        sp = " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
