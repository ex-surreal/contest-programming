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

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int n, p;
    cin >> n >> p;
    vt(int) a(n+1);
    rep(i, n) {
      cin >> a[i+1];
    }
    vt(vt(bool)) can(n+1, vt(bool)(n+1));
    vt(vt(int)) com(n+1, vt(int)(n+1));
    repi(i, 1, n+1) {
      int mx = 0, mn = n+1;
      repi(j, i, n+1) {
        mx = max(mx, a[j]);
        mn = min(mn, a[j]);
        can[i][j] = mx - mn == j-i;
        if (can[i][j] && mn != i) {
          com[i][j] = mn < i ? -1 : 1;
        }
      }
    }
    vt(int) f(n+1), g(n+1), h(n+1);
    repi(i, 1, n+1) {
      h[i] = f[i] = g[i] = -(1<<29);
      repi(j, 1, i+1) {
        if (can[j][i]) {
          if (!com[j][i]) {
            f[i] = max(f[j-1]+1, f[i]);
            h[i] = max(h[j-1]+1, h[i]);
            g[i] = max(g[j-1]+1, g[i]);
          } else if (com[j][i] < 0) {
            f[i] = max(g[j-1]+1, f[i]);
          } else {
            g[i] = max(h[j-1]+1, g[i]);
          }
        }
      }
    }
    cout << "Case #" << ++ cas << ": " << f[n] << "\n";
  }
  return 0;
}
