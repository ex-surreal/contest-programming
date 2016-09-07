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

vector <int> lst, to, pre, cst, can, parent, D;

void init(int n) {
  lst = vector <int> (n, -1);
  to.clear();
  pre.clear();
  cst.clear();
  can.clear();
  parent.resize(n);
  D.resize(n);
}

void add(int u, int v, int c) {
  to.push_back(v);
  cst.push_back(c);
  can.push_back(1);
  pre.push_back(lst[u]);
  lst[u] = sz(pre)-1;
}

void add_edge(int u, int v, int c) {
  add(u, v, c);
  add(v, u, c);
}

void dfs(int u, int w) {
  for (int e = lst[u]; e != -1; e = pre[e]) {
    if (to[e] == w || !can[e]) {
      continue;
    }
    parent[to[e]] = e;
    D[to[e]] = D[u]+cst[e];
    dfs(to[e], u);
  }
}

int get_dia(int s) {
  rep(i, 2) {
    parent[s] = -1;
    fill(all(D), -1);
    D[s] = 0;
    dfs(s, -1);
    s = max_element(all(D)) - D.begin();
  }
  return s;
}

int get_min(int s, int &d) {
  s = get_dia(s);
  int ret = D[s];
  d = D[s];
  while (parent[s] != -1) {
    ret = min(ret, max(D[s], d-D[s]));
    s = to[parent[s]^1];
  }
  return ret;
}

int solve() {
  int l = get_dia(0);
  vector <int> go = parent;
  int ret = D[l];
  while (go[l] != -1) {
    can[go[l]] = can[go[l]^1] = 0;
    int a, b;
    int t = get_min(l, a)+get_min(to[go[l]^1], b) + cst[go[l]];
    ret = min(ret, max(t, max(a, b)));
    if (ret == 6) {
      cout << l << endl;
    }
    can[go[l]] = can[go[l]^1] = 1;
    l = to[go[l]^1];
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int n;
    cin >> n;
    init(n);
    rep(i, n-1) {
      int u, v, c;
      cin >> u >> v >> c;
      add_edge(u, v, c);
    }
    cout << "Case " << ++ cas << ": " << solve() << "\n";
  }
  return 0;
}
