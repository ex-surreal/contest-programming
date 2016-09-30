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
  vector <int> a(n), dp(n, -1), Q(n);
  rep(i, n) {
    cin >> a[i];
    a[i] --;
  }
  dp[0] = 0;
  int fr = 0, bk = 0;
  Q[bk ++] = 0;
  while (fr < bk) {
    int u = Q[fr ++];
    vector <int> f = {u+1, u-1, a[u]};
    repe(v, f) {
      if (v < 0 || v >= n) {
        continue;
      }
      if (dp[v] == -1) {
        dp[v] = dp[u]+1;
        Q[bk ++] = v;
      }
    }
  }
  rep(i, n) {
    cout << dp[i] << " ";
  }
  return 0;
}
