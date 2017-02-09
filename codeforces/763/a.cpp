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

vt(int) lst, to, pre, c, K;
int T;

void init(int n) {
  lst = vt(int)(n, -1);
}

void add(int u, int v, int t) {
  c.push_back(t);
  to.push_back(v);
  pre.push_back(lst[u]);
  K.push_back(0);
  lst[u] = sz(pre) - 1;
}

int calc(int u, int w) {
  int ret = 0;
  for (int e = lst[u]; e != -1; e = pre[e]) {
    int v = to[e];
    if (v == w) {
      continue;
    }
    int t = calc(v, u);
    ret += t + c[e];
    K[e] = t;
    K[e^1] = T-t-c[e];
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vt(int) u(n-1), v(n-1), col(n);
  rep(i, n-1) {
    cin >> u[i] >> v[i];
  }
  repe(&e, col) {
    cin >> e;
  }
  init(n);
  T = 0;
  rep(i, n-1) {
    u[i] --, v[i] --;
    int t = col[u[i]] != col[v[i]];
    T += t;
    add(u[i], v[i], t);
    add(v[i], u[i], t);
  }
  calc(0, -1);
  rep(i, n) {
    int t = 0;
    for (int e = lst[i]; e != -1; e = pre[e]) {
      t |= K[e];
    }
    if (!t) {
      cout << "YES\n";
      cout << i+1;
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
