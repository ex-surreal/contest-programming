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

vector <vector <int> * > tree;
vector <vector <px(int)> > adj;
vector <ll> sub, ans, a;
vt(ll) d;
set <px(ll)> st;
int z;

int dfs(int u) {
  sub[u] = 1;
  repe(t, adj[u]) {
    int v, w;
    tie(v, w) = t;
    d[v] = d[u] + w;
    sub[u] += dfs(v);
  }
  return sub[u];
}

void merge(int u, int x) {
  if (a[x] >= d[x]-d[u]) {
    st.insert(mp(a[x]-d[x], x));
    z ++;
    ans[u] ++;
  }
  tree[u]->push_back(x);
}

void calc(int u, int f) {
  int r = -1;
  repe(t, adj[u]) {
    int v, w;
    tie(v, w) = t;
    if (r == -1 || sub[v] > sub[r]) {
      r = v;
    }
  }
  repe(t, adj[u]) {
    int v, w;
    tie(v, w) = t;
    if (r != v) {
      calc(v, 0);
    }
  }
  if (r != -1) {
    calc(r, 1);
    tree[u] = tree[r];
    st.insert(mp(a[r]-d[r], r));
    z ++;
  }
  tree[u]->push_back(u);
  while (!st.empty() && st.begin()->x < -d[u]) {
    st.erase(st.begin());
    z --;
  }
  ans[u] = z;
  repe(t, adj[u]) {
    int v, w;
    tie(v, w) = t;
    if (r == v) {
      continue;
    }
    repe(x, *tree[v]) {
      merge(u, x);
    }
  }
  if (!f) {
    repe(i, *tree[u]) {
      auto it = st.find(mp(a[i]-d[i], i));
      if (it != st.end()){
        st.erase(it);
        z --;
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  d.resize(n);
  a.resize(n);
  adj.resize(n);
  ans.resize(n);
  sub.resize(n);
  tree.resize(n);
  rep(i, n) {
    tree[i] = new vt(int)();
  }
  repe(&e, a) {
    cin >> e;
  }
  rep(u, n-1) {
    int v, w;
    cin >> v >> w;
    v --;
    adj[v].push_back(mp(u+1, w));
  }
  dfs(0);
  calc(0, 0);
  repe(e, ans) {
    cout << e << " ";
  }
  return 0;
}
