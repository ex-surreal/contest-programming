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
  int n, c;
  cin >> n >> c;
  vt(int) s(n), p(n);
  repe(&e, p) {
    cin >> e;
  }
  repe(&e, s) {
    cin >> e;
  }
  vt(ll) dp[2] = {vt(ll)(n+1, 1ll<<60), vt(ll)(n+1, 1ll<<60)};
  int f = 0;
  dp[f][0] = 0;
  rep(i, n) {
    f ^= 1;
    dp[f][0] = dp[f^1][0] + p[i];
    repi(j, 1, i+2) {
      dp[f][j] = min(dp[f^1][j]+p[i]+1ll*j*c, dp[f^1][j-1]+s[i]);
    }
  }
  cout << *min_element(all(dp[f]));
  return 0;
}
