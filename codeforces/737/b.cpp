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

vt(int) ans;

void cnt(int d, int b, int c, int i = 0) {
  while (d/b >= c) {
    d -= b;
    ans.push_back(i+b-1);
    i += b;
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string p;
  cin >> p;
  vt(int) g, f;
  rep(i, sz(p)) {
    if (p[i] == '1') {
      continue;
    }
    int c = 0;
    while (i < sz(p) && p[i] == '0') {
      i ++;
      c ++;
    }
    if (c >= b) {
      g.push_back(c);
      f.push_back(i-c+1);
    }
  }
  vt(int) c(sz(g)+1);
  assert(sz(g));
  for (int i = sz(g)-1; i >= 0; i --) {
    c[i] = c[i+1] + g[i]/b;
  }
  rep(i, sz(g)) {
    if (c[i+1] < a) {
      cnt(g[i], b, a-c[i+1], f[i]);
    } else {
      while (g[i]/b) {
        g[i] -= b;
        ans.push_back(f[i]+b-1);
        f[i] += b;
      }
    }
  }
  cout << sz(ans) << "\n";
  repe(e, ans) {
    cout << e << " ";
  }
  return 0;
}
