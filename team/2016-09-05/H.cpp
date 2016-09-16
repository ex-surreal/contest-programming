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
  int n;
  while (~scanf("%d", &n)) {
    long long ans = 0;
    for (long long x = 0, y = n, s = 1ll*n*n; x <= n; x ++) {
      while (x*x + y*y > s) {
        y --;
      }
      ans += y;
    }
    printf("%d\n%lld\n", n, ans*4+1);
  }
  return 0;
}
