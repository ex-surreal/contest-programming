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
    int n;
    cin >> n;
    vt(int) w(n), dp[2];
    dp[0] = dp[1] = vt(int)(n+1);
    repe(&e, w) {
      cin >> e;
    }
    sort(all(w));
    for (int i = n-1; i >= 0; i --) {
      rep(j, n+1) {
        dp[i&1][j] = dp[!(i&1)][j+1];
        int x = (w[i]+49)/w[i]-1;
        if (x <= j) {
          dp[i&1][j] = max(dp[i&1][j], dp[!(i&1)][j-x]+1);
        }
      }
    }
    cout << "Case #" << ++ cas << ": " << dp[0][0] << "\n";
  }
  return 0;
}
