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

template <class type> ostream & operator << (ostream &o, vector <type> v) {
  repe(e, v) {
    o << e << "";
  }
  return o;
}

void add(vt(int) &p, ll x, int i) {
  for (int c = 0, j = 0; j < 40; j ++) {
    int b = ((x>>j)&1) + c + p[i+j];
    p[i+j] = b&1;
    c = b>>1;
  }
}

void sub(vt(int) &p, vt(int) q) {
  int c = 0;
  rep(i, sz(p)) {
    int b = p[i]-q[i]+c;
    p[i] = b&1;
    c = b == -1 ? -1 : b/2;
  }
}

#define sum(i) ((i) >= 0 ? a[i] : 0)

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vt(int) p(n+1), a(n+42), b(n+42);
  repe(&e, p) {
    cin >> e;
  }
  rep(i, n+1) {
    if (p[i] < 0) {
      add(b, -p[i], i);
    } else {
      add(a, p[i], i);
    }
  }
  int t = 0;
  vt(int) rb = b, ra = a;
  reverse(all(rb));
  reverse(all(ra));
  if (ra < rb) {
    swap(a, b);
    t = 1;
  }
  sub(a, b);
  repi(i, 1, sz(a)) {
    a[i] += a[i-1];
  }
  int ans = 0;
  rep(i, n+1) {
    if (!sum(i-1) && !(a.back() - sum(i+39))) {
      ll y = 0, b = 1;
      rep(j, 40) {
        y += b * (a[i+j] - sum(i+j-1));
        b *= 2;
      }
      if (t) {
        y = -y;
      }
      ll d = y-p[i];
      if (abs(d) <= k) {
        ans += i < n || d != 0;
      }
    }
  }
  cout << ans;
  return 0;
}
