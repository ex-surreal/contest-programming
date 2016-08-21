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

vector <long long> seg[2];
vector <int> ring_weight, ring_id;

void init(int n) {
    rep(i, 2) {
        seg[i].resize(4*n+3);
    }
}

void make(int node, int u, int v) {
    if (u == v) {
        seg[0][node] = seg[1][node] = ring_weight[u];
        return;
    }
    int ls = (node<<1)|1, rs = ls+1, m = (u+v)>>1;
    make(ls, u, m);
    make(rs, m+1, v);
    seg[0][node] = seg[0][ls] + seg[0][rs];
    seg[1][node] = min(seg[1][ls], seg[1][rs]);
}

tuple <long long, int> read(int node, int u, int v, int x, int y) {
    if (x > v || y < u) {
        return mp(0, 1<<30);
    }
    if (x <= u && v <= y) {
        return mp(seg[0][node], seg[1][node]);
    }
    int ls = (node<<1)|1, rs = ls+1, m = (u+v)>>1;
    long long lx, rx;
    int ly, ry;
    tie(lx, ly) = read(ls, u, m, x, y);
    tie(rx, ry) = read(rs, m+1, v, x, y);
    return mp(lx+rx, min(ly, ry));
}

vector <int> seen;
vector <int> ring_nodes;
vector <int> f, w;
vector <vector <int> > r, g;

int dfs(int u, int c) {
    seen[u] = c;
    if (seen[f[u]] == c) {
        ring_id[u] = sz(ring_nodes);
        ring_nodes.push_back(u);
        return (u == f[u] ? -1 : f[u]);
    }
    if (seen[f[u]] != -1) {
        return -1;
    }
    int t = dfs(f[u], c);
    if (t != -1) {
        ring_id[u] = sz(ring_nodes);
        ring_nodes.push_back(u);
    }
    return (t == u ? -1: t);
}

vector <tuple <long long, int> > ans;
vector <int> M, D;
vector <long long> W;

tuple<long long, int> get_ans(int id, long long h) {
    long long x = 0;
    int y = 1<<30;
    if (h >= sz(ring_nodes)) {
        x = h/sz(ring_nodes)*seg[0][0];
        y = seg[1][0];
    }
    h %= sz(ring_nodes);
    if (h <= 0) {
        return mp(x, y);
    }
    int jd = (id+h-1+sz(ring_nodes)) % sz(ring_nodes);
    if (jd < id) {
        long long tx;
        int ty;
        tie(tx, ty) = read(0, 0, sz(ring_nodes)-1, id, sz(ring_nodes)-1);
        x += tx;
        y = min(y, ty);
        tie(tx, ty) = read(0, 0, sz(ring_nodes)-1, 0, jd);
        x += tx;
        y = min(y, ty);
    } else {
        long long tx;
        int ty;
        tie(tx, ty) = read(0, 0, sz(ring_nodes)-1, id, jd);
        x += tx;
        y = min(y, ty);
    }
    return mp(x, y);
}

long long k;
vector <int> Q, to;
long long dp[3][20][100005];

void bfs() {
    int fr = 0, bk = 0;
    rep(i, sz(ring_nodes)) {
        M[ring_nodes[i]] = 1<<30;
        W[ring_nodes[i]] = 0;
        D[ring_nodes[i]] = 0;
        Q[bk ++] = ring_nodes[i];
        while (fr < bk) {
            int u = Q[fr ++];
            if (D[u] < k) {
                long long x;
                int y;
                tie(x, y) = get_ans(i, k-D[u]);
                x += W[u];
                y = min(y, M[u]);
                ans[u] = mp(x, y); 
            } else {
                to.push_back(u);
            }
            rep(j, sz(r[u])) {
                int v = r[u][j];
                if (ring_id[v] != -1) {
                    continue;
                }
                D[v] = D[u]+1;
                W[v] = W[u]+g[u][j];
                M[v] = min(M[u], g[u][j]);
                Q[bk ++] = v;
                dp[0][0][v] = u;
                dp[1][0][v] = g[u][j];
                dp[2][0][v] = g[u][j];
            }
        }
    }
}

void solve(int u) {
    ring_nodes.clear();
    dfs(u, u);
    if (sz(ring_nodes) == 0) {
        return;
    }
    reverse(all(ring_nodes));
    ring_weight.clear();
    repe(e, ring_nodes) {
        ring_weight.push_back(w[e]);
    }
    init(sz(ring_nodes));
    make(0, 0, sz(ring_nodes)-1);
    bfs();
}

tuple <long long, int> get(int u, int k, int l) {
    long long x = 0;
    int y = 1<<30;
    for (int i = l; i >= 0; i --) {
        if (dp[0][i][u] == -1 || k < (1<<i)) {
            continue;
        }
        x += dp[1][i][u];
        y = min(dp[2][i][u], 1ll*y);
        u = dp[0][i][u];
        k -= 1<<i;
    }
    return mp(x, y);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    seen.resize(n, -1);
    f.resize(n);
    w.resize(n);
    r.resize(n);
    g.resize(n);
    M.resize(n);
    W.resize(n);
    D.resize(n);
    Q.resize(n);
    ans.resize(n);
    ring_id.resize(n, -1);
    rep(i, n) {
        cin >> f[i];
    }
    rep(i, n) {
        cin >> w[i];
    }
    rep(i, n) {
        r[f[i]].push_back(i);
        g[f[i]].push_back(w[i]);
    }
    mem(dp, -1);
    rep(i, n) {
        if (seen[i] == -1) {
            solve(i);
        }
    }
    if (sz(to)) {
        for (int i = 1; (1<<i) <= n; i ++) {
            rep(j, n) {
                int t = dp[0][i-1][j];
                if (t != -1) {
                    dp[0][i][j] = dp[0][i-1][t];
                    dp[1][i][j] = dp[1][i-1][j]+dp[1][i-1][t];
                    dp[2][i][j] = min(dp[2][i-1][j], dp[2][i-1][t]);
                }
            }
        }
        int l = 31-__builtin_clz(k);
        repe(e, to) {
            ans[e] = get(e, k, l);
        }
    }
    repe(a, ans) {
        long long x;
        int y;
        tie(x, y) = a;
        cout << x << " " << y << "\n";
    }
    return 0;
}
