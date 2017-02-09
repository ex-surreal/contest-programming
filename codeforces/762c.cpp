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
  string p, q;
  cin >> p >> q;
  vt(int) pre(sz(q), -1);
  for (int i = sz(q)-1, j = sz(p)-1; i >= 0 && j >= 0;) {
    if (p[j] == q[i]) {
      pre[i --] = j --;
    } else {
      j --;
    }
  }
  int m = sz(q), l = -1, r = -1;
  int t = lower_bound(all(pre), 0) - pre.begin();
  if (t < m) {
    m = t;
    l = 0, r = t;
  }
  for (int i = 0, j = 0; i < sz(q) && j < sz(p);) {
    if (p[j] == q[i]) {
      i ++, j ++;
    } else {
      j ++;
    }
    int t = lower_bound(pre.begin()+i, pre.end(), j) - pre.begin();
    if (m > t-i) {
      m = t-i;
      l = i, r = t;
    }
  }
  if (m == sz(q)) {
    cout << "-";
  } else {
    cout << q.substr(0, l) + q.substr(r, -1);
  }
  return 0;
}
