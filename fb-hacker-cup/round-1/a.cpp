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
    int n, m;
    cin >> n >> m;
    vt(vt(int)) c(n, vt(int)(m+1)), dp(2, vt(int)(n+1));
    rep(i, n) {
      repi(j, 1, m+1) {
        cin >> c[i][j];
      }
      sort(all(c[i]));
      rep(j, m) {
        c[i][j+1] += c[i][j];
      }
    }
    reverse(all(c));
    rep(i, n) {
      rep(j, n+1) {
        dp[i&1][j] = INT_MAX/3;
        repi(k, !j, min(m, n-j+1)+1) {
          dp[i&1][j] = min(dp[i&1][j], k*k+c[i][k] + dp[!(i&1)][j+k-1]);
        }
      }
    }
    cout << "Case #" << ++ cas << ": " << dp[!(n&1)][0] << "\n";
  }
  return 0;
}
