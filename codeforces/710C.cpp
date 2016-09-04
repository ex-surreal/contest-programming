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
  int n;
  cin >> n;
  vector <vector <bool> > pr(n, vector <bool>(n));
  rep(i, n/2+1) {
    rep(j, i+1) {
      pr[i][n/2+j] = pr[i][n/2-j] = true;
      pr[n-1-i][n/2+j] = pr[n-1-i][n/2-j] = true;
    }
  }
  int o = 1, e = 2;
  rep(i, n) {
    rep(j, n) {
      if (pr[i][j]) {
        cout << o << " ";
        o += 2;
      } else {
        cout << e << " ";
        e += 2;
      }
    } cout << "\n";
  }
  return 0;
}
