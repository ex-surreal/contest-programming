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

vector <int> parent, rnk;

void init(int n) {
  parent = rnk = vector <int> (n);
  rep(i, n) {
    parent[i] = i;
  }
}

int root(int u) {
  return parent[u] == u ? u : root(parent[u]);
}

bool join(int i, int j) {
  if ((i = root(i)) == (j = root(j))) {
    return false;
  }
  if (rnk[i] > rnk[j]) {
    parent[j] = i;
  } else {
    parent[i] = j;
    rnk[j] += rnk[i] == rnk[j];
  }
  return true;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector <int> u(m), v(m);
  rep(i, m) {
    cin >> u[i] >> v[i];
    u[i] --, v[i] --;
  }
  init(n);
  int s, t, ds, dt;
  cin >> s >> t >> ds >> dt;
  s --, t --;
  vector <int> adj[2], X, Y;
  rep(i, m) {
    if (u[i] == s || u[i] == t || v[i] == s || v[i] == t) {
      if (u[i] == s) {
        adj[0].push_back(v[i]);
      }
      if (v[i] == s) {
        adj[0].push_back(u[i]);
      }
      if (u[i] == t) {
        adj[1].push_back(v[i]);
      }
      if (v[i] == t) {
        adj[1].push_back(u[i]);
      }
      continue;
    }
    if (join(u[i], v[i])) {
      X.push_back(u[i]);
      Y.push_back(v[i]);
    }
  }
  vector <int> cnt(n);
  cnt[s] = 1;
  cnt[t] = 2;
  repe(v, adj[0]) {
    cnt[root(v)] |= 1;
  }
  repe(v, adj[1]) {
    cnt[root(v)] |= 2;
  }
  vector <int> p, q, a, b;
  rep(i, 2) {
    repe(v, adj[i]) {
      if (cnt[root(v)] == 3) {
        p.push_back(i == 0 ? s : t);
        q.push_back(v);
      } else {
        a.push_back(i == 0 ? s : t);
        b.push_back(v);
      }
    }
  }
  rep(i, sz(a)) {
    if (join(a[i], b[i])) {
      X.push_back(a[i]);
      Y.push_back(b[i]);
      ds -= a[i] == s;
      dt -= a[i] == t;
    }
  }
  if (ds <= 0 || dt <= 0) {
    cout << "No";
    return 0;
  }
  bool st = false;
  rep(i, sz(p)) {
    if ((p[i] == s && q[i] == t) || (p[i] == t && q[i] == s)) {
      st = true;
      continue;
    }
    if (p[i] == s && ds > 0 && join(s, q[i])) {
      X.push_back(s);
      Y.push_back(q[i]);
      ds --;
    }
    if (p[i] == t && dt > 0 && join(t, q[i])) {
      X.push_back(t);
      Y.push_back(q[i]);
      dt --;
    }
  }
  if (st && ds > 0 && dt > 0 && join(s, t)) {
    ds --, dt --;
    X.push_back(s);
    Y.push_back(t);
  }
  if (sz(X) != n-1) {
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  rep(i, sz(X)) {
    cout << X[i]+1 << " " << Y[i]+1 << "\n";
  }
  return 0;
}
