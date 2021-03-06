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

int dp[1005][1005];

int solve(int n, int l) {
  if (n == 0) {
    return 0;
  }
  if (n < 0 || l <= 0) {
    return INT_MIN/3;
  }
  int &ret = dp[n][l];
  if (ret == -1) {
    ret = max(solve(n-l, l-1)+1, solve(n, l-1));
  }
  return ret;
}

void print(int n, int l) {
  if (n == 0) {
    return;
  }
  if (solve(n, l) == solve(n-l, l-1)+1) {
    cout << l << " ";
    print(n-l, l-1);
  } else {
    print(n, l-1);
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  mem(dp, -1);
  cout << solve(n, n) << "\n";
  print(n, n);
  return 0;
}
