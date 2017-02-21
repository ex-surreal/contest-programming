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

ll tot(ll x) {
  if (x <= 1) {
    return 1;
  }
  return 2*tot(x/2) + 1;
}

ll cnt(ll x, ll l, ll r, ll u, ll v) {
  if (v < l || u > r) {
    return 0;
  }
  if (x <= 1) {
    return x;
  }
  ll m = (u+v)/2;
  ll ret = cnt(x/2, l, r, u, m-1) + cnt(x/2, l, r, m+1, v);
  if (l <= m && m <= r) {
    ret += x&1;
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  ll x, l, r;
  cin >> x >> l >> r;
  cout << cnt(x, l, r, 1, tot(x));
  return 0;
}
