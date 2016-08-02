#include <iostream>
#include <cstdio>
#include <vector>
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


#include <algorithm>
#include <queue>
#include <iostream>

namespace min_cost_max_flow {
    typedef int flow_type;
    typedef int cost_type;
    const int N = 1000, M = 50000, inf = (1<<30);
    int L[N], pre[M], to[M], cnt;
    flow_type C[M];
    cost_type cost[M];
    int s, t, n;

    inline void init(int _s, int _t, int _n) {
        s = _s;
        t = _t;
        n = _n;
        std::fill(L, L + n, -1);
        cnt = 0;
    }

    inline void add(int u, int v, flow_type c = 1, cost_type w = 0) {
        to[cnt] = v;
        pre[cnt] = L[u];
        C[cnt] = c;
        cost[cnt] = w;
        L[u] = cnt++;
    }

    inline void add_edge(int u, int v, flow_type c = 1, cost_type w = 0) {
        add(u, v, c, w);
        add(v, u, 0, -w);
    }

    cost_type D[N];
    flow_type F[N];
    int mother[N], path[N];

    std::pair <flow_type, cost_type> augment() {
        vector <int> Q(n);
        vector <bool> seen(n, false);
        std::fill(F, F + n, 0);
        std::fill(D, D + n, inf);
        F[s] = inf;
        D[s] = 0;
        int fr = 0, bk = 0;
        Q[bk % n] = s;
        seen[s] = true;
        bk ++;

        while (fr %n != bk % n) {
            int u = Q[fr % n];
            fr ++;
            seen[u] = false;
            for (int e = L[u]; e != -1; e = pre[e]) {
                int v = to[e];
                if (C[e] > 0 && D[v] > D[u] + cost[e]) {
                    D[v] = D[u] + cost[e];
                    path[v] = e;
                    mother[v] = u;
                    F[v] = std::min(F[u], C[e]);
                    if (!seen[v]) {
                        Q[bk % n ] = v;
                        bk ++;
                        seen[v] = true;
                    }
                }
            }
        }
        if (F[t] == 0) {
            return std::make_pair(0, 0);
        }
        int g = t;
        while (g != s) {
            C[path[g]] -= F[t];
            C[path[g] ^ 1] += F[t];
            g = mother[g];
        }
        return std::make_pair(F[t], D[t]);
    }

    std::pair <flow_type, cost_type> cost_flow() {
        std::pair <flow_type, cost_type> ret(0, 0);
        while (true) {
            std::pair <flow_type, cost_type> a = augment();
            if (a.first == 0) {
                break;
            }
            ret.first += a.first;
            ret.second += a.second;
        }
        return ret;
    }
}

using namespace min_cost_max_flow;

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector <int> x(n), y(n), w(n);
        set <int> st;
        rep(i, n) {
            scanf("%d%d%d", &x[i], &y[i], &w[i]);
            st.insert(x[i]);
            st.insert(y[i]);
        }
        int z = 1;
        map <int, int> id;
        for (__typeof(st.begin()) it = st.begin(); it != st.end(); it ++) {
            id[*it] = z++;
        }
        int s = 0, t = n+z;
        init(s, t, t+1);
        rep(i, n) {
            add_edge(id[x[i]], id[y[i]], 1, -w[i]);
        }
        rep(i, t) {
            add_edge(i, i+1, k, 0);
        }
        printf("%d\n", -cost_flow().y);
    }
    return 0;
}
