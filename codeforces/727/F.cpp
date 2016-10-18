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

ll dp[1000][1000];
bool seen[1000][1000];
vector <int> a;

ll solve(int i, int j) {
  if (i < 0) {
    return 0;
  }
  ll &ret = dp[i][j];
  if (!seen[i][j]) {
    seen[i][j] = true;;
    ll t = solve(i-1, j) + a[i];
    if (j > 0) {
      t = max(t, solve(i-1, j-1));
    }
    if (t >= 0) {
      ret = t;
    } else {
      ret = -(1ll<<62);
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  a.resize(n);
  repe(&e, a) {
    cin >> e;
  }
  int t = 0;
  vt(pxy(ll, int)) p;
  rep(i, m) {
    ll x;
    cin >> x;
    p.push_back(mp(x, i));
  }
  rep(i, n+1) {
    cout << solve(n-1, i) << endl;
  }
  vt(int) ans(m);
  sort(all(p));
  rep(i, m) {
    while (t < n && solve(n-1, t) < p[i].x) {
      t ++;
    }
    ans[p[i].y] = t;
  }
  repe(e, ans) {
    cout << e << "\n";
  }
  return 0;
}
