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
  map <int, vt(int)> id;
  rep(i, n) {
    int p;
    cin >> p;
    id[p].push_back(i);
  }
  vt(px(int)) s(m);
  rep(i, m) {
    cin >> s[i].x;
    s[i].y = i;
  }
  sort(all(s));
  reverse(all(s));
  vt(int) a(m), b(n);
  vt(bool) f(m);
  for (int d = 0; !s.empty(); d ++) {
    repe(&e, s) {
      if (!f[e.y] && id.find(e.x) != id.end()) {
        b[id[e.x].back()] = e.y+1;
        id[e.x].pop_back();
        if (id[e.x].empty()) {
          id.erase(e.x);
        }
        f[e.y] = true;
        a[e.y] = d;
      }
      e.x = e.x == 1 ? 0 : ((e.x+1) >> 1);
    }
    while (!s.empty() && !s.back().x) {
      s.pop_back();
    }
  }
  int c = 0, u = 0;
  rep(i, n) {
    if (b[i]) {
      c ++;
    }
  }
  rep(i, m) {
    u += a[i];
  }
  cout << c << " " << u << "\n";
  repe(e, a) {
    cout << e << " ";
  }
  cout << "\n";
  repe(e, b) {
    cout << e << " ";
  }
  return 0;
}
