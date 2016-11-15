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

vt(int) a;

int solve(int i, int j, int h) {
  if (i > j) {
    return 0;
  }
  int m = j;
  repi(k, i, j) {
    if (a[k] < a[m]) {
      m = k;
    }
  }
  return min(j-i+1, solve(i, m-1, a[m]) + solve(m+1, j, a[m]) + a[m]-h);
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  a.resize(n);
  repe(&e, a) {
    cin >> e;
  }
  cout << solve(0, n-1, 0);
  return 0;
}
