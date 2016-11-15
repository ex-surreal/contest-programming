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
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int n, d;
    cin >> n >> d;
    ll ans = 0;
    repi(i, 1, n/d+1) {
      int l = (n-2*(i-1) + 1ll*d*i-1)/(1ll*d*i);
      int r = n/(1ll*d*i);
      l = max(1, l);
      repi(x, l, r+1) {
        int k = n - d*i*x;
        ans += k/2+1-max(0, k-i+1);
      }
    }
    cout << "Case #" << ++ cas << ": " << ans << "\n";
  }
  return 0;
}
