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
  vt(int) a(n);
  repe(&e, a) {
    cin >> e;
  }
  if (n%2 == 0 || n == 1) {
    cout << -1;
    return 0;
  }
  int ans = 0;
  for (int i = n-1; i > 0; i -= 2) {
    int t = max(a[i], a[i-1]);
    a[(i+1)/2-1] -= min(t, a[(i+1)/2-1]);
    ans += t;
  }
  cout << ans+a[0];
  return 0;
}
