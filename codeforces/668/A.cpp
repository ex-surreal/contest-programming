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
  int m, n, q;
  cin >> m >> n >> q;
  vector <vector <int> > ans(m, vector <int> (n));
  vector <vector <pair <int, int> > > pos(m, vector <pair <int, int> > (n));
  rep(i, m) {
    rep(j, n) {
      pos[i][j] = mp(i, j);
    }
  }
  rep(i, q) {
    int t, x, y, v;
    cin >> t;
    if (t == 1) {
      cin >> x;
      x --;
      auto l = pos[x][0];
      rep(j, n-1) {
        pos[x][j] = pos[x][j+1];
      }
      pos[x][n-1] = l;
    } else if (t == 2) {
      cin >> y;
      y --;
      auto l = pos[0][y];
      rep(j, m-1) {
        pos[j][y] = pos[j+1][y];
      }
      pos[m-1][y] = l;
    } else {
      cin >> x >> y >> v;
      x --, y --;
      ans[pos[x][y].x][pos[x][y].y] = v;
    }
  }
  rep(i, m) {
    rep(j, n) {
      cout << ans[i][j] << " ";
    } cout << "\n";
  }
  return 0;
}
