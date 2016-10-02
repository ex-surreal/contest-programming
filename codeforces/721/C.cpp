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

typedef long long ll;

ll dp[5005][5005];
int n;
vector <int> go[5005], w[5005];

ll solve(int u, int k) {
  if (u == n-1 && k == 0) {
    return 0;
  }
  ll &ret = dp[u][k];
  if (ret == -1) {
    ret = 1ll<<60;
    if (k > 0) {
      rep(i, sz(go[u])) {
        int v = go[u][i], c = w[u][i];
        ret = min(ret, solve(v, k-1)+c);
      }
    }
  }
  return ret;
}

void back(int u, int k) {
  cout << u+1 << " ";
  if (k == 0) {
    return;
  }
  rep(i, sz(go[u])) {
    int v = go[u][i], c = w[u][i];
    if (solve(u, k) == solve(v, k-1)+c) {
      back(v, k-1);
      return;
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int m, T;
  cin >> n >> m >> T;
  rep(i, m) {
    int u, v, c;
    cin >> u >> v >> c;
    u --, v --;
    go[u].push_back(v);
    w[u].push_back(c);
  }
  mem(dp, -1);
  for (int i = n-1; i >= 0; i --) {
    if (solve(0, i) <= T) {
      cout << i+1 << "\n";
      back(0, i);
      return 0;
    }
  }
  return 0;
}
