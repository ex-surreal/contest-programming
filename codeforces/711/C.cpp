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

long long dp[105][105][105];

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> c(n);
  repe(&e, c) {
    cin >> e;
  }
  vector <vector <int> > p(n, vector <int> (m));
  repe(&r, p) {
    repe(&c, r) {
      cin >> c;
    }
  }
  rep(i, n+1) {
    rep(j, k+1) {
      rep(l, m+1) {
        dp[i][j][l] = 1ll<<60;
      }
    }
  }
  repi(i, 0, m+1) {
    dp[0][0][i] = 0;
  }
  repi(i, 1, n+1) {
    repi(j, 1, k+1) {
      long long mn = 1ll<<60, mc = -1;
      long long nn = 1ll<<60, nc = -1;
      repi(l, 0, m+1) {
        if (mn > dp[i-1][j-1][l]) {
          nc = mc, nn = mn;
          mc = l, mn = dp[i-1][j-1][l];
        } else if (nn > dp[i-1][j-1][l]) {
          nc = l, nn = dp[i-1][j-1][l];
        }
      }
      repi(l, 1, m+1) {
        if (c[i-1] == l) {
          dp[i][j][l] = min(dp[i][j][l], dp[i-1][j][l]);
          if (mc != l) {
            dp[i][j][l] = min(dp[i][j][l], mn);
          }
          if (nc != l) {
            dp[i][j][l] = min(dp[i][j][l], nn);
          }
        } else if (c[i-1] == 0) {
          dp[i][j][l] = min(dp[i][j][l], dp[i-1][j][l]+p[i-1][l-1]);
          if (mc != l) {
            dp[i][j][l] = min(dp[i][j][l], mn+p[i-1][l-1]);
          }
          if (nc != l) {
            dp[i][j][l] = min(dp[i][j][l], nn+p[i-1][l-1]);
          }
        }
      }
    }
  }
  long long ans = 1ll<<60;
  repi(i, 1, m+1) {
    ans = min(ans, dp[n][k][i]);
  }
  cout << (ans == (1ll<<60) ? -1 : ans);
  return 0;
}
