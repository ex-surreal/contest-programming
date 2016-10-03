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

vector <string> B, seen;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
int cnt;

int dfs(int i, int j) {
  int ret = 1;
  if (i == 0 || j == 0 || i == sz(B)-1 || j == sz(B.back())-1) {
    ret = 0;
  }
  cnt ++;
  seen[i][j] = '*';
  rep(t, 4) {
    int x = i+di[t];
    int y = j+dj[t];
    if (x < 0 || y < 0 || x >= sz(B) || y >= sz(B.back())) {
      continue;
    }
    if (seen[x][y] != '.') {
      continue;
    }
    ret = dfs(x, y) && ret;
  }
  return ret;
}

void go(int i, int j) {
  B[i][j] = '*';
  rep(t, 4) {
    int x = i+di[t];
    int y = j+dj[t];
    if (x < 0 || y < 0 || x >= sz(B) || y >= sz(B.back())) {
      continue;
    }
    if (B[x][y] == '.') {
      go(x, y);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int m, n, k;
  cin >> m >> n >> k;
  B.resize(m);
  seen.resize(m);
  rep(i, m) {
    cin >> B[i];
    seen[i] = B[i];
  }
  vector <pair <int, pair <int, int> > > ord;
  rep(i, m) {
    rep(j, n) {
      if (seen[i][j] == '.') {
        cnt = 0;
        if (dfs(i, j)) {
          ord.push_back(mp(cnt, mp(i, j)));
        }
      }
    }
  }
  sort(all(ord));
  int r = sz(ord) - k;
  int ans = 0;
  rep(i, r) {
    ans += ord[i].x;
    go(ord[i].y.x, ord[i].y.y);
  }
  cout << ans << "\n";
  repe(e, B) {
    cout << e << "\n";
  }
  return 0;
}
