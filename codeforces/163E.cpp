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

vector <vector <int> > to, adj;
vector <int> link, term, term_node;

void init() {
    to.push_back(vector <int>(26, -1));
    term.push_back(-1);
    link.push_back(-1);
}

void add_str(string p) {
    int u = 0;
    for (int i = 0; i < int(p.size()); i ++) {
        if (to[u][p[i]-'a'] == -1) {
            to[u][p[i]-'a'] = link.size();
            to.push_back(vector <int>(26, -1));
            term.push_back(-1);
            link.push_back(-1);
        }
        u = to[u][p[i]-'a'];
    }
    term[u] = sz(term_node);
    term_node.push_back(u);
}

void push_link() {
    vector <int> Q(link.size());
    int fr = 0, bk = 0;
    Q[bk ++] = 0;
    while (fr < bk) {
        int u = Q[fr ++];
        int j = link[u];
        rep(c, sz(to[u])) {
            int v = to[u][c];
            if (v == -1) {
                to[u][c] = j == -1 ? 0 : to[j][c];
                continue;
            }
            link[v] = j == -1 ? 0 : to[j][c];
            Q[bk ++] = v;
        }
    }
}

int z;
vector <int> pre, post, tree;

void dfs(int u) {
    pre[u] = ++ z;
    repe(v, adj[u]) {
        dfs(v);
    }
    post[u] = z;
}

void update(int id, int v) {
    while (id < sz(tree)) {
        tree[id] += v;
        id += id&-id;
    }
}

int read(int id) {
    int ret = 0;
    while (id > 0) {
        ret += tree[id];
        id -= id&-id;
    }
    return ret;
}

void init_bit() {
    adj.resize(sz(link));
    repi(i, 1, sz(link)) {
        adj[link[i]].push_back(i);
    }
    pre.resize(sz(link));
    post.resize(sz(link));
    dfs(0);
    tree.resize(sz(link)+1);
    rep(i, sz(term_node)) {
        update(pre[term_node[i]], 1);
        update(post[term_node[i]]+1, -1);
    }
}

int count_words(string p) {
    int ret = 0, u = 0;
    repe(c, p) {
        u = to[u][c-'a'];
        ret += read(pre[u]);
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    init();
    rep(i, k) {
        string p;
        cin >> p;
        add_str(p);
    }
    push_link();
    init_bit();
    vector <int> cnt(k, 1);
    rep(i, n) {
        string buf;
        cin >> buf;
        if (buf[0] == '?') {
            cout << count_words(buf.substr(1)) << "\n";
        } else {
            int id = stoi(buf.substr(1))-1;
            if (cnt[id] == 0 && buf[0] == '+') {
                update(pre[term_node[id]], +1);
                update(post[term_node[id]]+1, -1);
                cnt[id] ++;
            } else if (cnt[id] == 1 && buf[0] == '-') {
                update(pre[term_node[id]], -1);
                update(post[term_node[id]]+1, +1);
                cnt[id] --;
            }
        }
    }
    return 0;
}
