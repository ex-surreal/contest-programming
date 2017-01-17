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

tuple <int, int, int> parse(string p) {
  int x = 0, y = 0, z = 0, i = 0;
  while (p[i] != 'd') {
    x = x*10 + p[i ++]-'0';
  }
  while (++ i < sz(p) && p[i] >= '0' && p[i] <= '9') {
    y = y*10 + p[i]-'0';
  }
  if (i < sz(p)) {
    int t = p[i] == '-' ? -1 : 1;
    while (++ i < sz(p)) {
      z = z*10 + p[i]-'0';
    }
    z *= t;
  }
  return make_tuple(x, y, z);
}

double dp[25][20005][25];

int main () {
  std::ios_base::sync_with_stdio(false);
  cout.precision(6);
  cout.setf(ios::fixed);
  repi(k, 1, 25) {
    rep(j, 25) {
      dp[k][0][j] = 1;
    }
    repi(i, 1, 20005) {
      repi(j, 1, 25) {
        repi(l, 1, k+1) {
          dp[k][i][j] += (i >= l ? dp[k][i-l][j-1] : 1)/k;
        }
      }
    }
  }
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int h, s;
    cin >> h >> s;
    double ans = 0;
    rep(i, s) {
      string p;
      cin >> p;
      int x, y, z;
      tie(x, y, z) = parse(p);
      if (h-z <= 0) {
        ans = 1;
      } else {
        ans = max(ans, dp[y][h-z][x]);
      }
    }
    cout << "Case #" << ++ cas << ": " << ans << "\n";
  }
  return 0;
}
