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

const int lim = 400050;
int cnt[lim];

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  rep(i, n) {
    int x;
    cin >> x;
    cnt[x] ++;
  }
  repi(i, 1, lim) {
    cnt[i] += cnt[i-1];
  }
  ll ans = 0;
  repi(i, 1, lim) {
    if (cnt[i]-cnt[i-1] == 0) {
      continue;
    }
    ll t = 0;
    for (int j = i; j + i < lim; j += i) {
      t += 1ll*(cnt[j+i-1]-cnt[j-1])*j;
    }
    ans = max(ans, t);
  }
  cout << ans;
  return 0;
}
