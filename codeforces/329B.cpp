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
vt(vt(int)) D;

void bfs(int sx, int sy) {
  D.resize(sz(B), vt(int)(sz(B.back()), -1));
  D[sx][sy] = 0;
  vt(px(int)) Q(sz(B)*sz(B.back()));
  int fr = 0, bk = 0;
  Q[bk ++] = mp(sx, sy);
  while (fr < bk) {
    int i, j;
    tie(i, j) = Q[fr ++];
    int di = 0, dj = 1;
    rep(e, 4) {
      int x = i+di, y = j+dj;
      tie(di, dj) = mp(dj, -di);
      if (x < 0 || x >= sz(B) || y < 0 || y >= sz(B.back())) {
        continue;
      }
      if (B[x][y] != 'T' && D[x][y] == -1) {
        D[x][y] = D[i][j] + 1;
        Q[bk ++] = mp(x, y);
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  B.resize(m);
  repe(&e, B) {
    cin >> e;
  }
  int sx, sy, tx, ty;
  rep(i, m) {
    rep(j, n) {
      if (B[i][j] == 'E') {
        tx = i, ty = j;
      }
      if (B[i][j] == 'S') {
        sx = i, sy = j;
      }
    }
  }
  bfs(tx, ty);
  int ans = 0;
  rep(i, m) {
    rep(j, n) {
      if (D[i][j] == -1) {
        continue;
      }
      if (D[i][j] <= D[sx][sy] && isdigit(B[i][j])) {
        ans += B[i][j] - '0';
      }
    }
  }
  cout << ans;
  return 0;
}
