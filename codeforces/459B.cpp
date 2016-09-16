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
#define pb push_back
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int mn = 1<<30, mx = 0, a = 0, b = 0;
  rep(i, n) {
    int x;
    cin >> x;
    if (mn > x) {
      a = 1, mn = x;
    } else if (mn == x) {
      a ++;
    }
    if (mx < x) {
      b = 1, mx = x;
    } else if (mx == x) {
      b ++;
    }
  }
  if (mx == mn) {
    cout << "0 " << 1ll*n*(n-1)/2;
  } else {
    cout << mx-mn << " " << 1ll*a*b << endl;
  }
  return 0;
}
