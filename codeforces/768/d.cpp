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

const int lim = 8000;
double dp[lim][1005];

int main () {
  std::ios_base::sync_with_stdio(false);
  int k, q;
  cin >> k >> q;
  dp[0][0] = 1;
  repi(i, 1, lim) {
    repi(j, 1, 1005) {
      dp[i][j] = dp[i-1][j]*j/k + dp[i-1][j-1]*(k-j+1)/k;
    }
  }
  rep(t, q) {
    int p;
    cin >> p;
    rep(i, lim) {
      if (dp[i][k] >= (p-1e-7)/2000) {
        cout << i << "\n";
        break;
      }
    }
  }
  return 0;
}
