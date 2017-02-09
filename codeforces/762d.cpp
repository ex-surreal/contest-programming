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
  vt(vt(int)) a(3, vt(int)(n));
  vt(vt(ll)) dp(2, vt(ll)(3));
  repe(&e, a) {
    repe(&c, e) {
      cin >> c;
    }
  }
  vt(ll) c(n);
  rep(i, n) {
    rep(j, 3) {
      c[i] += a[j][i];
    }
  }
  repi(i, 1, n) {
    c[i] += c[i-1];
  }
  dp[n&1][0] = dp[n&1][1] = LLONG_MIN/3;
  int l = n;
  ll m = c.back();
  for (int i = n-1; i >= 0; i --) {
    ll t = max(dp[1^(i&1)][0], dp[1^(i&1)][2]) + c[i];
    dp[i&1][0] = max({
      dp[(i&1)^1][0] + a[0][i],
      dp[(i&1)^1][1] + a[0][i]+a[1][i],
      dp[(i&1)^1][2] + a[0][i]+a[1][i]+a[2][i]
    });
    dp[i&1][1] = max({
      dp[(i&1)^1][0] + a[0][i]+a[1][i],
      dp[(i&1)^1][1] + a[1][i],
      dp[(i&1)^1][2] + a[1][i]+a[2][i]
    });
    dp[i&1][2] = max({
      dp[(i&1)^1][2] + a[2][i],
      dp[(i&1)^1][1] + a[1][i]+a[2][i],
      dp[(i&1)^1][0] + a[0][i]+a[1][i]+a[2][i]
    });
    if (i < n-1) {
      dp[i&1][0] = max({
        dp[i&1][0],
        m - (!i ? 0 : c[i-1])
      });
      dp[i&1][2] = max({
        dp[i&1][2],
        m - (!i ? 0 : c[i-1])
      });
      if (t > m) {
        l = i+1, m = t;
      }
    }
  }
  cout << dp[0][0];
  return 0;
}
