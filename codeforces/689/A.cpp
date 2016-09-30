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
  vector <int> x(10), y(10);
  rep(i, 3) {
    rep(j, 3) {
      x[i*3+j+1] = i;
      y[i*3+j+1] = j;
    }
  }
  x[0] = 3, y[0] = 1;
  int n;
  cin >> n;
  string p;
  cin >> p;
  int s = 0;
  rep(t, 10) {
    s ++;
    int i = x[t], j = y[t];
    repi(r, 1, n) {
      i += x[p[r]-'0']-x[p[r-1]-'0'];
      j += y[p[r]-'0']-y[p[r-1]-'0'];
      if (i == 3 && j == 1) {
        continue;
      }
      if (i < 0 || i > 2 || j < 0 || j > 2) {
        s --;
        break;
      }
    }
  }
  cout << (s > 1 ? "NO" : "YES");
  return 0;
}
