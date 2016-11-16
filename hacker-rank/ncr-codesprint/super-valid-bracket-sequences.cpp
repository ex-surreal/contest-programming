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

const int lim = 50;
int dp[lim+5][lim+5];

int main () {
  std::ios_base::sync_with_stdio(false);
  dp[2][1] = dp[0][0] = 1;
  int mod = 1e9+7;
  for (int i = 4; i <= lim; i += 2) {
    repi(j, 1, i+1) {
      dp[i][j] = dp[i-2][j];
      if (j > 1) {
        dp[i][j] += dp[i-2][j-2];
        if (dp[i][j] >= mod) {
          dp[i][j] -= mod;
        }
      }
      for (int x = 4; x < i; x += 2) {
        rep(l, j) {
          dp[i][j] += 1ll*dp[x-2][l]*dp[i-x][j-l-1] % mod;
          if (dp[i][j] >= mod) {
            dp[i][j] -= mod;
          }
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q --) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    repi(i, k, n) {
      ans += dp[n][i];
      if (ans >= mod) {
        ans -= mod;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
