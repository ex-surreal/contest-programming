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
  int n, q;
  cin >> n >> q;
  int e = 0, o = 1;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      e = (e + x%n+n)%n;
      o = (o + x%n+n)%n;
    } else {
      if (e&1) {
        e --;
        o ++;
      } else {
        e ++;
        o --;
      }
    }
  }
  vector <int> ans(n);
  rep(i, n/2) {
    ans[e] = i*2;
    ans[o] = i*2+1;
    e = (e+2) % n;
    o = (o+2) % n;
  }
  repe(e, ans) {
    cout << e+1 << " ";
  }
  return 0;
}
