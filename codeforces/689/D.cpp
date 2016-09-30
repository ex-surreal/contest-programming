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

vector <int> a, b;
int dp[2][20][200005];

void make() {
  int n = sz(a);
  rep(i, n) {
    dp[0][0][i] = a[i];
    dp[1][0][i] = b[i];
  }
  for (int j = 1; (1<<j) <= n; j ++) {
    for (int i = 0; i+(1<<j)-1 < n; i ++) {
      dp[0][j][i] = max(dp[0][j-1][i], dp[0][j-1][i+(1<<(j-1))]);
      dp[1][j][i] = min(dp[1][j-1][i], dp[1][j-1][i+(1<<(j-1))]);
    }
  }
}

int read(int i, int j, int f) {
  int l = 31-__builtin_clz(j-i+1);
  if (f) {
    return min(dp[f][l][i], dp[f][l][j-(1<<l)+1]);
  } else {
    return max(dp[f][l][i], dp[f][l][j-(1<<l)+1]);
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  a.resize(n);
  b.resize(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }
  make();
  long long ans = 0;
  rep(i, n) {
    int low = i, high = n-1;
    while (low <= high) {
      int mid = (high+low)/2;
      int mn = read(i, mid, 1), mx = read(i, mid, 0);
      if (mn < mx) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    int t = high;
    low = i, high = n-1;
    while (low <= high) {
      int mid = (high+low)/2;
      int mn = read(i, mid, 1), mx = read(i, mid, 0);
      if (mn > mx) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    int s = low;
    ans += t-s+1;
  }
  cout << ans;
  return 0;
}
