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
  int n;
  cin >> n;
  vt(int) p(n);
  repe(&e, p) {
    cin >> e;
  }
  vt(vt(int)) f(n, vt(int)(n)), g(n, vt(int)(n));
  rep(i, n) {
    f[i][i] = 1;
  }
  repi(l, 2, n+1) {
    rep(i, n-l+1) {
      int j = i+l-1;
      f[i][j] = g[i][j] = 1<<29;
      if (p[i] == p[j]) {
        f[i][j] = g[i+1][j-1]+1;
        g[i][j] = g[i+1][j-1];
      }
      repi(k, i, j) {
        f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]);
        g[i][j] = min(g[i][j], f[i][k]+g[k+1][j]);
        g[i][j] = min(g[i][j], g[i][k]+f[k+1][j]);
      }
    }
  }
  cout << f[0][n-1];
  return 0;
}
