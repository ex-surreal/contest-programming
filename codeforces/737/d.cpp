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

vt(int) a;
int dp[2][2004][180][90];
bool seen[2][2004][180][90];

#define sum(i, j) (i > 0 ? a[j]-a[(i)-1] : a[j])

int solve(int f, int i, int d, int k) {
  int j = sz(a) - (i-d) - 1;
  if (j-i < k) {
    return 0;
  }
  int &ret = dp[f][i][d+89][k];
  if (seen[f][i][d+89][k]) {
    return ret;
  }
  seen[f][i][d+89][k] = true;
  if (!f) {
    ret = solve(f^1, i+k, d+k, k) + sum(i+1, i+k);
    if (j-i-1 >= k) {
      ret = max(ret, solve(f^1, i+k+1, d+k+1, k+1) + sum(i+1, i+k+1));
    }
  } else {
    ret = solve(f^1, i, d-k, k) - sum(j-k+1, j);
    if (j-i-1 >= k) {
      ret = min(ret, solve(f^1, i, d-k-1, k+1) - sum(j-k, j));
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  a.resize(n+1);
  repi(i, 1, n+1) {
    cin >> a[i];
  }
  repi(i, 1, n+1) {
    a[i] += a[i-1];
  }
  cout << solve(0, 0, 0, 1);
  return 0;
}
