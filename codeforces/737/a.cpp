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

ll can(vt(int) &g, int v) {
  ll ret = 0;
  repi(i, 1, sz(g)) {
    int d = g[i]-g[i-1];
    int x = min(v-d, d);
    if (x >= 0) {
      ret += 2ll*d-x;
    } else {
      return LLONG_MAX;
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, k, s, t;
  cin >> n >> k >> s >> t;
  vt(px(int)) p(n);
  repe(&e, p) {
    cin >> e.y >> e.x;
  }
  sort(all(p));
  vt(int) g(k+2);
  rep(i, k) {
    cin >> g[i];
  }
  g.back() = s;
  sort(all(g));
  vt(int) mn(n);
  int l = INT_MAX;
  for (int i = n-1; i >= 0; i --) {
    l = mn[i] = min(l, p[i].y);
  }
  int high = n-1, low = 0;
  while (low <= high) {
    int mid = (high+low)/2;
    ll y = can(g, p[mid].x);
    if (y > t) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (low == n) {
    cout << -1;
  } else {
    cout << mn[low];
  }
  return 0;
}
