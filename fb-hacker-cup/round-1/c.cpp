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

int D[105][5000][3];

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst;
  cin >> tst;
  repi(cas, 1, tst+1) {
    int n, m, k;
    cin >> n >> m >> k;
    vt(vt(int)) c(n, vt(int)(n, INT_MAX/3));
    rep(i, n) {
      c[i][i] = 0;
    }
    rep(i, m) {
      int u, v, w;
      cin >> u >> v >> w;
      u --, v --;
      c[u][v] = min(c[u][v], w);
      c[v][u] = min(c[v][u], w);
    }
    rep(k, n) {
      rep(i, n) {
        rep(j, n) {
          c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
        }
      }
    }
    vt(int) s(k+1), t(k+1), f(k+2, INT_MAX/3), g(k+2, INT_MAX/3), h(k+2, INT_MAX/3), l(k+2, INT_MAX/3);
    repi(i, 1, k+1) {
      cin >> s[i] >> t[i];
      s[i] --, t[i] --;
    }
    f[k+1] = 0;
    for (int i = k; i >= 1; i --) {
      l[i] = min(l[i], c[s[i]][t[i]] + f[i+1]);
      g[i] = min(g[i], c[t[i-1]][t[i]] + f[i+1]);
      if (i+1 <= k) {
        h[i] = min(h[i], c[s[i+1]][t[i]] + g[i+1]);
        l[i] = min(l[i], c[s[i]][s[i+1]] + h[i]);
        g[i] = min(g[i], c[t[i-1]][s[i+1]] + h[i]);
      }
      f[i] = min(f[i], c[t[i-1]][s[i]] + l[i]);
    }
    cout << "Case #" << cas << ": " << (f[1] >= INT_MAX/3 ? -1 : f[1]) << "\n";
  }
  return 0;
}
