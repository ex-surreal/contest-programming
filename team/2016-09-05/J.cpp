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

int main () {
  vector <bool> is(1000005, true);
  is[0] = is[1] = false;
  for (int i = 4; i < sz(is); i += 2) {
    is[i] = false;
  }
  for (int i = 3; i*i < sz(is); i += 2) {
    if (!is[i]) {
      continue;
    }
    for (int j = i*i; j < sz(is); j += 2*i) {
      is[j] = false;
    }
  }
  vector <int> prime;
  rep(i, sz(is)) {
    if (is[i]) {
      prime.push_back(i);
    }
  }
  int n, cas = 0;
  while (~scanf("%d", &n) && n) {
    if (n <= 3) {
      printf("Case %d: 1 1\n", ++cas);
      continue;
    }
    vector <long long> gcd(sz(prime)), lcm(sz(prime));
    rep(i, sz(prime)) {
      if (prime[i] > n) {
        break;
      }
      int t = n;
      while (t > 0) {
        t /= prime[i];
        gcd[i] += 1ll*t*(t-1)/2;
        lcm[i] += 1ll*(n-1)*t - 1ll*t*(t-1)/2;
      }
    }
    double d = 100.0*log(10.0);
    double x = 0, y = 0;
    rep(i, sz(prime)) {
      x += gcd[i]*log(prime[i])/d;
      y += lcm[i]*log(prime[i])/d;
    }
    printf("Case %d: %lld %lld\n", ++cas, (long long)ceil(x), (long long)ceil(y));
  }
  return 0;
}
