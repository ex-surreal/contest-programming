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

vector <int> D, adj;

int dfs(int u) {
  if (D[adj[u]] == -1) {
    D[adj[u]] = D[u] + 1;
    return dfs(adj[u]);
  }
  return D[u]-D[adj[u]]+1;
}

vector <vector <int> > g;
vector <int> seen;

int cnt(int u) {
  int ret = 1;
  seen[u] = true;
  repe(v, g[u]) {
    if (!seen[v]) {
      ret += cnt(v);
    }
  }
  return ret;
}

int pwr(int r, int e, int mod) {
  if (e == 0) {
    return 1;
  }
  int t = pwr(r, e/2, mod);
  return (e&1) ? 1ll*t*t%mod*r%mod : 1ll*t*t % mod;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  D.resize(n, -1);
  D[0] = 0;
  adj.resize(n);
  g.resize(n);
  seen.resize(n);
  repe(&e, adj) {
    cin >> e;
    e --;
  }
  rep(i, n) {
    g[i].push_back(adj[i]);
    g[adj[i]].push_back(i);
  }
  int mod = 1e9+7, ans = 1;
  rep(i, n) {
    if (!seen[i]) {
      int c = dfs(i);
      int k = cnt(i);
      ans = 1ll*pwr(2, k-c, mod)*(pwr(2, c, mod)-2+mod)%mod*ans % mod;
    }
  }
  cout << ans;
  return 0;
}
