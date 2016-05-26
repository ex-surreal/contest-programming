#include <iostream>
#include <string>
#include <vector>

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

#include<algorithm>

namespace dinic {
    const int N = 55005, M = 320000, inf = (1 << 30);
    int L[N], pre[M], to[M], ptr[N], cap[M], flow[M], cnt = 0;
    int n, s, t;

    void init(int _s, int _t, int _n) {
        s = _s;
        t = _t;
        n = _n;
        std::fill(L, L + n, -1);
        cnt = 0;
    }

    inline void add(int u, int v, int c = 1) {
        to[cnt] = v;
        pre[cnt] = L[u];
        cap[cnt] = c;
        flow[cnt] = 0;
        L[u] = cnt++;
    }

    inline void add_edge(int u, int v, int c = 1) {
        add(u, v, c);
        add(v, u, 0);
    }

    int Q[N], level[N];

    bool bfs() {
        int fr = 0, bk = 0;
        std::fill(level, level + n, -1);
        level[s] = 0;
        Q[bk++] = s;
        while (fr < bk) {
            int u = Q[fr++];
            for (int e = L[u]; e != -1; e = pre[e]) {
                if (flow[e] < cap[e]) {
                    int v = to[e];
                    if (level[v] == -1) {
                        level[v] = level[u] + 1;
                        Q[bk++] = v;
                    }

                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int f) {
        if (u == t || f == 0) {
            return f;
        }
        for (int & e = ptr[u]; e != -1; e = pre[e]) {
            int v = to[e];
            if (flow[e] < cap[e] && level[v] == level[u] + 1) {
                int pushed = dfs(v, std::min(f, cap[e] - flow[e]));
                if (pushed > 0) {
                    flow[e] += pushed;
                    flow[e ^ 1] -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow() {
        int ret = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                ptr[i] = L[i];
            }
            while (int f = dfs(s, inf)) {
                ret += f;
            }
        }
        return ret;
    }
}

using namespace dinic;

int main () {
    std::ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector <string> B(m);
    repe(&x, B) {
        cin >> x;
    }
    int s = n+m, t = s+1;
    init(s, t, t+1);
    rep(i, m) {
        rep(j, n) {
            if (B[i][j] == '1') {
                add_edge(i, j+m, 1);

            }
        }
    }
    rep(i, m) {
        add_edge(s, i, 1);
    }
    rep(j, n) {
        add_edge(j+m, t, 1);
    }
    int f = max_flow();
    vector <string> ans(m, string(n, '1'));
    if (f < m) {
        rep(i, m) {
            cout << ans[i] << "\n";
        }
        return 0;
    }
    vector <int> match(m+n, -1);
    rep(i, m) {
        for (int e = L[i]; e != -1; e = pre[e]) {
            if (flow[e] == 1) {
                match[i] = to[e];
                match[to[e]] = i;
            }
        }
    }
    rep(i, m) {
        for (int e = L[i]; e != -1; e = pre[e]) {
            int j = to[e] - m;
            if (B[i][j] == '1' && flow[e] == 1) {
                int z = match[i] - m;
                int w = match[j+m];
                if (B[w][z] == '1') {
                    ans[i][j] = '0';
                }
            }
        }
    }
    rep(i, m) {
        cout << ans[i] << "\n";
    }
    return 0;
}
