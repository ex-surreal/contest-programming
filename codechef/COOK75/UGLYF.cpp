#include <iostream>
#include <climits>
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
  int tst;
  cin >> tst;
  while (tst --) {
    string p, q;
    cin >> p >> q;
    vt(int) x(26, -1), y(26, 200000);
    vt(int) w(26, -1), z(26, 200000);
    rep(i, sz(p)) {
      int c = p[i]-'A';
      if (abs(x[c]-y[c]) > abs(i-(sz(p)-i-1))) {
        x[c] = i;
        y[c] = sz(p)-i-1;
      }
    }
    rep(i, sz(q)) {
      int c = q[i]-'A';
      if (abs(w[c]-z[c]) > abs(i-(sz(q)-i-1))) {
        w[c] = i;
        z[c] = sz(q)-i-1;
      }
    }
    int ans = INT_MAX;
    rep(c, 26) {
      ans = min(ans, abs(x[c]-w[c])+abs(x[c]-z[c])+abs(y[c]-w[c])+abs(y[c]-z[c]));
    }
    cout << ans << "\n";
  }
  return 0;
}
