#include <vector>
#include <algorithm>

using namespace std;

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

/**
 * @param int root(0)
 * @param int start(0)
 * starting index for the chain order
 * ex. for BIT it should be 1
 * */
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
