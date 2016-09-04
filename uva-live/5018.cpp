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
  int n, q;
  while (~scanf("%d%d", &n, &q) && n) {
    vector <int> x(n), y(n);
    rep(i, n) {
      scanf("%d%d", &x[i], &y[i]);
    }
    repi(i, 1, n) {
      x[i] -= x[0];
      y[i] -= y[0];
    }
    x[0] = y[0] = 0;
    vector <long long> cum(n);
    repi(i, 1, n) {
      cum [i] = cum[i-1] - 1ll*x[i-1]*y[i] + 1ll*y[i-1]*x[i];
    }
    rep(i, q) {
      int a, b;
      scanf("%d%d", &a, &b);
      long long t = cum[a]+cum.back()-cum[b] - 1ll*x[a]*y[b] + 1ll*y[a]*x[b];
      t = min(t, cum.back()-t);
      printf("%lld%s\n", t/2, (t%2 ? ".5" : ".0"));
    }
  }
  return 0;
}
