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
  int n, m;
  cin >> n >> m;
  vt(pxy(px(int), int)) p(m);
  rep(i, m) {
    cin >> p[i].x.x >> p[i].x.y;
    p[i].x.y *= -1;
    p[i].y = i;
  }
  sort(all(p));
  vt(px(int)) ans(m);
  stack <px(int)> st;
  try {
    for (int i = 0, now = 2; i < m; i ++) {
      if (p[i].x.y) {
        ans[p[i].y] = mp(now-1, now);
        if (now > 2) {
          st.push(mp(now, 1));
        }
        now ++;
        continue;
      }
      if (st.empty()) {
        throw -1;
      }
      int x, y;
      tie(x, y) = st.top();
      ans[p[i].y] = mp(x, y);
      st.pop();
      if (y+1 < x-1) {
        st.push(mp(x, y+1));
      }
    }
    repe(e, ans) {
      cout << e.x << " " << e.y << "\n";
    }
  } catch (int ans) {
    cout << ans;
  }
  return 0;
}
