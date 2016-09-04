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

const int limit = 1000006;
int lst[limit];

int main () {
  std::ios_base::sync_with_stdio(false);
  repi(i, 2, limit) {
    if (lst[i] != 0) {
      continue;
    }
    for (int j = i; j < limit; j += i) {
      lst[j] = i;
    }
  }
  int tst;
  cin >> tst;
  while (tst --) {
    int n, ans = 0;
    cin >> n;
    while (n > 1) {
      int t = lst[n], c = 0;
      while (n % t == 0) {
        n /= t;
        c ++;
      }
      ans = max(ans, c);
    }
    cout << ans << "\n";
  }
  return 0;
}
