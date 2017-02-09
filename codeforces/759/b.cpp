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
  vt(int) t(n), p(n), q(n), dp(n+1);
  repe(&e, t) {
    cin >> e;
  }
  for (int i = n-1, j = n-1, k = n-1; i >= 0; i --) {
    auto func = [&](int x, int &j) {
      while (j > 0 && t[j-1]+x > t[i]) {
        j --;
      }
      return j;
    };
    p[i] = func(90, j);
    q[i] = func(1440, k);
  }
  rep(i, n) {
    dp[i+1] = min({
      dp[i] + 20,
      dp[p[i]] + 50,
      dp[q[i]] + 120
    });
  }
  rep(i, n) {
    cout << dp[i+1]-dp[i] << "\n";
  }
  return 0;
}
