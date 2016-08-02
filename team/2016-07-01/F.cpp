#include <iostream>
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

int mod = 10007;
vector <int> seg[3], lazy[3];

int sum(int a, int b) {
    return (1ll*b*(b+1)/2 - 1ll*a*(a-1)/2)%mod;
}

int sq_sum(int a, int b) {
    return (1ll*b*(b+1)*(2*b+1)/6 - 1ll*a*(a-1)*(2*a-1)/6) % mod;
}

int get_sum(int i, int a, int b) {
    if (i == 0) {
        return sq_sum(a, b);
    } else if (i == 1) {
        return sum(a, b);
    } else {
        return (b-a+1)%mod;
    }
}

void update(int node, int u, int v, int x, int y, vector <int> &a) {
    int ls = (node<<1) + 1, rs = (node<<1) + 2;
    if (lazy[0][node] || lazy[1][node] || lazy[2][node]) {
        rep(i, 3) {
            seg[i][node] = (seg[i][node] + lazy[i][node]*get_sum(i, u, v)) % mod;
        }
        if (u != v) {
            rep(i, 3) {
                lazy[i][ls] = (lazy[i][ls] + lazy[i][node]) % mod;
                lazy[i][rs] = (lazy[i][rs] + lazy[i][node]) % mod;
            }
        }
        rep(i, 3) {
            lazy[i][node] = 0;
        }
    }
    if (x > v || y < u) {
        return;
    }
    if (x <= u && v <= y) {
        rep(i, 3) {
            seg[i][node] = (seg[i][node] + a[i]*get_sum(i, u, v)) % mod;
        }
        if (u != v) {
            rep(i, 3) {
                lazy[i][ls] = (lazy[i][ls] + a[i]) % mod;
                lazy[i][rs] = (lazy[i][rs] + a[i]) % mod;
            }
        }
        return;
    }
    update(ls, u, (u+v)>>1, x, y, a);
    update(rs, ((u+v)>>1)+1, v, x, y, a);
    rep(i, 3) {
        seg[i][node] = (seg[i][rs]+seg[i][ls])%mod;
    }
}

int query(int node, int u, int v, int x, int y) {
    int ls = (node<<1) + 1, rs = (node<<1) + 2;
    if (lazy[0][node] || lazy[1][node] || lazy[2][node]) {
        rep(i, 3) {
            seg[i][node] = (seg[i][node] + lazy[i][node]*get_sum(i, u, v)) % mod;
        }
        if (u != v) {
            rep(i, 3) {
                lazy[i][ls] = (lazy[i][ls] + lazy[i][node]) % mod;
                lazy[i][rs] = (lazy[i][rs] + lazy[i][node]) % mod;
            }
        }
        rep(i, 3) {
            lazy[i][node] = 0;
        }
    }
    if (x > v || y < u) {
        return 0;
    }
    if (x <= u && v <= y) {
        return (seg[0][node]+seg[1][node]+seg[2][node])%mod;
    }
    int p = query(ls, u, (u+v)>>1, x, y);
    int q = query(rs, ((u+v)>>1)+1, v, x, y);
    return (p+q)%mod;
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 3) {
        seg[i].resize(4*n);
        lazy[i].resize(4*n);
    }
    rep(i, m) {
        int o, l, r;
        scanf("%d%d%d", &o, &l, &r);
        if (o == 0) {
            vector <int> a(3);
            rep(i, 3) {
                scanf("%d", &a[i]);
            }
            update(0, 0, n-1, l, r, a);
        } else {
            printf("%d\n", query(0, 0, n-1, l, r));
        }
    }
    return 0;
}
