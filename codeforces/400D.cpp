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
#define mt make_tuple
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))
#define vt(x) vector < x >
#define px(x) pair < x, x >
#define pxy(x, y) pair < x, y >

typedef long long ll;

vt(vt(int)) adj;
vt(int) seen;

void dfs(int u, int c) {
  seen[u] = c;
  repe(v, adj[u]) {
    if (seen[v] == -1) {
      dfs(v, c);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  adj.resize(n);
  vt(int) type, c(k);
  rep(i, k) {
    cin >> c[i];
    rep(j, c[i]) {
      type.push_back(i);
    }
  }
  vt(vt(int)) D(k, vt(int)(k, 1<<29));
  rep(i, k) {
    D[i][i] = 0;
  }
  rep(i, m) {
    int u, v, x;
    cin >> u >> v >> x;
    u --, v --;
    if (x == 0) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    u = type[u], v = type[v];
    D[u][v] = D[v][u] = min(D[u][v], x);
  }
  seen.resize(n, -1);
  rep(i, n) {
    if (seen[i] == -1) {
      dfs(i, i);
    }
  }
  try {
    vector <set <int> > st(k);
    rep(i, n) {
      st[type[i]].insert(seen[i]);
    }
    repe(e, st) {
      if (sz(e) != 1) {
        throw string("No");
      }
    }
    rep(p, k) {
      rep(i, k) {
        rep(j, k) {
          D[i][j] = min(D[i][j], D[i][p]+D[p][j]);
        }
      }
    }
    rep(i, k) {
      rep(j, k) {
        if (D[i][j] == (1<<29)) {
          D[i][j] = -1;
        }
      }
    }
    cout << "Yes\n";
    repe(e, D) {
      repe(c, e) {
        cout << c << " ";
      } cout << "\n";
    }
  } catch (string ans) {
    cout << ans;
  }
  return 0;
}
