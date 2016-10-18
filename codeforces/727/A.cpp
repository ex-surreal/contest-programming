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

vt(int) ans;

void go(int a, int b) {
  if (a == b) {
    ans.push_back(a);
    return;
  }
  if (a < b || (a%10 > 1 && a%2)) {
    throw string("NO");
  }
  if (a&1) {
    go(a/10, b);
    ans.push_back(a);
  } else {
    go(a/2, b);
    ans.push_back(a);
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  try {
    go(b, a);
    cout << "YES\n" << sz(ans) << "\n";
    repe(e, ans) {
      cout << e << " ";
    }
  } catch (string p) {
    cout << p;
  }
  return 0;
}
