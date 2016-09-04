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

int pwr(int b, int e, int mod) {
  if (e == 0) {
    return 1;
  }
  int t = pwr(b, e/2, mod);
  t = 1ll*t*t % mod;
  return (e&1) ? 1ll*t*b % mod : t;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst, mod = 1e8+7;
  cin >> tst;
  while (tst --) {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > dp(20, vector <int> (n/2+1));
    rep(i, n/2+1) {
      dp[0][i] = 1;
    }
    repi(i, 1, 20) {
      vector <int> sum(n/2+1, 0);
      sum[0] = dp[i-1][0];
      repi(j, 1, n/2+1) {
        sum[j] = (dp[i-1][j] + sum[j-1]) % mod;
      }
      dp[i][0] = 0;
      repi(j, 1, n/2+1) {
        if (j&1) {
          dp[i][j] = (dp[i][j-1] + 2ll*sum[j/2]) % mod;
        } else {
          dp[i][j] = (dp[i][j-1] + dp[i-1][j/2] + 2ll*sum[j/2-1]);
        }
      }
    }
    int ans = pwr(n-n/2, m, mod);
    repi(i, 1, min(20, m)) {
      ans = (ans + 1ll*pwr(n-n/2, m-i, mod)*(m-i) % mod * dp[i][n/2]) % mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
