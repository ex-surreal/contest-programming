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

typedef long long ll;
int mod = 1e9+7;
vector <int> df, dl;
int inv2 = 500000004;

void preprocess() {
  df.resize(31);
  dl.resize(31);
  df[0] = df[1] = 1;
  dl[0] = 1;
  dl[1] = 3;
  repi(i, 2, sz(df)) {
    df[i] = 1ll*df[i-1]*dl[i-1] % mod;
    dl[i] = (5ll*df[i-1]%mod*df[i-1]%mod + 1ll*dl[i-1]*dl[i-1] % mod) * inv2 % mod;
  }
}

tuple <int, int> getFL(int n) {
  int l = 1, f = 1;
  n --;
  for (int i = 0; (1<<i) <= n; i ++) {
    if ((n>>i)&1) {
      int t = f;
      f = (1ll*t*dl[i] + 1ll*l*df[i]) % mod * inv2 % mod;
      l = (5ll*t*df[i] + 1ll*l*dl[i]) % mod * inv2 % mod;
    }
  }
  return mp(f, l);
}

vector <int> F, L, f, l;
vector <int> lazyL, lazyF;

void init(int node, int u, int v) {
  if (u == v) {
    F[node] = f[u];
    L[node] = l[u];
    lazyL[node] = lazyF[node] = -1;
    return;
  }
  int ls = (node<<1) | 1, rs = ls + 1, m = (u+v)>>1;
  init(ls, u, m);
  init(rs, m+1, v);
  F[node] = (F[ls]+F[rs]) % mod;
  L[node] = (L[ls]+L[rs]) % mod;
}

void push_down(int node, int ls, int rs, int u, int v) {
  if (lazyF[node] == -1) {
    return;
  }
  int f = F[node], l = L[node];
  F[node] = (1ll*f*lazyL[node] + 1ll*l*lazyF[node]) % mod * inv2 % mod;
  L[node] = (5ll*f%mod*lazyF[node] + 1ll*l*lazyL[node]) % mod * inv2 % mod;
  if (u != v) {
    if (lazyF[ls] == -1) {
      lazyF[ls] = lazyF[rs] = lazyF[node];
      lazyL[ls] = lazyL[rs] = lazyL[node];
    } else {
      f = lazyF[ls], l = lazyL[ls];
      lazyF[ls] = (1ll*f*lazyL[node] + 1ll*l*lazyF[node]) % mod * inv2 % mod;
      lazyL[ls] = (5ll*f%mod*lazyF[node] + 1ll*l*lazyL[node]) % mod * inv2 % mod;
      f = lazyF[rs], l = lazyL[rs];
      lazyF[rs] = (1ll*f*lazyL[node] + 1ll*l*lazyF[node]) % mod * inv2 % mod;
      lazyL[rs] = (5ll*f%mod*lazyF[node] + 1ll*l*lazyL[node]) % mod * inv2 % mod;
    }
  }
  lazyF[node] = lazyL[node] = -1;
}

void update(int node, int u, int v, int x, int y, int f, int l) {
  int ls = (node<<1) | 1, rs = ls + 1, m = (u+v)>>1;
  push_down(node, ls, rs, u, v);
  if (v < x || u > y) {
    return;
  }
  if (x <= u && v <= y) {
    lazyF[node] = f;
    lazyL[node] = l;
    push_down(node, ls, rs, u, v);
    return;
  }
  update(ls, u, m, x, y, f, l);
  update(rs, m+1, v, x, y, f, l);
  F[node] = (F[ls]+F[rs]) % mod;
  L[node] = (L[ls]+L[rs]) % mod;
}

int query(int node, int u, int v, int x, int y) {
  int ls = (node<<1) | 1, rs = ls + 1, m = (u+v)>>1;
  push_down(node, ls, rs, u, v);
  if (v < x || u > y) {
    return 0;
  }
  if (x <= u && v <= y) {
    return F[node];
  }
  int ret = (query(ls, u, m, x, y)+query(rs, m+1, v, x, y)) % mod;
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  preprocess();
  int n, m;
  cin >> n >> m;
  F.resize(4*n);
  L.resize(4*n);
  lazyL.resize(4*n, -1);
  lazyF.resize(4*n, -1);
  rep(i, n) {
    int x;
    cin >> x;
    int a, b;
    tie(a, b) = getFL(x);
    f.push_back(a);
    l.push_back(b);
  }
  init(0, 0, n-1);
  rep(i, m) {
    int t, l, r;
    cin >> t >> l >> r;
    l --, r --;
    if (t == 2) {
      cout << query(0, 0, n-1, l, r) << "\n";
    } else {
      int x;
      cin >> x;
      int a, b;
      tie(a, b) = getFL(x);
      update(0, 0, n-1, l, r, a, b);
    }
  }
  return 0;
}
