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

int dp[10004][2];
set <string> ans;
string p;

int solve(int i, int j) {
  if (i == 4) {
    return 1;
  }
  if (i < 4) {
    return 0;
  }
  int &ret = dp[i][j];
  if (ret == -1) {
    ret = 1;
    string t(3, 'a'), v(3, 'a');
    rep(k, 3) {
      t[k] = p[i+k-2];
      v[k] = p[i+1+k];
    }
    string s(2, 'a'), u(2, 'a');
    rep(k, 2) {
      s[k] = p[i+k-1];
      u[k] = p[i+1+k];
    }
    if (j == 0) {
      if (solve(i-3, 1)) {
        ans.insert(t);
      }
      if (u != s && solve(i-2, 0)) {
        ans.insert(s);
      }
    } else {
      if (solve(i-2, 0)) {
        ans.insert(s);
      }
      if (v != t && solve(i-3, 1)) {
        ans.insert(t);
      }
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  mem(dp, -1);
  cin >> p;
  p = p + "AAA";
  solve(sz(p)-4, 0);
  cout << sz(ans) << "\n";
  repe(e, ans) {
    cout << e << "\n";
  }
  return 0;
}
