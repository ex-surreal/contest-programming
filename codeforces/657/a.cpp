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
  int n, d, h;
  cin >> n >> d >> h;
  if (d > 2*h) {
    cout << -1;
    return 0;
  }
  vt(int) deg(n+1, 0), u, v;
  int now = 2, lst = 1;
  rep(i, h) {
    u.push_back(lst);
    v.push_back(now);
    deg[lst] ++;
    deg[now] ++;
    lst = now;
    now ++;
  }
  lst = 1;
  rep(i, d-h) {
    u.push_back(lst);
    v.push_back(now);
    deg[lst] ++;
    deg[now] ++;
    lst = now;
    now ++;
  }
  if (now <= n) {
    int t = -1;
    rep(i, sz(deg)) {
      if (deg[i] > 1) {
        t = i;
        break;
      }
    }
    if (t == -1) {
      cout << -1;
      return 0;
    }
    while (now <= n) {
      u.push_back(t);
      v.push_back(now ++);
    }
  }
  rep(i, sz(u)) {
    cout << u[i] << " " << v[i] << "\n";
  }
  return 0;
}
