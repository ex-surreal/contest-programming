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

vector <int> seg, lft, rgt, srt;

int add(int pre, int u, int v, int x) {
    int now = sz(seg);
    lft.push_back(pre == -1 ? -1 : lft[pre]);
    rgt.push_back(pre == -1 ? -1 : rgt[pre]);
    seg.push_back(0);
    if (u == v) {
        seg[now] = 1;
        return now;
    }
    int m = (u+v)>>1;
    if (x <= m) {
        int t = add(lft[now], u, m, x);
        lft[now] = t;
    } else {
        int t = add(rgt[now], m+1, v, x);
        rgt[now] = t;
    }
    seg[now] = (lft[now] == -1 ? 0 : seg[lft[now]]) + (rgt[now] == -1 ? 0 : seg[rgt[now]]);
    return now;
}

int query(int u, int v, int x, int y, int l, int p, int k) {
    if (u == v) {
        return u;
    }
    int m = (u+v)>>1;
    int lx = (lft[x] == -1 ? 0 : seg[lft[x]]);
    int ly = (lft[y] == -1 ? 0 : seg[lft[y]]);
    int ll = (lft[l] == -1 ? 0 : seg[lft[l]]);
    int lp = (p == -1 || lft[p] == -1 ? 0 : seg[lft[p]]);
    if (lx+ly-ll-lp >= k) {
        return query(u, m, lft[x], lft[y], lft[l], p == -1 ? -1 : lft[p], k);
    } else {
        return query(m+1, v, rgt[x], rgt[y], rgt[l], p == -1 ? -1 : rgt[p], k-(lx+ly-ll-lp));
    }
}

vector <vector <int> > adj, dp;
vector <int> val, depth, num;

void dfs(int u, int w) {
    dp[u][0] = w;
    srt[u] = add(w == -1 ? -1 : srt[w], 0, sz(num)-1, val[u]);
    depth[u] = (w == -1 ? 0 : depth[w] + 1);
    rep(i, sz(adj[u])) {
        int v = adj[u][i];
        if (v != w) {
            dfs(v, u);
        }
    }
}

int lg;

void make(int r) {
    dp.clear();
    int n = sz(adj);
    lg = 31-__builtin_clz(n);
    dp = vector <vector <int> >(n, vector <int> (lg+1, -1));
    srt.resize(n);
    depth.resize(n);
    dfs(r, -1);
    rep(i, n) {
        for (int j = 1; (1<<j) <= n; j ++) {
            dp[i][j] = (dp[i][j-1] == -1 ? -1 : dp[dp[i][j-1]][j-1]);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    for (int l = lg; depth[v] > depth[u]; l --) {
        if (dp[v][l] != -1 && depth[dp[v][l]] >= depth[u]) {
            v = dp[v][l];
        }
    }
    if (u == v) {
        return u;
    }
    for (int l = lg; l >= 0 && u != v; l --) {
        if (dp[u][l] != dp[v][l]) {
            u = dp[u][l];
            v = dp[v][l];
        }
    }
    return dp[u][0];
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> a(n), t;
    map <int, int> id;
    rep(i, n) {
        scanf("%d", &a[i]);
    }
    t = a;
    sort(all(a));
    rep(i, n) {
        if (id.count(a[i]) == 0) {
            id[a[i]] = sz(num);
            num.push_back(a[i]);
        }
    }
    rep(i, n) {
        val.push_back(id[t[i]]);
    }
    adj.resize(n);
    rep(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u --, v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    make(0);
    rep(i, m) {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        u --, v --;
        int l = lca(u, v);
        if (l == -1) {
            continue;
        }
        int p = dp[l][0];
        printf("%d\n", num[query(0, sz(num)-1, srt[u], srt[v], srt[l], p== -1 ? -1 : srt[p], k)]);
    }
    return 0;
}
