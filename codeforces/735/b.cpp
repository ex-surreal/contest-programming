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
  int n, n1, n2;
  cin >> n >> n1 >> n2;
  vt(int) a(n);
  repe(&e, a) {
    cin >> e;
  }
  sort(all(a));
  reverse(all(a));
  double f = 0, g = 0;
  if (n1 > n2) {
    swap(n1, n2);
  }
  rep(i, n1) {
    f += a[i];
  }
  repi(i, n1, n1+n2) {
    g += a[i];
  }
  cout.precision(15);
  cout.setf(ios::fixed);
  cout << (f/n1+g/n2);
  return 0;
}
