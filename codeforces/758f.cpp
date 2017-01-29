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

int gcd[3200][3200];

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, l, r;
  cin >> n >> l >> r;
  if (n == 1) {
    cout << r-l+1;
    return 0;
  }
  if (n == 2) {
    cout << 1ll*(r-l+1)*(r-l);
    return 0;
  }
  repi(i, 1, 3200) {
    repi(j, 1, i+1) {
      if (i % j == 0) {
        gcd[j][i] = gcd[i][j] = j;
      } else {
        gcd[j][i] = gcd[i][j] = gcd[j][i%j];
      }
    }
  }
  int s = pow(r, 1.0/(n-1));
  if (n-1 <= 30) {
    ll t = 1;
    rep(i, n-1) {
      t *= s+1;
    }
    if (t <= r) {
      s ++;
    }
  }
  ll ans = 0;
  repi(i, 1, s+1) {
    repi(j, i+1, s+1) {
      if (gcd[i][j] != 1) {
        continue;
      }
      int p = 1, q = 1, bi = i, bj = j, t = n-1;
      while (t) {
        if (t&1) {
          p *= bi;
          q *= bj;
        }
        bi *= bi;
        bj *= bj;
        t >>= 1;
      }
      ans += 2*max(0, r/q - (l-1)/p);
    }
  }
  cout << ans << endl;
  return 0;
}
