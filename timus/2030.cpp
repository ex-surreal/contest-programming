#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>

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

int order[100005];
int lft[100005];
int rgt[100005];
vector <vector <int> > adj;
int z = 0;
int parent[100005];

void dfs(int u, int w) {
    parent[u] = w;
    lft[u] = z;
    repe(v, adj[u]) {
        if (v != w) {
            order[v] = z++;
        }
    }
    rgt[u] = z-1;
    repe(v, adj[u]) {
        if (v != w) {
            dfs(v, u);
        }
    }
}

int tree[100005];
int mod = 1e9+7;

void update(int id, int val) {
    while (id < 100005) {
        tree[id] += val;
        if (tree[id] >= mod) {
            tree[id] -= mod;
        }
        id += id&-id;
    }
}

int read(int id) {
    int ret = 0;
    while (id > 0) {
        ret += tree[id];
        if (ret >= mod) {
            ret -= mod;
        }
        id -= id&-id;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a(n);
    repe(&x, a) {
        cin >> x;
    }
    adj.resize(n);
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    z = 1;
    order[0] = z ++;
    dfs(0, 0);
    vector <int> b(n+1);
    rep(i, n) {
        b[order[i]] = a[i];
    }
    rep(i, n) {
        update(i+1, (b[i+1]-b[i]+mod)%mod);
    }
    int q;
    cin >> q;
    rep(i, q) {
        int t, v;
        cin >> t >> v;
        v --;
        int x = read(order[v]);
        if (t == 1) {
            update(lft[v], x);
            update(rgt[v]+1, (mod-x)%mod);
            if (parent[v] != v) {
                update(order[parent[v]], x);
                update(order[parent[v]]+1, (mod-x)%mod);
            }
        } else {
            cout << x << "\n";
        }
    }
    return 0;
}
