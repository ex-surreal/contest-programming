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
  vt(int) a(n), f(n), g(n);
  rep(i, n) {
    cin >> a[i];
    a[i] += (i ? a[i-1] : 0);
  }
  int mx = a.back(), mn = -a.back();
  for (int i = n-2; i >= 0; i --) {
    f[i] = mx;
    g[i] = mn;
    mn = min(mn, f[i]-a[i]);
    mx = max(mx, g[i]+a[i]);
  }
  cout << f[0];
  return 0;
}
