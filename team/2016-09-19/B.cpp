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

const int inf = 1<<29;
vector <int> last, pre, cst, to, ex;

void init(int n) {
  last = vector <int> (n, -1);
  pre.clear();
  cst.clear();
  to.clear();
  ex.clear();
}

void add(int u, int v, int c, int e) {
  to.push_back(v);
  cst.push_back(c);
  pre.push_back(last[u]);
  ex.push_back(e);
  last[u] = sz(pre)-1;
}

void add_edge(int u, int v, int c, int e) {
  add(u, v, c, e);
  add(v, u, c, e);
}

void djk(int s, int t) {
  vector <int> D(2*sz(last), inf), parent(2*sz(last), -1);
  set <pair <int, int> > Q;
  s *= 2;
  t *= 2;
  D[s] = 0;
  Q.insert(mp(D[s], s));
  while (!Q.empty()) {
    int u = Q.begin()->y, x = u/2;
    Q.erase(Q.begin());
    for (int e = last[x]; e != -1; e = pre[e]) {
      if (u%2 && ex[e]) {
        continue;
      }
      int v = ex[e] + u%2 + 2*to[e], w = cst[e];
      if (D[v] > D[u] + w) {
        Q.erase(mp(D[v], v));
        D[v] = D[u] + w;
        parent[v] = u;
        Q.insert(mp(D[v], v));
      }
    }
  }
  if (D[t] > D[t+1]) {
    t ++;
  }
  int e = -1, d = D[t];
  while (t != s) {
    cout << t/2+1 << " ";
    if (t%2 && parent[t]%2 == 0) {
      e = t/2+1;
    }
    t = parent[t];
  }
  cout << t/2+1 << "\n";
  if (e == -1) {
    cout << "Ticket Not Used\n";
  } else {
    cout << e << "\n";
  }
  cout << d << "\n";
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, t, s;
  string nl = "";
  while (cin >> n >> t >> s) {
    init(n);
    int m;
    cin >> m;
    rep(i, m) {
      int u, v, c;
      cin >> u >> v >> c;
      add_edge(u-1, v-1, c, 0);
    }
    int k;
    cin >> k;
    rep(i, k) {
      int u, v, c;
      cin >> u >> v >> c;
      add_edge(u-1, v-1, c, 1);
    }
    cout << nl;
    djk(s-1, t-1);
    nl = "\n";
  }
  return 0;
}
