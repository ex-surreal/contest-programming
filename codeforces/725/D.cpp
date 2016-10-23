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
  int n;
  cin >> n;
  ll x, y;
  cin >> x >> y;
  multiset <ll> before;
  multiset <px(ll)> after;
  rep(i, n-1) {
    ll t, w;
    cin >> t >> w;
    if (t > x) {
      before.insert(w+1-t);
    } else {
      after.insert(mp(-t, w));
    }
  }
  int ans = sz(before);
  while (!before.empty()) {
    if (*before.begin() > x) {
      break;
    }
    x -= *before.begin();
    before.erase(before.begin());
    while (!after.empty() && -after.begin()->x > x) {
      before.insert(after.begin()->y+1+after.begin()->x);
      after.erase(after.begin());
    }
    ans = min(ans, sz(before));
  }
  cout << ans+1;
  return 0;
}
