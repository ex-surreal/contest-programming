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

ll m;

ll cnt(ll n) {
  ll sum = 0;
  for (ll i = 2; sum <= m && i*i*i <= n; i ++) {
    sum += n/(i*i*i);
  }
  return sum;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  cin >> m;
  ll high = 8*m, low = 8;
  while (low <= high) {
    ll mid = (high+low)/2;
    if (cnt(mid) < m) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (cnt(low) != m) {
    cout << -1;
  } else {
    cout << low;
  }
  return 0;
}
