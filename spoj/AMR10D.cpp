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

int dp[10][2222][11];
int d[10], tot;

int solve(int i, int j, int k) {
  if (i == 10) {
    return k ? (1<<29) : (j > 0 ? j - 1: abs(j));
  }
  int &ret = dp[i][1000+j][k];
  if (ret == -1) {
    ret = 1<<29;
    rep(x, d[i]+1) {
      ret = min(ret, d[i]+solve(i+1, j+2*x-d[i], (k+x*i+(d[i]-x)*10*i)%11));
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst;
  cin >> tst;
  while (tst --) {
    rep(i, 9) {
      cin >> d[i+1];
    }
    tot = accumulate(d, d+10, 0);
    mem(dp, -1);
    cout << (solve(1, 0, 0) > (1<<28) ? -1 : solve(1, 0, 0)) << "\n";
  }
  return 0;
}
