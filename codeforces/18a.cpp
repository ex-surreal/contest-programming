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

bool is_right(vt(px(int)) v) {
  rep(i, 3) {
    rep(j, i) {
      if (v[i] == v[j]) {
        return false;
      }
    }
  }
  rep(i, 3) {
    int j = (i+1) % 3;
    int k = (i+2) % 3;
    if ((v[j].x-v[i].x)*(v[k].x-v[i].x) + (v[j].y-v[i].y)*(v[k].y-v[i].y) == 0) {
      return true;
    }
  }
  return false;
}

bool is_almost_right(vt(px(int)) v) {
  int di[] = {0, 0, -1, 1};
  int dj[] = {-1, 1, 0, 0};
  rep(i, sz(v)) {
    rep(t, 4) {
      auto p = v;
      p[i].x += di[t];
      p[i].y += dj[t];
      if (is_right(p)) {
        return true;
      }
    }
  }
  return false;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  vt(px(int)) v(3);
  rep(i, 3) {
    cin >> v[i].x >> v[i].y;
  }
  if (is_right(v)) {
    cout << "RIGHT";
  } else if (is_almost_right(v)) {
    cout << "ALMOST";
  } else {
    cout << "NEITHER";
  }
  return 0;
}
