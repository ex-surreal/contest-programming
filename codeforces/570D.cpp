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

vector <vector <int> * > tree;
vector <vector <int> > adj, q, id;
vector <int> c, d, sub, h, ans;

int dfs(int u) {
  sub[u] = 1;
  repe(v, adj[u]) {
    d[v] = d[u] + 1;
    sub[u] += dfs(v);
  }
  return sub[u];
}

void merge(int u, int x) {
  h[d[x]] ^= c[x];
  tree[u]->push_back(x);
}

void calc(int u, int f) {
  int r = -1;
  repe(v, adj[u]) {
    if (r == -1 || sub[v] > sub[r]) {
      r = v;
    }
  }
  repe(v, adj[u]) {
    if (r != v) {
      calc(v, 0);
    }
  }
  if (r != -1) {
    calc(r, 1);
    tree[u] = tree[r];
  }
  merge(u, u);
  repe(v, adj[u]) {
    if (r == v) {
      continue;
    }
    repe(x, *tree[v]) {
      merge(u, x);
    }
  }
  rep(i, sz(q[u])) {
    ans[id[u][i]] = h[q[u][i]] - (h[q[u][i]]&-h[q[u][i]]);
  }
  if (!f) {
    repe(i, *tree[u]) {
      h[d[i]] ^= c[i];
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  tree.resize(n);
  rep(i, n) {
    tree[i] = new vector <int> ();
  }
  adj.resize(n);
  repi(i, 1, n) {
    int p;
    cin >> p;
    adj[p-1].push_back(i);
  }
  d = c = sub = h = vector <int> (n);
  ans.resize(m);
  q.resize(n);
  id.resize(n);
  string t;
  cin >> t;
  rep(i, n) {
    c[i] = 1 << (t[i]-'a');
  }
  rep(i, m) {
    int u, x;
    cin >> u >> x;
    q[u-1].push_back(x-1);
    id[u-1].push_back(i);
  }
  dfs(0);
  calc(0, 0);
  repe(e, ans) {
    cout << (!e ? "Yes" : "No") << "\n";
  }
  return 0;
}
