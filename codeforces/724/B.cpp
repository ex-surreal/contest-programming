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
  int m, n;
  cin >> m >> n;
  vt(vt(int)) a(m, vt(int)(n));
  rep(i, m) {
    rep(j, n) {
      cin >> a[i][j];
    }
  }
  string ans = "NO";
  rep(p, n) {
    rep(q, p+1) {
      rep(i, m) {
        swap(a[i][p], a[i][q]);
      }
      bool f = true;
      rep(i, m) {
        vt(int) t;
        rep(j, n) {
          if (j+1 != a[i][j]) {
            t.push_back(j);
          }
        }
        if (sz(t) > 2) {
          f = false;
        }
      }
      if (f) {
        ans = "YES";
      }
      rep(i, m) {
        swap(a[i][p], a[i][q]);
      }
    }
  }
  cout << ans;
  return 0;
}
