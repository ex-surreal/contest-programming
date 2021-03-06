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
  ll n, ans, d;
  cin >> n >> d;
  ans = n;
  ll now = 10;
  while (now < n) {
    ll r = n%now, q = n/now;
    ll s = (q-(r < now-1))*now+now-1;
    if (n-s <= d) {
      ans = s;
    }
    now *= 10;
  }
  if (n == 10 && d > 0) {
    ans = 9;
  }
  cout << ans;
  return 0;
}
