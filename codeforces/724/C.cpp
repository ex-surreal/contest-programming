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
  int m, n, k;
  cin >> m >> n >> k;
  vt(ll) ans(k, -1);
  bool f = false;
  if (m < n) {
    swap(m, n);
    f = true;
  }
  map <px(int), vt(px(int))> id[4];
  rep(i, k) {
    int x, y;
    cin >> x >> y;
    if (f) {
      swap(x, y);
    }
    int d = min(x, y);
    id[0][mp(x-d, y-d)].push_back(mp(i, d));
    d = min(x, n-y);
    id[1][mp(x-d, y+d)].push_back(mp(i, d));
    d = min(m-x, n-y);
    id[2][mp(x+d, y+d)].push_back(mp(i, d));
    d = min(m-x, y);
    id[3][mp(x+d, y-d)].push_back(mp(i, d));
  }
  int x = 0, y = 0, i = 0;
  int dx[] = {+1, +1, -1, -1};
  int dy[] = {+1, -1, -1, +1};
  ll cur = 0;
  rep(l, 3*(m+n)) {
    if (id[i].find(mp(x, y)) != id[i].end()){
      repe(e, id[i][mp(x, y)]) {
        if (ans[e.x] == -1) {
          ans[e.x] = e.y+cur;
        }
      }
      id[i].erase(mp(x, y));
    }
    int d = -1;
    switch (i) {
      case 0:
        d = min(m-x, n-y);
        break;
      case 1:
        d = min(m-x, y);
        break;
      case 2:
        d = min(x, y);
        break;
      case 3:
        d = min(x, n-y);
        break;
    }
    cur += d;
    x += dx[i]*d;
    y += dy[i]*d;
    if (y == n) {
      if (i == 0) {
        i = 1;
      } else {
        i = 2;
      }
    } else if (y == 0) {
      if (i == 2) {
        i = 3;
      } else {
        i = 0;
      }
    } else if (x == m) {
      if (i == 1) {
        i = 2;
      } else {
        i = 3;
      }
    } else {
      if (i == 3) {
        i = 0;
      } else {
        i = 1;
      }
    }
    if (mp(x, y) == mp(m, n) || mp(x, y) == mp(m, 0) || mp(x, y) == mp(0, n) || mp(x, y) == mp(0, 0)) {
      break;
    }
  }
  repe(e, ans) {
    cout << e << "\n";
  }
  return 0;
}
