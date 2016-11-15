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

vt(string) B;
vt(vt(int)) seen, dp;

int dfs(int i, int j, int c) {
  if (B[i][j] == '*') {
    return 1;
  }
  seen[i][j] = c;
  int ret = 0, dx = 1, dy = 0;
  rep(e, 4) {
    int x = i+dx, y = j+dy;
    tie(dx, dy) = mp(dy, -dx);
    if (seen[x][y] != c) {
      ret += dfs(x, y, c);
    }
  }
  return ret;
}

void fill(int i, int j, int c) {
  dp[i][j] = c;
  int dx = 1, dy = 0;
  rep(e, 4) {
    int x = i+dx, y = j+dy;
    tie(dx, dy) = mp(dy, -dx);
    if (dp[x][y] == -1 && B[x][y] == '.') {
      fill(x, y, c);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int m, n, q;
  cin >> m >> n >> q;
  B.resize(m);
  seen.resize(m, vt(int)(n, -1));
  dp.resize(m, vt(int)(n, -1));
  repe(&e, B) {
    cin >> e;
  }
  int c = 0;
  rep(i, m) {
    rep(j, n) {
      if (seen[i][j] != -1 || B[i][j] == '*') {
        continue;
      }
      fill(i, j, dfs(i, j, c ++));
    }
  }
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    cout << dp[x-1][y-1] << "\n";
  }
  return 0;
}
