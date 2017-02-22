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

map <ll, int> dp[66];

int grundy(int n, ll b) {
  if (n == 0) {
    return 0;
  }
  if (dp[n].find(b) != dp[n].end()) {
    return dp[n][b];
  }
  ll g = 0;
  repi(i, 1, n+1) {
    if (!((b>>i)&1)) {
      g |= 1ll << grundy(n-i, b|(1<<i));
    }
  }
  int t = 0;
  while ((g>>t)&1) {
    t ++;
  }
  return dp[n][b] = t;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  rep(i, n) {
    int x;
    cin >> x;
    ans ^= grundy(x, 0);
  }
  cout << (!ans ? "YES" : "NO");
  return 0;
}
