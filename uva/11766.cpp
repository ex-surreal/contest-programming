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

int dp[1005];
int cnt[1005][1005];

int main () {
  int cas = 0, n;
  while (~scanf("%d", &n) && n) {
    rep(i, n+1) {
      rep(j, n+1) {
        cnt[i][j] = 0;
      }
    }
    rep(i, n) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (a+b >= n) {
        continue;
      }
      cnt[n-b][a] ++;
    }
    int t = 0;
    dp[0] = 0;
    rep(i, n+1) {
      dp[i+1] = dp[i];
      rep(j, n+1) {
        if (!cnt[i][j]) {
          continue;
        }
        dp[i+1] = max(dp[i+1], dp[j+1]+min(cnt[i][j], i-j));
      }
      t = max(dp[i+1], t);
    }
    printf("Case %d: %d\n", ++cas, n-t);
  }
  return 0;
}
