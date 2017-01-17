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
  int n;
  cin >> n;
  vt(int) a(n), b(n);
  vt(vt(int)) c(n+1);
  rep(i, n) {
    cin >> a[i] >> b[i];
    c[a[i]].push_back(i);
  }
  int q;
  cin >> q;
  rep(u, q) {
    int k;
    cin >> k;
    vt(int) p(k);
    repe(&e, p) {
      cin >> e;
    }
    int high = n-1, low = 0, g = 0;
    while (low <= high) {
      int mid = (high+low) >> 1, r = 0, f = 1;
      repe(e, p) {
        f = e == a[mid] ? 0 : f;
        r += sz(c[e]) - (lower_bound(all(c[e]), mid) - c[e].begin());
      }
      if (f) {
        r += sz(c[a[mid]]) - (lower_bound(all(c[a[mid]]), mid) - c[a[mid]].begin());
        g = 1;
      }
      if (r < n-mid) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    int t = a[low];
    if (!g) {
      cout << "0 0\n";
    } else {
      int high = sz(c[t])-1, low = 0;
      p.push_back(t);
      while (low <= high) {
        int mid = (high+low) >> 1, r = 0;
        repe(e, p) {
          r += sz(c[e]) - (lower_bound(all(c[e]), c[t][mid]) - c[e].begin());
        }
        if (r < n-c[t][mid]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      cout << a[c[t][low]] << " " << b[c[t][low]] << "\n";
    }
  }
  return 0;
}
