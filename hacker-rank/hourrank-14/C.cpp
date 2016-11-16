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

vt(vt(int)) adj, c, D;
vt(px(int)) Q;

int bfs(int s, int d) {
  D.resize(sz(adj), vt(int)(1<<(d+1), -1));
  Q.resize(sz(adj)*(1<<(d+1)));
  int fr = 0, bk = 0;
  Q[bk ++] = mp(s, 1);
  D[s][1] = 0;
  vt(int) st(1<<(d+1), 0);
  while (fr < bk) {
    int u = Q[fr].x, m = Q[fr].y;
    fr ++;
    if (D[u][m] == d) {
      st[m] = 1;
      continue;
    }
    rep(i, sz(adj[u])) {
      int v = adj[u][i];
      int t = (m << 1) | c[u][i];
      if (D[v][t] == -1) {
        D[v][t] = D[u][m]+1;
        Q[bk ++] = mp(v, t);
      }
    }
  }
  return accumulate(all(st), 0);
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, d;
  cin >> n >> m >> d;
  adj.resize(n);
  c.resize(n);
  rep(i, m) {
    int u, v, f;
    cin >> u >> v >> f;
    u --, v --;
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u].push_back(f);
    c[v].push_back(f);
  }
  cout << bfs(0, d) << endl;
  return 0;
}
