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

typedef pair <int, int> point;

vector <vector <point> > adj;

int dis(point a, point b) {
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double prim(vector <point> &p) {
  int n = sz(p);
  set <point> Q;
  vector <int> D(n, 1<<30), parent(n, -1);
  vector <bool> seen(n, false);
  D[0] = 0;
  Q.insert(mp(D[0], 0));
  while (!Q.empty()) {
    int u = Q.begin()->y;
    seen[u] = true;
    Q.erase(Q.begin());
    rep(v, n) {
      if (seen[v] || u == v) {
        continue;
      }
      int w = dis(p[u], p[v]);
      if (D[v] > w) {
        Q.erase(mp(D[v], v));
        D[v] = w;
        parent[v] = u;
        Q.insert(mp(D[v], v));
      }
    }
  }
  adj.clear(), adj.resize(n);
  rep(i, n) {
    if (parent[i] == -1) {
      continue;
    }
    adj[i].push_back(mp(parent[i], D[i]));
    adj[parent[i]].push_back(mp(i, D[i]));
  }
  double ret = 0;
  repe(e, D) {
    ret += sqrt(e);
  }
  return ret;
}

void dfs(int u, int w, vector <int> &D) {
  repe(e, adj[u]) {
    int v = e.x, c = e.y;
    if (v != w) {
      D[v] = max(D[u], c);
      dfs(v, u, D);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  cout.precision(2);
  cout.setf(ios::fixed);
  int tst;
  cin >> tst;
  while (tst --) {
    int n;
    cin >> n;
    vector <point> p(n);
    vector <int> f(n);
    rep(i, sz(p)) {
      cin >> p[i].x >> p[i].y >> f[i];
    }
    double mst = prim(p);
    double ans = 0;
    rep(i, n) {
      vector <int> D(n);
      dfs(i, -1, D);
      rep(j, n) {
        if (i == j) {
          continue;
        }
        ans = max(ans, (f[i]+f[j])/(mst-sqrt(D[j])));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
