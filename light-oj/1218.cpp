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

int path_cover(vector <int> &a) {
  int s = 2*sz(a), t = s+1;
  init(t+1);
  rep(j, sz(a)) {
    add_edge(s, j, 1);
    add_edge(j+sz(a), t, 1);
    rep(i, j) {
      if (a[j]%a[i] == 0) {
        add_edge(i, j+sz(a), 1);
      }
    }
  }
  return sz(a)-mf(s, t);
}

vector <int> solve(vector <int> a) {
  vector <int> ret;
  sort(all(a));
  int need = path_cover(a);
  for (int now = 0; need > 0 && now < sz(a);) {
    vector <int> t;
    repi(j, now+1, sz(a)) {
      if (a[j]%a[now]) {
        t.push_back(a[j]);
      }
    }
    if (path_cover(t) == need-1) {
      ret.push_back(a[now]);
      need --;
      a = t;
      now = 0;
    } else {
      now ++;
    }
  }
  assert(!need);
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst, cas = 0;
  cin >> tst;
  while (tst --) {
    int n;
    cin >> n;
    vector <int> a(n);
    rep(i, n) {
      cin >> a[i];
    }
    vector <int> ans = solve(a);
    cout << "Case " << ++ cas << ":";
    rep(i, sz(ans)) {
      cout << " " << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
