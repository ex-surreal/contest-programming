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
  int n, m;
  cin >> n >> m;
  vt(int) p(n), c;
  repe(&e, p) {
    cin >> e;
  }
  map <string, int> cnt;
  rep(i, m) {
    string p;
    cin >> p;
    cnt[p] ++;
  }
  repe(e, cnt) {
    c.push_back(e.y);
  }
  sort(all(p));
  sort(all(c));
  int l = 0, r = 0;
  rep(i, sz(c)) {
    r += c[sz(c)-i-1]*p[sz(p)-1-i];
    l += c[sz(c)-i-1]*p[i];
  }
  cout << l << " " << r;
  return 0;
}
