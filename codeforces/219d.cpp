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

vt(vt(pxy(int, bool))) adj;
vt(int) cnt, depth;

int dfs(int u, int w) {
  int ret = 0;
  repe(v, adj[u]) {
    if (v.x == w) {
      continue;
    }
    cnt[v.x] = cnt[u] + v.y;
    depth[v.x] = depth[u] + 1;
    ret += v.y + dfs(v.x, u);
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  adj.resize(n);
  rep(i, n-1) {
    int x, y;
    cin >> x >> y;
    adj[x-1].push_back(mp(y-1, 0));
    adj[y-1].push_back(mp(x-1, 1));
  }
  cnt.resize(n);
  depth.resize(n);
  int tot = dfs(0, -1), mn = INT_MAX;
  rep(i, n) {
    int t = tot - 2*cnt[i] + depth[i];
    mn = min(mn, t);
  }
  cout << mn << "\n";
  rep(i, n) {
    int t = tot - 2*cnt[i] + depth[i];
    if (t == mn) {
      cout << i+1 << " ";
    }
  }
  return 0;
}
