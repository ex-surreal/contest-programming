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

int rev(int x) {
  int ret = 0;
  while (x > 0) {
    ret = ret*10 + x%10;
    x /= 10;
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int a, b, k;
  cin >> a >> b >> k;
  int ans = 0;
  repi(i, a, b+1) {
    if (abs(rev(i)-i)%k == 0) {
      ans ++;
    }
  }
  cout << ans << endl;
  return 0;
}
