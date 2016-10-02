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
  int n, k;
  cin >> n >> k;
  vector <string> v(n);
  string pw;
  repe(&e, v) {
    cin >> e;
  }
  cin >> pw;
  int a = 0, b = -1;
  repe(e, v) {
    a += sz(e) < sz(pw);
    b += sz(e) <= sz(pw);
  }
  int x = 1, y = 1, failed = 0;
  rep(i, a) {
    failed ++;
    x ++;
    if (failed == k) {
      x += 5;
      failed = 0;
    }
  }
  failed = 0;
  rep(i, b) {
    failed ++;
    y ++;
    if (failed == k) {
      y += 5;
      failed = 0;
    }
  }
  cout << x << " " << y;
  return 0;
}
