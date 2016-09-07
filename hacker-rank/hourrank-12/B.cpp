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

long long dp[3003][3003];
int L, R;
vector <int> a;

long long solve(int i, int j) {
  if (i < 0) {
    return 0;
  }
  long long &ret = dp[i][j];
  if (ret == -1) {
    int l = j, r = i+1-j;
    int tl = L-l, tr = R-r;
    ret = 1ll<<60;
    if (l > 0) {
      ret = min(ret, solve(i-1, j-1) + 1ll*(r-tr)*a[i]);
    }
    if (r > 0) {
      ret = min(ret, solve(i-1, j) + 1ll*(l-tl)*a[i]);
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n >> L;
  mem(dp, -1);
  R = n-L;
  a.resize(n);
  repe(&e, a) {
    cin >> e;
  }
  sort(all(a));
  cout << solve(n-1, L) << endl;
  return 0;
}
