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

typedef long long ll;

int pwr(int b, ll e, int mod) {
  if (e == 0) {
    return 1 % mod;
  }
  int t = pwr(b, e/2, mod);
  t = 1ll*t*t % mod;
  return e%2 ? 1ll*t*b % mod : t;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  ll n, k;
  int mod = 1e6+3;
  cin >> n >> k;
  if (n <= 63 && (1ll<<n) < k) {
    cout << "1 1";
    return 0;
  }
  ll two = 1;
  for (ll t = k-1; t > 0; t >>= 1) {
    two = two*pwr(2, t>>1, mod) % mod;
  }
  two = pwr(two, mod-2, mod);
  ll A = 0, B = pwr(pwr(2, n, mod), k-1, mod)*two % mod;
  if (k < mod) {
    A = two;
    int t = pwr(2, n, mod);
    repi(i, 1, k) {
      A = A * (t-i+mod) % mod;
    }
  }
  A = (B-A+mod) % mod;
  cout << A << " " << B;
  return 0;
}
