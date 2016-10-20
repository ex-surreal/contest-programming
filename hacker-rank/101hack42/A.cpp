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
  int q;
  cin >> q;
  while (q --) {
    int n;
    cin >> n;
    vt(int) x(n), y(n);
    int mx = -1000000, nx = 1000000;
    int my = -1000000, ny = 1000000;
    rep(i, n) {
      cin >> x[i] >> y[i];
      mx = max(x[i], mx);
      nx = min(x[i], nx);
      my = max(y[i], my);
      ny = min(y[i], ny);
    }
    string ans = "YES";
    rep(i, n) {
      if ((x[i] == mx || x[i] == nx) && ny <= y[i] && y[i] <= my) {
        continue;
      }
      if ((y[i] == my || y[i] == ny) && nx <= x[i] && x[i] <= mx) {
        continue;
      }
      ans = "NO";
    }
    cout << ans << endl;
  }
  return 0;
}
