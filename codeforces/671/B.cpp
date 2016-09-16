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
  std::ios_base::sync_with_stdio(false);
  int n;
  typedef long long ll;
  ll k;
  cin >> n >> k;
  vector <ll> a(n), r(n);
  repe(&e, a) {
    cin >> e;
  }
  sort(all(a));
  ll s = accumulate(all(a), 0ll);
  ll c = (s+n-1)/n, f = s/n;
  ll x = 0, y = 0;
  rep(i, n) {
    if (a[i] < f) {
      x += f - a[i];
    }
    if (a[i] > c) {
      y += a[i] - c;
    }
  }
  if (min(x, y) <= k) {
    cout << c-f;
    return 0;
  }
  int i = 0, j = n-1;
  while (i+1 < j) {
    ll d = (a[j] - a[j-1]) * (n-j);
    while (i+1 < j) {
      ll can = (a[i+1]-a[i])*(i+1)+r[i];
      if (can < d) {
        d -= can;
        i ++;
      } else {
        a[i] += d/(i+1);
        a[i] += (r[i]+d%(i+1))/(i+1);
        r[i] = (r[i]+d%(i+1))%(i+1);
        r[i] = (i+1-r[i]) % (i+1);
        j --;
        d = 0;
        break;
      }
    }
    if (i+1 == j) {
    }
  }
  return 0;
}
