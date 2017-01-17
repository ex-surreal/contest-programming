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

vt(int) solve(vt(pxy(int, px(int))) sweep, vt(int) l, vt(int) r, int k, int ans = -1) {
  set <px(int)> active, lft;
  int ret = 0;
  repe(e, sweep) {
    if (e.y.x) {
      active.erase(mp(r[e.y.y], e.y.y));
      lft.erase(mp(l[e.y.y], e.y.y));
    } else {
      active.insert(mp(r[e.y.y], e.y.y));
      lft.insert(mp(l[e.y.y], e.y.y));
      if (sz(active) == k+1) {
        lft.erase(mp(l[active.begin()->y], active.begin()->y));
        active.erase(active.begin());
      }
      if (sz(active) == k) {
        int t = active.begin()->x - lft.rbegin()->x + 1;
        if (t == ans) {
          vt(int) v;
          repe(a, active) {
            v.push_back(a.y+1);
          }
          sort(all(v));
          return v;
        }
        ret = max(t, ret);
      }
    }
  }
  throw ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vt(int) l(n), r(n);
  vt(pxy(int, px(int))) sweep;
  rep(i, n) {
    cin >> l[i] >> r[i];
    sweep.push_back(mp(l[i], mp(0, i)));
    sweep.push_back(mp(r[i], mp(1, i)));
  }
  sort(all(sweep));
  try {
    solve(sweep, l, r, k);
  } catch (int ans) {
    cout << ans << "\n";
    vt(int) v;
    try {
      v = solve(sweep, l, r, k, ans);
    } catch (int ans) {
      rep(i, k) {
        v.push_back(i+1);
      }
    }
    repe(e, v) {
      cout << e << " ";
    }
  }
  return 0;
}
