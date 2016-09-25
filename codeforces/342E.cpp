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

vector <int> last, pre, nxt, to, parent, cnt;
vector <vector <int> > D;

void init(int n) {
  cnt = last = parent = vector <int> (n, -1);
  D.resize(n);
}

void add(int u, int v) {
  to.push_back(v);
  nxt.push_back(-1);
  if (last[u] != -1) {
    nxt[last[u]] = sz(pre);
  }
  pre.push_back(last[u]);
  last[u] = sz(pre)-1;
}

void del(int e) {
  if(last[to[e^1]] == e){
    last[to[e^1]] = pre[e];
  }
  if (~pre[e]) {
    nxt[pre[e]] = nxt[e];
  }
  if (~nxt[e]) {
    pre[nxt[e]] = pre[e];
  }
}

int find_centroid(int u, int w, int n) {
  cnt[u] = 1;
  int ret = -1;
  bool ok = true;
  for (int e = last[u]; ~e; e = pre[e]) {
    if (to[e] != w) {
      int t = find_centroid(to[e], u, n);
      cnt[u] += cnt[to[e]];
      ret = t != -1 ? t : ret;
      ok = ok && cnt[to[e]] <= n/2; 
    }
  }
  if (ok && ret == -1) {
    ret = n-cnt[u] > n/2 ? -1 : u;
  }
  return ret;
}

int dfs(int u, int w, int d) {
  D[u].push_back(d);
  int ret = 1;
  for (int e = last[u]; ~e; e = pre[e]) {
    if (to[e] != w) {
      ret += dfs(to[e], u, d+1);
    }
  }
  return ret;
}

void decompose(int r, int n, int w) {
  int c = find_centroid(r, -1, n);
  parent[c] = w;
  D[c].push_back(0);
  for (int e = last[c]; ~e; e = pre[e]) {
    del(e), del(e^1);
    decompose(to[e], dfs(to[e], -1, 1), c);
  }
}

vector <int> dis;

void update(int u) {
  int i = sz(D[u]), t = u;
  while (~u) {
    dis[u] = min(dis[u], D[t][-- i]);
    u = parent[u];
  }
}

int read(int u) {
  int ans = 1<<29, i = sz(D[u]), t = u;
  while (~u) {
    ans = min(ans, dis[u]+D[t][-- i]);
    u = parent[u];
  }
  return ans;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  init(n);
  dis.resize(n, 1<<29);
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    add(u-1, v-1);
    add(v-1, u-1);
  }
  decompose(0, n, -1);
  update(0);
  rep(i, q) {
    int t, u;
    cin >> t >> u;
    if (t == 1) {
      update(u-1);
    } else {
      cout << read(u-1) << "\n";
    }
  }
  return 0;
}
