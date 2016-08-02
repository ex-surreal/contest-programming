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
#define repg(e, u) for (int e = last[u]; e != -1; e = pre[e])

int last[100005], pre[200005], nxt[200005], to[200005], num_edges;

void init(int n) {
    fill(last, last+n, -1);
    fill(nxt, nxt+2*n, -1);
    num_edges = 0;
}

void add_edge(int u, int v) {
    to[num_edges] = v;
    pre[num_edges] = last[u];
    if (last[u] != -1) {
        nxt[last[u]] = num_edges;
    }
    last[u] = num_edges ++;
}

void add(int u, int v) {
    add_edge(u, v);
    add_edge(v, u);
}

int cnt[100005];

int get_centroid(int u, int w, int n) {
    cnt[u] = 1;
    bool can = true;
    repg(e, u) {
        int v = to[e];
        if (v != w) {
            int c = get_centroid(v, u, n);
            if (c != -1) {
                return c;
            }
            cnt[u] += cnt[v];
            can = can && (cnt[v] <= n/2);
        }
    }
    if (can) {
        if (u == w) {
            return u;
        } else {
            int cw = n-cnt[u];
            if (cw <= n/2) {
                cnt[w] = n-cnt[u];
                return u;
            }
        }
    }
    return -1;
}

long long ans[100005];
int color[100005];

int go(int u, int w, int c, int num) {
    ans[u] += num;
    int ret = 1;
    if (c == color[u]) {
        return ret;
    }
    repg(e, u) {
        int v = to[e];
        if (v != w) {
            ret += go(v, u, c, num);
        }
    }
    return ret;
}

void update(int c, int n) {
    int r = 0;
    repg(e, c) {
        r += go(to[e], c, color[c], n-cnt[to[e]]);
    }
    ans[c] += r;
}

void cut_edge(int e) {
    int u = to[e^1];
    if (nxt[e] == -1) {
        last[u] = pre[e];
    } else {
        pre[nxt[e]] = pre[e];
    }
}

void compute(int u, int n) {
    int c = get_centroid(u, u, n);
    update(c, n);
    repg(e, c) {
        last[c] = pre[e];
        cut_edge(e^1);
        compute(to[e], cnt[to[e]]);
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    init(n);
    rep(i, n) {
        cin >> color[i];
    }
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        add(u-1, v-1);
    }
    compute(0, n);
    rep(i, n) {
        cout << ans[i] << " ";
    }
    return 0;
}
