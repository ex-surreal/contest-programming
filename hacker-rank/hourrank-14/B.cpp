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

vt(int) a, t;

ll merge(int i, int j, int k, int l) {
  ll ret = 0;
  int c = i, r = i;
  while (i <= j && k <= l) {
    if (a[k] < a[i]) {
      ret += j-i+1;
      t[c ++] = a[k ++];
    } else {
      t[c ++] = a[i ++];
    }
  }
  while (i <= j) {
    t[c ++] = a[i ++];
  }
  while (k <= l) {
    t[c ++] = a[k ++];
  }
  repi(x, r, c) {
    a[x] = t[x];
  }
  return ret;
}

ll sort(int i, int j) {
  if (i >= j) {
    return 0;
  }
  int m = (i+j)/2;
  ll ret = sort(i, m) + sort(m+1, j) + merge(i, m, m+1, j);
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  a.resize(n);
  t.resize(n);
  vt(int) p(n);
  repe(&e, p) {
    cin >> e;
  }
  a = p;
  ll ans = sort(0, n-1);
  repe(&e, p) {
    e = -e;
  }
  a = p;
  ans = min(ans, sort(0, n-1));
  cout << ans << endl;
  return 0;
}
