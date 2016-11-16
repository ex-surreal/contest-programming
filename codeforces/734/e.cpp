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

vt(vt(int)) adj;
vt(int) seen, color, dis;

void dfs(int u, int c) {
  seen[u] = c;
  repe(v, adj[u]) {
    if (seen[v] == -1 && color[v] == color[u]) {
      dis[v] = dis[u] + 1;
      dfs(v, c);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  seen.resize(n);
  dis.resize(n);
  adj.resize(n);
  color.resize(n);
  repe(&e, color) {
    cin >> e;
  }
  vt(int) u(n-1), v(n-1);
  rep(i, n-1) {
    cin >> u[i] >> v[i];
    u[i] --, v[i] --;
    adj[u[i]].push_back(v[i]);
    adj[v[i]].push_back(u[i]);
  }
  fill(all(seen), -1);
  int c = 0;
  rep(i, n) {
    if (seen[i] == -1) {
      dfs(i, c ++);
    }
  }
  adj.clear();
  adj.resize(c);
  set <px(int)> st;
  rep(i, n-1) {
    int x = seen[u[i]], y = seen[v[i]];
    if (x != y && st.find(mp(x, y)) == st.end()) {
      adj[x].push_back(y);
      adj[y].push_back(x);
      st.insert(mp(x, y));
      st.insert(mp(y, x));
    }
  }
  color.clear();
  color.resize(c);
  seen.clear();
  seen.resize(c, -1);
  dis.resize(c);
  dfs(0, 0);
  int s = max_element(all(dis)) - dis.begin();
  dis[s] = 0;
  seen.clear();
  seen.resize(c, -1);
  dfs(s, 0);
  cout << (1+*max_element(all(dis)))/2;
  return 0;
}
