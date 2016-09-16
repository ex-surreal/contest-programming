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
  int t;
  cin >> t;
  map <int, int> cnt;
  rep(i, t) {
    string o;
    long long x;
    cin >> o >> x;
    int a = 0, b = 1;
    while (x > 0) {
      a += b*(x%2);
      b *= 2;
      x /= 10;
    }
    if (o == "+") {
      cnt[a] ++;
    } else if (o == "-") {
      cnt[a] --;
    } else {
      cout << cnt[a] << "\n";
    }
  }
  return 0;
}
