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

vector <vector <int> > to, term, adj;
vector <int> link, node;

void init() {
    to.push_back(vector <int>(26, -1));
    link.push_back(-1);
    term.push_back(vector <int>());
}

void add_str(string p, int id) {
    int u = 0;
    repe(c, p) {
        if (to[u][c-'a'] == -1) {
            to[u][c-'a'] = sz(link);
            to.push_back(vector <int>(26, -1));
            link.push_back(-1);
            term.push_back(vector <int>());
        }
        u = to[u][c-'a'];
    }
    node[id] = u;
    term[u].push_back(id);
}

void push_link() {
    vector <int> Q(sz(link));
    int fr = 0, bk = 0;
    Q[bk ++] = 0;
    while (fr < bk) {
        int u = Q[fr ++];
        int j = link[u];
        rep(i, 26) {
            if (to[u][i] == -1) {
                to[u][i] = j == -1 ? 0 : to[j][i];
                continue;
            }
            int v = to[u][i];
            link[v] = j == -1 ? 0 : to[j][i];
            Q[bk ++] = v;
        }
    }
    adj.resize(sz(link));
    repi(i, 1, sz(link)) {
        adj[link[i]].push_back(i);
    }
}

vector <int> seg, lft, rgt, srt;

int add(int pre, int now, int u, int v, int x) {
    if (now == -1) {
        now = sz(seg);
        lft.push_back(pre == -1 ? -1 : lft[pre]);
        rgt.push_back(pre == -1 ? -1 : rgt[pre]);
        seg.push_back(0);
    }
    if (u == v) {
        seg[now] ++;
        return now;
    }
    int m = (u+v)>>1, l = lft[now], r = rgt[now];
    if (x <= m) {
        l = add(lft[now], lft[now], u, m, x);
    } else {
        r = add(lft[now], rgt[now], m+1, v, x);
    }
    lft[now] = l, rgt[now] = r;
    seg[now] = (l == -1 ? 0 : seg[l]) + (r == -1 ? 0 : seg[r]);
    cout << pre << " " << now << " " << u << " " << v << " " << seg[now] << endl;
    return now;
}

void dfs(int u, int w) {
    srt[u] = -1;
    repe(e, term[u]) {
        srt[u] = add(w == -1 ? -1 : srt[w], srt[u], 0, sz(node)-1, e);
    }
    cout << u << " ***" << endl;
    repe(v, adj[u]) {
        dfs(v, u);
    }
}

int query(int now, int u, int v, int x, int y) {
    if (y < u || x > v || now == -1) {
        return 0;
    }
    if (x <= u && v <= y) {
        return seg[now];
    }
    int m = (u+v)>>1;
    return query(lft[now], u, m, x, y)+query(rgt[now], m+1, v, x, y);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    node.resize(n);
    init();
    rep(i, n) {
        string p;
        cin >> p;
        add_str(p, i);
    }
    push_link();
    /* rep(i, sz(link)) { */
    /*     repe(e, term[i]) { */
    /*         cout << e << " "; */
    /*     } cout << endl; */
    /* } */
    srt.resize(sz(link));
    dfs(0, -1);
    rep(i, q) {
        int l, r, k;
        cin >> l >> r >> k;
        l --, r --, k --;
        cout << query(srt[node[k]], 0, n-1, l, r) << "\n";
    }
    return 0;
}
