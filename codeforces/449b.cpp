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

vt(vt(px(int))) adj;

void djk(vt(ll) &D, vt(bool) &f) {
  set <pxy(ll, int)> Q;
  D[0] = 0;
  Q.insert(mp(D[0], 0));
  rep(i, sz(adj)) {
    if (f[i]) {
      Q.insert(mp(D[i], i));
    }
  }
  while (!Q.empty()) {
    int u = Q.begin()->y;
    Q.erase(Q.begin());
    repe(x, adj[u]) {
      int v, w;
      tie(v, w) = x;
      if (D[v] >= D[u]+w) {
        Q.erase(mp(D[v], v));
        D[v] = D[u]+w;
        f[v] = false;
        Q.insert(mp(D[v], v));
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  adj.resize(n);
  vt(ll) D(n, LLONG_MAX/3);
  vt(bool) f(n);
  rep(i, m) {
    int u, v, x;
    cin >> u >> v >> x;
    adj[u-1].push_back(mp(v-1, x));
    adj[v-1].push_back(mp(u-1, x));
  }
  rep(i, k) {
    int s, x;
    cin >> s >> x;
    D[s-1] = min(D[s-1], 1ll*x);
    f[s-1] = true;
  }
  djk(D, f);
  cout << k - accumulate(all(f), 0);
  return 0;
}
