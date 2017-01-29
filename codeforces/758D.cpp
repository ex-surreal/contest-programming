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
  string s;
  cin >> n >> s;
  vt(ll) dp(sz(s)+1);
  rep(i, sz(s)) {
    dp[i+1] = LLONG_MAX/3;
    for (int j = i, d = 0, b = 1; j >= 0 && i-j+1 <= 9 && d + 1ll*b*(s[j]-'0') < n; j --, b *= 10) {
      d = d + b*(s[j]-'0');
      if ((s[j] == '0' && j < i) || 1.0*dp[j]*n + d > 1e18) {
        continue;
      }
      dp[i+1] = min(dp[i+1], dp[j]*n+d);
    }
  }
  cout << dp.back();
  return 0;
}
