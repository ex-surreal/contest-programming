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

vector <int> sub, color, cnt, mx;
vector <long long> sum;
vector <vector <int> * > tree;
vector <vector <int> > adj;

int dfs(int u, int w) {
  sub[u] = 1;
  repe(v, adj[u]) {
    if (v != w) {
      sub[u] += dfs(v, u);
    }
  }
  return sub[u];
}

void merge(int u, int x) {
  tree[u]->push_back(x);
  cnt[color[x]] ++;
  if (cnt[color[x]] > mx[u]) {
    mx[u] = cnt[color[x]];
    sum[u] = color[x]+1;
  } else if (mx[u] == cnt[color[x]]) {
    sum[u] += color[x]+1;
  }
}

void calc(int u, int w, bool f) {
  int r = -1;
  repe(v, adj[u]) {
    if (v == w) {
      continue;
    }
    if (r == -1 || sub[r] < sub[v]) {
      r = v;
    }
  }
  repe(v, adj[u]) {
    if (v != w && v != r) {
      calc(v, u, false);
    }
  }
  if (r != -1) {
    calc(r, u, 1);
    tree[u] = tree[r];
    mx[u] = mx[r];
    sum[u] = sum[r];
  }
  merge(u, u);
  repe(v, adj[u]) {
    if (v == w || v == r) {
      continue;
    }
    repe(x, *tree[v]) {
      merge(u, x);
    }
  }
  if (!f) {
    repe(x, *tree[u]) {
      cnt[color[x]] --;
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  sub = color = mx = cnt = vector <int> (n);
  sum.resize(n);
  tree.resize(n);
  adj.resize(n);
  rep(i, n) {
    tree[i] = new vector <int>();
  }
  repe(&e, color) {
    cin >> e;
    e --;
  }
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  dfs(0, 0);
  calc(0, 0, 0);
  rep(i, n) {
    cout << sum[i] << " ";
  }
  return 0;
}
