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
vt(vt(px(int))) q;
vt(vt(int)*) tree;
vt(int) name, depth, sub, ans;
vector <map <int, int> > cnt;

void dfs(int u, int w) {
  depth[u] = w == -1 ? 0 : depth[w]+1;
  sub[u] = 1;
  repe(v, adj[u]) {
    dfs(v, u);
    sub[u] += sub[v];
  }
}

void merge(int u, int x) {
  tree[u]->push_back(x);
  if (x >= sz(cnt)) {
    cout << "x big" << " " << u << " " << x << endl;
    exit(0);
  }
  cnt[depth[x]][name[x]] ++;
}

void calc(int u, int f) {
  int r = -1;
  repe(v, adj[u]) {
    if (r == -1 || sub[r] < sub[v]) {
      r = v;
    }
  }
  repe(v, adj[u]) {
    if (v != r) {
      calc(v, 0);
    }
  }
  if (r != -1) {
    calc(r, 1);
    tree[u] = tree[r];
  }
  merge(u, u);
  repe(v, adj[u]) {
    if (v != r) {
      repe(x, *tree[v]) {
        merge(u, x);
      }
    }
  }
  repe(v, q[u]) {
    ans[v.y] = depth[u]+v.x < sz(cnt) ? sz(cnt[depth[u]+v.x]) : 0;
  }
  if (!f) {
    repe(x, *tree[u]) {
      cnt[depth[x]][name[x]] --;
      if (!cnt[depth[x]][name[x]]) {
        cnt[depth[x]].erase(name[x]);
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  adj.resize(n);
  q.resize(n);
  tree.resize(n, new vt(int));
  cnt.resize(n);
  depth = name = sub = vt(int)(n);
  map <string, int> id;
  int c = 0;
  vt(int) r;
  rep(i, n) {
    string p;
    int q;
    cin >> p >> q;
    if (id.find(p) == id.end()) {
      id[p] = c ++;;
    }
    name[i] = id[p];
    if (q == 0) {
      r.push_back(i);
    } else {
      adj[q-1].push_back(i);
    }
  }
  int m;
  cin >> m;
  ans.resize(m);
  rep(i, m) {
    int v, k;
    cin >> v >> k;
    q[v-1].push_back(mp(k, i));
  }
  repe(x, r) {
    dfs(x, -1);
  }
  repe(x, r) {
    calc(x, 0);
  }
  repe(e, ans) {
    cout << e << "\n";
  }
  return 0;
}
