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

vt(int) last, pre, to, bridge, dir, low, seen;

void add(int u, int v) {
  to.push_back(v);
  pre.push_back(last[u]);
  bridge.push_back(-1);
  dir.push_back(-1);
  last[u] = sz(pre)-1;
}

int z;

void find_bridge(int u, int w = -1) {
  low[u] = seen[u] = z ++;
  for (int e = last[u]; ~e; e = pre[e]) {
    int v = to[e];
    if (seen[v] == -1) {
      find_bridge(v, u);
      bridge[e] = bridge[e^1] = low[v] == seen[v];
      low[u] = min(low[u], low[v]);
    } else if (v != w) {
      low[u] = min(low[u], seen[v]);
      bridge[e] = false;
    }
  }
}

int dfs(int u) {
  int ret = 1;
  seen[u] = 1;
  for (int e = last[u]; ~e; e = pre[e]) {
    int v = to[e];
    if (!bridge[e] && seen[v] == -1) {
      ret += dfs(v);
    }
  }
  return ret;
}

void give_dir(int u) {
  seen[u] = 1;
  for (int e = last[u]; ~e; e = pre[e]) {
    int v = to[e];
    if (seen[v] == -1) {
      give_dir(v);
      dir[e] = !bridge[e];
      dir[e^1] = !dir[e];
    } else if (dir[e] == -1) {
      dir[e] = 1;
      dir[e^1] = 0;
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  low.resize(n);
  seen.resize(n, -1);
  last.resize(n, -1);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    add(u-1, v-1);
    add(v-1, u-1);
  }
  find_bridge(0);
  int mx = -1, st = -1;
  fill(all(seen), -1);
  rep(i, n) {
    if (seen[i] == -1) {
      int t = dfs(i);
      if (t > mx) {
        st = i;
        mx = t;
      }
    }
  }
  fill(all(seen), -1);
  give_dir(st);
  cout << mx << "\n";
  rep(i, sz(dir)) {
    if (dir[i]) {
      cout << to[i^1]+1 << " " << to[i]+1 << "\n";
    }
  }
  return 0;
}
