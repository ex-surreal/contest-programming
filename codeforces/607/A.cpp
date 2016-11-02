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
  vt(px(int)) p(n);
  repe(&e, p) {
    cin >> e.x >> e.y;
  }
  sort(all(p));
  vt(int) dp(n), left(1000001, -1);
  rep(i, n) {
    left[p[i].x] = i;
  }
  for (int l = -1, i = 0; i <= 1000000; i ++) {
    if (left[i] != -1) {
      l = left[i];
    }
    left[i] = l;
  }
  rep(i, n) {
    int t = p[i].x-p[i].y-1;
    dp[i] = t >= 0 && left[t] >= 0 ? dp[left[t]]+1 : 1;
  }
  cout << n - *max_element(all(dp));
  return 0;
}
