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

vt(bool) seen;
vt(int) com;
vt(vt(int)) adj;

void dfs(int u) {
  com.push_back(u);
  seen[u] = true;
  repe(v, adj[u]) {
    if (!seen[v]) {
      dfs(v);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vt(int) color(n);
  repe(&e, color) {
    cin >> e;
  }
  adj.resize(n);
  seen.resize(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  int ans = 0;
  rep(i, n) {
    if (!seen[i]) {
      com.clear();
      dfs(i);
      map <int, int> cnt;
      repe(e, com) {
        cnt[color[e]] ++;
      }
      int mx = 0;
      repe(e, cnt) {
        mx = max(e.y, mx);
      }
      ans += sz(com) - mx;
    }
  }
  cout << ans;
  return 0;
}
