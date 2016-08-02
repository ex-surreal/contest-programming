#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

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
    const int N = 500, M = 600000, inf = (1<<30);
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
        std::priority_queue <std::pair <cost_type, int> > Q;
        std::fill(F, F + n, 0);
        std::fill(D, D + n, inf);
        F[s] = inf;
        D[s] = 0;
        Q.push(std::make_pair(-D[s], s));

        while (!Q.empty()) {
            int u = Q.top().second;
            cost_type w = -Q.top().first;
            Q.pop();
            if (w > D[u]) {
                continue;
            }
            for (int e = L[u]; e != -1; e = pre[e]) {
                int v = to[e];
                if (C[e] > 0 && D[v] > D[u] + cost[e]) {
                    D[v] = D[u] + cost[e];
                    path[v] = e;
                    mother[v] = u;
                    F[v] = std::min(F[u], C[e]);
                    Q.push(std::make_pair(-D[v], v));
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
    std::ios_base::sync_with_stdio(false);
    int n, k;
    while (cin >> n >> k) {
        int s = 2*n+1, t = s+1;
        init(s, t, t+1);
        rep(i, n) {
            add_edge(s, i, 1, 0);
            add_edge(n+1+i, t, 1, 0);
        }
        add_edge(n, t, k, 0);
        rep(i, n) {
            repi(j, i+1, n+1) {
                int c;
                cin >> c;
                add_edge(j-1, i+n, 1, c);
            }
        }
        cout << cost_flow().y << "\n";
    }
    return 0;
}
