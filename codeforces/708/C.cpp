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

vector <set <int> > seg;
vector <int> a;

void init(int node, int u, int v) {
    if (u == v) {
        seg[node].insert(a[u]);
        return;
    }
    int ls = node*2+1, rs = ls+1, m = (u+v)>>1;
    init(ls, u, m);
    init(rs, m+1, v);
    seg[node] = seg[ls];
    repe(e, seg[rs]) {
        seg[node].insert(e);
    }
}

bool read(int node, int u, int v, int x, int y, int a) {
    if (y < u || x > v || v < u) {
        return false;
    }
    if (x <= u && v <= y) {
        auto l = seg[node].lower_bound(a);
        if (l == seg[node].end()) {
            return false;
        }
        return true;
    }
    int ls = node*2+1, rs = ls+1, m = (u+v)>>1;
    return read(ls, u, m, x, y, a) || read(rs, m+1, v, x, y, a);
}

vector <int> st, ed, cnt, parent;
vector <vector <int> > adj;
int z;

void dfs(int u, int w) {
    st[u] = z ++;
    cnt[u] = 1;
    parent[u] = w;
    repe(v, adj[u]) {
        if (v != w) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
    ed[u] = z;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    adj.resize(n);
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    st.resize(n);
    ed.resize(n);
    cnt.resize(n);
    seg.resize(4*n+5);
    a.resize(n);
    parent.resize(n);
    z = 0;
    dfs(0, -1);
    rep(i, n) {
        a[st[i]] = cnt[i];
    }
    init(0, 0, n-1);
    rep(u, n) {
        int k = 0, f = -1;
        repe(v, adj[u]) {
            if (v == parent[u]) {
                if (n-cnt[u] > n/2) {
                    k = n - cnt[u] - n/2;
                    f = v;
                }
                continue;
            }
            if (cnt[v] > n/2) {
                k = cnt[v] - n/2;
                f = v;
            }
        }
        cout << " - " << u << " " << f << " " << k << endl;
        bool ans = false;
        if (f == -1) {
            ans = true;
        } else {
            if (f == parent[u]) {
                ans = ans || read(0, 0, n-1, 0, st[f]-1, k);
                ans = ans || read(0, 0, n-1, ed[f]+1, n-1, k);
            } else {
                ans = read(0, 0, n-1, st[f]+1, ed[f], k);
            }
        }
        cout << ans << " ";
    }
    return 0;
}
