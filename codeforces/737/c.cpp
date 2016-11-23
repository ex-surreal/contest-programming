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
  int n, s;
  cin >> n >> s;
  s --;
  vt(int) a(n), c(n);
  repe(&e, a) {
    cin >> e;
    c[e] ++;
  }
  int f = 0, ret = 0;
  if (a[s]) {
    c[a[s]] --;
    c[0] ++;
    a[s] = 0;
    ret ++;
  }
  f = c[0] - 1;
  ret += f;
  for (int i = 1, j = *max_element(all(a)); i < j; i ++) {
    if (!c[i]) {
      if (f > 0) {
        f --;
      } else {
        ret ++;
        c[j] --;
        while (j >= 0 && !c[j]) {
          j --;
        }
      }
    }
  }
  cout << ret;
  return 0;
}
