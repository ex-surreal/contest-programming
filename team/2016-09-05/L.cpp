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

int C[1<<10][1<<10];

int main () {
  std::ios_base::sync_with_stdio(false);
  int mod = 10056;
  rep(i, 1<<10) {
    C[i][0] = 1;
    rep(j, i) {
      C[i][j+1] = (C[i-1][j+1]+C[i-1][j]) % mod;
    }
  }
  int dp[1<<10] = {1};
  repi(i, 1, 1<<10) {
    dp[i] = 0;
    repi(j, 1, i+1) {
      dp[i] = (dp[i]+C[i][j]*dp[i-j]) % mod;
    }
  }
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int n;
    cin >> n;
    cout << "Case " << ++ cas << ": " << dp[n] << "\n";
  }
  return 0;
}
