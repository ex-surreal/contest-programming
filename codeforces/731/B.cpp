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

vt(int) dp[2], a;

int solve(int f, int i) {
  if (i == sz(a)) {
    return !f;
  }
  int &ret = dp[f][i];
  if (ret == -1) {
    if (f && !a[i]) {
      ret = false;
    } else {
      if ((a[i]-f)&1) {
        ret = solve(1, i+1);
      } else {
        ret = solve(0, i+1);
      }
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  a.resize(n);
  dp[0].resize(n, -1);
  dp[1].resize(n, -1);
  repe(&e, a) {
    cin >> e;
  }
  cout << (solve(0, 0) ? "YES" : "NO");
  return 0;
}
