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

vector <vector <int> > adj, D;

void bfs(int s, vector <int> &D) {
  fill(all(D), -1);
  vector <int> Q(sz(adj));
  int fr = 0, bk = 0;
  D[s] = 0;
  Q[bk ++] = s;
  while (fr < bk) {
    int u = Q[fr ++];
    repe(v, adj[u]) {
      if (D[v] == -1) {
        D[v] = D[u] + 1;
        Q[bk ++] = v;
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  D.resize(n, vector <int> (n));
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    adj[u-1].push_back(v-1);
  }
  rep(i, n) {
    bfs(i, D[i]);
  }
  vector <set <pair <int, int> > > row(n), col(n);
  rep(i, n) {
    rep(j, n) {
      if (i == j) {
        continue;
      }
      if (D[i][j] != -1) {
        row[i].insert(mp(-D[i][j], j));
      }
      if (sz(row[i]) > 4) {
        row[i].erase(*row[i].rbegin());
      }
      if (D[j][i] != -1) {
        col[i].insert(mp(-D[j][i], j));
      }
      if (sz(col[i]) > 4) {
        col[i].erase(*col[i].rbegin());
      }
    }
  }
  int ans = -1;
  int u, v, w, x;
  rep(i, n) {
    rep(j, n) {
      if (i == j || D[i][j] == -1) {
        continue;
      }
      repe(c, col[i]) {
        if (c.y == j) {
          continue;
        }
        repe(d, row[j]) {
          if (d.y == i || d.y == c.y) {
            continue;
          }
          int t = D[i][j]-c.x-d.x;
          if (ans < t) {
            ans = t;
            u = c.y, x = d.y;
            v = i, w = j;
          }
        }
      }
    }
  }
  u ++, v ++, w ++, x ++;
  cout << u << " " << v << " " << w << " " << x;
  return 0;
}
