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

bool is_prime(int n) {
  for (int d = 2; 1ll*d*d <= n; d ++) {
    if (n%d == 0) {
      return false;
    }
  }
  return true;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (is_prime(n)) {
    cout << 1;
  } else {
    if (n&1) {
      if (is_prime(n-2)) {
        cout << 2;
      } else {
        cout << 3;
      }
    } else {
      cout << 2;
    }
  }
  return 0;
}