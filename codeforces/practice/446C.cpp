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

int A = 276601605;
int Y[] = {691504013, 308495997};
vector <int> lazy[2], sum[2], X[2];
vector <int> seg, a;
int mod = 1e9+9;

void init(int node, int u, int v) {
    if (u > v) {
        return;
    }
    if (u == v) {
        seg[node] = a[u];
        return;
    }
    int ls = (node<<1) | 1, rs = ls + 1, m = (u+v)>>1;
    init(ls, u, m);
    init(rs, m+1, v);
    seg[node] = (seg[ls]+seg[rs]) % mod;
}

void push_down(int node, int ls, int rs, int u, int m, int v) {
    seg[node] += 1ll*lazy[0][node]*sum[0][v-u]%mod;
    seg[node] %= mod;
    seg[node] += mod -1ll*lazy[1][node]*sum[1][v-u]%mod;
    seg[node] %= mod;
    rep(i, 2)  {
        if (u != v) {
            lazy[i][ls] = (lazy[i][ls]+lazy[i][node]) % mod;
            lazy[i][rs] = (lazy[i][rs]+1ll*X[i][m+1-u]*lazy[i][node]) % mod;
        }
        lazy[i][node] = 0;
    }
}

void update(int node, int u, int v, int x, int y) {
    int ls = (node<<1) | 1, rs = ls + 1, m = (u+v)>>1;
    push_down(node, ls, rs, u, m, v);
    if (v < x || u > y) {
        return;
    }
    if (x <= u && v <= y) {
        seg[node] += 1ll*A*sum[0][v-u]%mod*X[0][u-x+1]%mod;
        seg[node] %= mod;
        seg[node] += mod-1ll*A*sum[1][v-u]%mod*X[1][u-x+1]%mod;
        seg[node] %= mod;
        if (u != v) {
            rep(i, 2) {
                lazy[i][ls] = (lazy[i][ls]+1ll*A*X[i][u-x+1]) % mod;
                lazy[i][rs] = (lazy[i][rs]+1ll*A*X[i][m-x+2]) % mod;
            }
        }
        return;
    }
    update(ls, u, m, x, y);
    update(rs, m+1, v, x, y);
    seg[node] = (seg[ls]+seg[rs]) % mod;
}

int query(int node, int u, int v, int x, int y) {
    int ls = (node<<1) | 1, rs = ls + 1, m = (u+v)>>1;
    push_down(node, ls, rs, u, m, v);
    if (v < x || u > y) {
        return 0;
    }
    if (x <= u && v <= y) {
        return seg[node];
    }
    return (query(ls, u, m, x, y)+query(rs, m+1, v, x, y)) % mod;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    seg.resize(n*4+5);
    a.resize(n+1);
    repi(i, 1, n+1) {
        cin >> a[i];
    }
    init(0, 1, n);
    rep(i, 2) {
        X[i].resize(n+5);
        sum[i].resize(n+5);
        lazy[i].resize(n*4+5);
        X[i][0] = 1;
        sum[i][0] = 1;
        repi(j, 1, sz(X[i])) {
            X[i][j] = 1ll*X[i][j-1]*Y[i] % mod;
            sum[i][j] = (sum[i][j-1] + X[i][j]) % mod;
        }
    }
    rep(i, m) {
        int o, l, r;
        cin >> o >> l >> r;
        if (o == 1) {
            update(0, 1, n, l, r);
        } else {
            cout << query(0, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
