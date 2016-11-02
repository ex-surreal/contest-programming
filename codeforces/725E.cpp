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
  int c, n;
  cin >> c >> n;
  vt(int) left(c+1), cnt(c+1);
  rep(i, n) {
    int x;
    cin >> x;
    cnt[x] ++;
  }
  int lst = 0;
  rep(i, c+1) {
    if (cnt[i]) {
      lst = i;
    }
    left[i] = lst;
  }
  try {
    rep(i, c) {
      int t = c, now = left[c], f = 0;
      if (now < i) {
        t -= i;
        now = left[t];
        f = 1;
      }
      while (t > 0 && now > 0) {
        t -= now*min(t/now, cnt[now]);
        now = left[min(now-1, t)];
        if (!f && i <= t && now < i) {
          f = 1;
          t -= i;
          now = left[min(now, t)];
        }
      }
      if (t > 0) {
        throw i;
      }
    }
    cout << "Greed is good";
  } catch (int ans) {
    cout << ans;
  }
  return 0;
}
