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

vector <int> L, pre, to, cst, var;

void init(int n) {
  L = vector <int> (n, -1);
  pre.clear();
  to.clear();
  cst.clear();
  var.clear();
}

void add(int u, int v, int c = 1) {
  to.push_back(v);
  pre.push_back(L[u]);
  cst.push_back(c);
  var.push_back(c == 0);
  L[u] = to.size()-1;
}

void add_edge(int u, int v, int c = 1) {
  add(u, v, c);
  add(v, u, c);
}

void djk(int s, int t, int l) {
  vector <ll> D(sz(L), 1ll<<60);
  set <pair <ll, int> > Q;
  D[s] = 0;
  Q.insert(mp(D[s], s));
  while (!Q.empty()) {
    int u = Q.begin()->y;
    Q.erase(Q.begin());
    for (int e = L[u]; e != -1; e = pre[e]) {
      int v = to[e], w = cst[e];
      if (w == 0) {
        continue;
      }
      if (D[u]+w < D[v]) {
        D[v] = D[u] + w;
        Q.insert(mp(D[v], v));
      }
    }
  }
  if (D[t] < l) {
    throw string("NO");
  }
}

void djk2(int s, int t, int l) {
  vector <ll> D(sz(L), 1ll<<60);
  vector <int> parent(sz(L), -1);
  set <pair <ll, int> > Q;
  D[s] = 0;
  Q.insert(mp(D[s], s));
  while (!Q.empty()) {
    int u = Q.begin()->y;
    Q.erase(Q.begin());
    for (int e = L[u]; e != -1; e = pre[e]) {
      if (cst[e] == 0) {
        cst[e] = cst[e^1] = 1;
      }
      int v = to[e], w = cst[e];
      if (D[u]+w < D[v]) {
        D[v] = D[u] + w;
        parent[v] = e;
        Q.insert(mp(D[v], v));
      }
    }
  }
  if (D[t] > l) {
    throw string("NO");
  }
  if (D[t] == l) {
    return;
  }
  int r = l - D[t];
  vector <bool> flag(sz(pre), false);
  for (int g = t; g != s; g = to[parent[g]^1]) {
    flag[parent[g]] = flag[parent[g]^1] = true;
  }
  for (int g = t; g != s; g = to[parent[g]^1]) {
    if (var[parent[g]]) {
      cst[parent[g]] += r;
      cst[parent[g]^1] += r;
      break;
    }
  }
  rep(i, sz(pre)) {
    if (!flag[i] && var[i]) {
      cst[i] = l+1;
    }
  }
  djk2(s, t, l);
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, l, s, t;
  cin >> n >> m >> l >> s >> t;
  init(n);
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    add_edge(u, v, w);
  }
  try {
    djk(s, t, l);
    djk2(s, t, l);
    cout << "YES\n";
    for (int i = 0; i < sz(pre); i += 2) {
      cout << to[i^1] << " " << to[i] << " " << cst[i] << "\n";
    }
  } catch (string p) {
    cout << p << "\n";
  }
  return 0;
}
