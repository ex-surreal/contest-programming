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

using namespace std;

const int inf = (1 << 30);
vector <int> L, pre, to, ptr, cap, flow, level;

void init(int n) {
  level = L = vector <int> (n, -1);
  pre.clear();
  to.clear();
  ptr.clear();
  cap.clear();
  flow.clear();
}

void add(int u, int v, int c = 1) {
  to.push_back(v);
  pre.push_back(L[u]);
  cap.push_back(c);
  flow.push_back(0);
  L[u] = to.size()-1;
}

void add_edge(int u, int v, int c = 1) {
  add(u, v, c);
  add(v, u, 0);
}

bool bfs(int s, int t) {
  int fr = 0, bk = 0;
  level = vector <int> (L.size(), -1);
  level[s] = 0;
  vector <int> Q(L.size());
  Q[bk++] = s;
  while (fr < bk) {
    int u = Q[fr++];
    for (int e = L[u]; e != -1; e = pre[e]) {
      if (flow[e] < cap[e]) {
        int v = to[e];
        if (level[v] == -1) {
          level[v] = level[u] + 1;
          Q[bk++] = v;
        }
      }
    }
  }
  return level[t] != -1;
}

int dfs(int u, int f, int t) {
  if (u == t || f == 0) {
    return f;
  }
  for (int & e = ptr[u]; e != -1; e = pre[e]) {
    int v = to[e];
    if (flow[e] < cap[e] && level[v] == level[u] + 1) {
      int pushed = dfs(v, min(f, cap[e] - flow[e]), t);
      if (pushed > 0) {
        flow[e] += pushed;
        flow[e ^ 1] -= pushed;
        return pushed;
      }
    }
  }
  return 0;
}

int mf(int s, int t) {
  int ret = 0;
  while (bfs(s, t)) {
    ptr = L;
    while (int f = dfs(s, inf, t)) {
      ret += f;
    }
  }
  return ret;
}

vector <int> color;

void dfs(int u, int c) {
  color[u] = c;
  for (int e = L[u]; ~e; e = pre[e]) {
    if (cap[e] - flow[e] == 0) {
      continue;
    }
    int v = to[e];
    if (color[v] == -1) {
      dfs(v, c);
    }
  }
}

vector <bool> seen;
int r, c;

void print(int u) {
  seen[u] = true;
  for (int e = L[u]; ~e; e = pre[e]) {
    int v = to[e];
    if (cap[e] - flow[e] == 0) {
      if (flow[e] == 1 && color[u] != color[v]) {
        cout << (color[u] == u ? " r" + to_string(v+1) : " c" + to_string(u-r+1));
      }
      continue;
    }
    if (!seen[v]) {
      print(v);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  while (cin >> r >> c >> n && r) {
    init(r+c+2);
    rep(i, n) {
      int u, v;
      cin >> u >> v;
      add_edge(u-1, v-1+r);
    }
    int s = r+c, t = s+1;
    rep(i, r) {
      add_edge(s, i);
    }
    rep(i, c) {
      add_edge(r+i, t);
    }
    cout << mf(s, t);
    color.clear(), color.resize(r+c+2, -1);
    seen.clear(), seen.resize(r+c+2, false);
    dfs(s, s);
    dfs(t, t);
    print(s);
    cout << "\n";
  }
  return 0;
}
