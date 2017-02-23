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

double f[1005][1005];
double g[1005][1005];

int main () {
  std::ios_base::sync_with_stdio(false);
  rep(i, 1005) {
    g[0][i] = 1;
  }
  repi(i, 1, 1005) {
    f[i][0] = 1;
    g[i][0] = 1;
  }
  int w, b;
  cin >> w >> b;
  repi(i, 1, w+1) {
    repi(j, 1, b+1) {
      f[i][j] = 1.0*i/(i+j) + j*(1-g[i][j-1])/(i+j);
      g[i][j] = 1.0*i/(i+j) + j*((
         (1-f[i-1][j-1])*i +
         (1-(j == 1 ? 0. : f[i][j-2]))*(j-1)
        ) / (i+j-1)
      ) / (i+j);
    }
  }
  cout.precision(10);
  cout.setf(ios::fixed);
  cout << f[w][b];
  return 0;
}
