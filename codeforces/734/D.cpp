#include <iostream>
#include <climits>
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
  int n, x, y;
  cin >> n;
  cin >> x >> y;
  vt(int) t(8, INT_MAX), c(8);
  rep(i, n) {
    int a, b;
    string p;
    cin >> p >> a >> b;
    if (x == a || y == b) {
      if (x == a) {
        if (y > b && y-b < t[0]) {
          t[0] = y-b;
          c[0] = p.front();
        } else if (y < b && b-y < t[4]) {
          t[4] = b-y;
          c[4] = p.front();
        }
      } else {
        if (x > a && x-a < t[2]) {
          t[2] = x-a;
          c[2] = p.front();
        } else if (x < a && a-x < t[6]) {
          t[6] = a-x;
          c[6] = p.front();
        }
      }
    } else if (abs(x-a) == abs(y-b)) {
      int d = abs(x-a);
      if (a > x && b > y) {
        if (t[1] > d) {
          t[1] = d;
          c[1] = p.front();
        }
      } else if (a > x) {
        if (t[3] > d) {
          t[3] = d;
          c[3] = p.front();
        }
      } else if (b < y) {
        if (t[5] > d) {
          t[5] = d;
          c[5] = p.front();
        }
      } else {
        if (t[7] > d) {
          t[7] = d;
          c[7] = p.front();
        }
      }
    }
  }
  string ans = "NO";
  rep(i, 8) {
    if (c[i] == 'Q') {
      ans = "YES";
    }
    if (i%2 == 1 && c[i] == 'B') {
      ans = "YES";
    }
    if (i%2 == 0 && c[i] == 'R') {
      ans = "YES";
    }
  }
  cout << ans;
  return 0;
}
