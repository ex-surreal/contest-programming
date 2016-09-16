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

typedef pair <double, double> point;

double dis(point a, point b) {
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main () {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout.setf(ios::fixed);
  double ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  int n;
  cin >> n;
  vector <vector <double> > dp(n+1, vector <double>(4));
  dp[0][0] = 1e18;
  rep(i, n) {
    double x, y;
    cin >> x >> y;
    double a = dis(mp(ax, ay), mp(x, y));
    double b = dis(mp(bx, by), mp(x, y));
    double d = dis(mp(x, y), mp(tx, ty));
    rep(j, 4) {
      dp[i+1][j] = 1e18;
      dp[i+1][j] = min(dp[i+1][j], d*2 + dp[i][j]);
      if (!(j&1)) {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j|1]+a+d);
      }
      if (!(j&2)) {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j|2]+b+d);
      }
    }
  }
  cout << dp[n][0];
  return 0;
}
