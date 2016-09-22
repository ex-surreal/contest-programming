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

typedef long long ll;

int inf;
vector <int> last, pre, cst, to;

void init(int n) {
  last = vector <int> (n, -1);
  pre.clear();
  cst.clear();
  to.clear();
}

void add(int u, int v, int c) {
  to.push_back(v);
  cst.push_back(c);
  pre.push_back(last[u]);
  last[u] = sz(pre)-1;
}

void add_edge(int u, int v, int c) {
  add(u, v, c);
  add(v, u, c);
}

vector <vector <bool> > used;

ll djk(int s, bool update = true) {
  vector <ll> D(sz(last), inf);
  set <pair <ll, int> > Q;
  vector <int> edge(sz(last), -1);
  D[s] = 0;
  Q.insert(mp(D[s], s));
  while (!Q.empty()) {
    int u = Q.begin()->y;
    Q.erase(Q.begin());
    for (int e = last[u]; e != -1; e = pre[e]) {
      int v = to[e], w = cst[e];
      if (D[v] > D[u] + w) {
        edge[v] = e;
        Q.erase(mp(D[v], v));
        D[v] = D[u] + w;
        Q.insert(mp(D[v], v));
      }
    }
  }
  if (update) {
    repe(e, edge) {
      if (e != -1) {
        used[s][e/2] = true;
      }
    }
  }
  return accumulate(all(D), 0ll);
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m >> inf) {
    init(n);
    rep(i, m) {
      int u, v, c;
      cin >> u >> v >> c;
      add_edge(u-1, v-1, c);
    }
    used.clear(), used.resize(n, vector <bool> (m));
    vector <ll> sum(n);
    ll x = 0;
    rep(i, n) {
      sum[i] = djk(i);
      x += sum[i];
    }
    ll y = x;
    rep(e, m) {
      ll t = 0;
      rep(u, n) {
        if (used[u][e]) {
          int d = cst[e*2];
          cst[e*2] = cst[e*2+1] = inf;
          t += djk(u, false);
          cst[e*2] = cst[e*2+1] = d;
        } else {
          t += sum[u];
        }
      }
      y = max(y, t);
    }
    cout << x << " " << y << "\n";
  }
  return 0;
}
