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
    ll l, r;
    string p;
    cin >> p >> l >> r;
    l --, r --;
    int s = sz(p);
    vt(int) c(s+1);
    rep(i, s) {
      c[i+1] = c[i] + (p[i] == 'B');
    }
    ll i = l/s*s, j = (r+s)/s*s-1;
    ll sum = (j-i+1)/s*c.back() - c[l%s] - (c.back()-c[r%s+1]);
    cout << "Case #" << ++ cas << ": " << sum << "\n";
  }
  return 0;
}
