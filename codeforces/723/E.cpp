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

vector <int> L, pre, to, dir;

void init(int n) {
  L = vector <int> (n, -1);
  pre.clear();
  dir.clear();
  to.clear();
}

void add(int u, int v) {
  to.push_back(v);
  pre.push_back(L[u]);
  dir.push_back(-1);
  L[u] = to.size()-1;
}

void add_edge(int u, int v) {
  add(u, v);
  add(v, u);
}

vector <bool> seen;

void eular(int u) {
  for (int e = L[u]; ~e; e = pre[e]) {
    if (dir[e] != -1) {
      continue;
    }
    dir[e] = 1;
    dir[e^1] = 0;
    eular(to[e]);
  }
  seen[u] = true;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst;
  cin >> tst;
  while (tst --) {
    int n, m;
    cin >> n >> m;
    seen.clear();
    seen.resize(n, false);
    init(n+1);
    vector <int> d(n);
    rep(i, m) {
      int u, v;
      cin >> u >> v;
      add_edge(u-1, v-1);
      d[u-1] ++, d[v-1] ++;
    }
    int ans = 0;
    rep(i, n) {
      if (d[i]&1) {
        add_edge(n, i);
      } else {
        ans ++;
      }
    }
    rep(i, n) {
      if (seen[i]) {
        continue;
      }
      eular(i);
    }
    cout << ans << "\n";
    for (int i = 0; i < 2*m; i += 2) {
      if (dir[i] == 1) {
        cout << to[i^1]+1 << " " << to[i]+1 << "\n";
      } else {
        cout << to[i]+1 << " " << to[i^1]+1 << "\n";
      }
    }
  }
  return 0;
}
