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

const double pi = acos(-1);

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  rep(i, n) {
    int p, x, y;
    cin >> p >> x >> y;
    x -= 50, y -= 50;
    double th = atan2(x, y), a = pi*p/50;
    if (th < 0) {
      th += 2*pi;
    }
    cout << "Case #" << i+1 << ": ";
    if (abs(x) <= 50 && abs(y) <= 50 && x*x + y*y <= 2500 && th <= a+1e-7) {
      cout << "black\n";
    } else {
      cout << "white\n";
    }
  }
  return 0;
}
