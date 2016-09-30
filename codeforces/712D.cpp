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

int dp[2][500005];
int mod = 1e9+7, mid = 250000;

int main () {
  std::ios_base::sync_with_stdio(false);
  int a, b, k, t;
  cin >> a >> b >> k >> t;
  int now = 0, pre = 1;
  dp[now][a-b+mid] = 1;
  int lim = a+b+2*k*t;
  rep(i, 2*t) {
    repi(j, -lim, lim+1) {
      dp[now][mid+j] += dp[now][mid+j-1];
      if (dp[now][mid+j] >= mod) {
        dp[now][mid+j] -= mod;
      }
    }
    swap(now, pre);
    repi(j, -lim, lim+1) {
      dp[now][j+mid] = dp[pre][min(j+k, lim)+mid] - dp[pre][max(j-k, -lim)-1+mid];
      if (dp[now][j+mid] < 0) {
        dp[now][j+mid] += mod;
      }
    }
  }
  int ans = 0;
  repi(j, 1, lim+1) {
    ans += dp[now][j+mid];
    if (ans >= mod) {
      ans -= mod;
    }
  }
  cout << ans;
  return 0;
}
