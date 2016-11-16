#include <iostream>
#include <climits>
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
  int n, m, k, x, s;
  cin >> n >> m >> k >> x >> s;
  vt(px(int)) p(m+1, mp(0, x)), q(k+1, mp(0, 0));
  rep(i, m) {
    cin >> p[i].y;
  }
  rep(i, m) {
    cin >> p[i].x;
  }
  rep(i, k) {
    cin >> q[i].y;
  }
  rep(i, k) {
    cin >> q[i].x;
  }
  sort(all(p));
  sort(all(q));
  ll ans = 1ll*x*n;
  for (int i = 0, j = k, mn = x; j >= 0; j --) {
    if (q[j].x > s) {
      continue;
    }
    while (i <= m && 1ll*p[i].x + q[j].x <= s) {
      mn = min(mn, p[i].y);
      i ++;
    }
    ans = min(1ll*mn*max(0, n-q[j].y), ans);
  }
  cout << ans;
  return 0;
}
