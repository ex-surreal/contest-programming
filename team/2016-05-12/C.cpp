#include <bits/stdc++.h>

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

namespace heavy_light_decomposition {
    const int N = 100006;
    int parent[N];
    int depth[N];
    int sub[N];
    /**
     * @var int [] order
     * serial order of a heavy chain
     * -1 for a chain with length 0
     * */
    int order[N];
    /**
     * @var int [] skip
     * head node of a heavy chain
     * */
    int skip[N];
    /**
     * @var int counter
     * total number of nodes in non-zero length chains
     * */
    int counter;
    vector<vector <int> > adj;

    int dfs(int u, int w) {
        parent[u] = w;
        sub[u] = 1;
        depth[u] = depth[w]+1;
        for (int i = 0; i < (int)adj[u].size(); i ++) {
            int v = adj[u][i];
            if(v != w) {
                sub[u] += dfs(v,u);
            }
        }
        return sub[u];
    }
    
    bool is_light(int v, int c) {
        return sub[c]*2 < sub[v];
    }
 
    void go(int u, int w) {
        order[u] = counter ++;
        for (int i = 0; i < int(adj[u].size()); i ++) {
            int v = adj[u][i];
            if(v != w && !is_light(u, v)) {
                go(v, u);
            }
        }
    }

    void order_nodes(int u, int w, bool light = true) {
        skip[u] = (light ? u : skip[w]);
        for (int i = 0; i < (int)adj[u].size(); i ++) {
            int v = adj[u][i];
            if (v == w) {
                continue;
            }
            if(order[u] == -1 && !is_light(u, v)) {
                order[u] = counter ++;
                go(v, u);
            }
            order_nodes(v, u, is_light(u, v));
        }
    }

    void decompose(int root = 0, int start = 0) {
        depth[root] = 0;
        dfs(root, root);
        counter = start;
        fill(order, order+adj.size(), -1);
        order_nodes(root, root);
    }

    int lca(int u, int v) {
        while(skip[u] != skip[v]) {
            if(depth[skip[u]] < depth[skip[v]]) {
                v = parent[skip[v]];
            } else {
                u = parent[skip[u]];
            }
        }
        return (depth[u] < depth[v] ? u : v);
    }
};

namespace point_update {
    #define invalid (INT_MIN/3)
    #define fun(a,b) max(a,b)
    typedef int type;
    const int N = 100000;
    type seg[4*N+5];
    std::vector <type> a;
     
    void init(int node, int u, int v) {
        if(u > v) {
            return;
        }
        if(u == v) {
            seg[node] = a[u];
            return;
        }
        init(2*node+1, u, (u+v)/2);
        init(2*node+2, (u+v)/2+1, v);
        seg[node] = fun(seg[2*node+1], seg[2*node+2]);
    }

    void init(vector <type> &d) {
        a = d;
        init(0, 0, int(a.size()-1));
    }
     
    void update(int node, int u, int v, int x, type val) {
        if(v < x || u > x){
            return;
        }
        if(u == v) {
            seg[node] = val;
            return;
        }
        update(2*node+1, u, (u+v)/2, x, val);
        update(2*node+2, (u+v)/2+1, v, x, val);
        seg[node] = fun(seg[node*2+1], seg[node*2+2]);
    }

    void update(int x, type val) {
        update(0, 0, int(a.size()), x, val);
    }
 
    type read(int node, int u, int v, int x, int y) {
        if (x > y || v < x || u > y) {
            return invalid;
        }
        if(x <= u && v <= y) {
            return seg[node];
        }
        type a = read(2*node+1, u, (u+v)/2, x, y);
        type b = read(2*node+2, (u+v)/2+1 ,v, x, y);
        return fun(a,b);
    }

    type read(int u, int v) {
        return read(0, 0, int(a.size())-1, u, v);
    }
}

using namespace point_update;
using namespace heavy_light_decomposition;

int radio[100005];
 
int get_max(int l, int v) {
    int ret = radio[l];
    while(l != v) {
        int w = (depth[skip[v]] < depth[l] ? l : skip[v]);
        if(w != v) {
            ret = max(ret, read(0, 0, counter, order[w], order[v]));
            v = w;
        } else {
            ret = max(radio[v], ret);
            v = parent[v];
        }
    }
    return ret;
}
 
void query(string o, int u, int v) {
    if(o == "G") {
        u --, v --;
        int l = lca(u,v);
        int ans= max(get_max(l, u), get_max(l, v));
        cout << ans << "\n";
    } else {
        u --;
        radio[u] += v;
        if(order[u] != -1) {
            update(0, 0, counter, order[u], radio[u]);
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    adj.resize(n);
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    decompose(0, 0);
    int q;
    cin >> q;
    rep(i, q) {
        string o;
        int u, v;
        cin >> o >> u >> v;
        query(o, u, v);
    }
    return 0;
}
