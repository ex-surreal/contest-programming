#include<algorithm>
#include<vector>

using namespace std;

const int inf = (1 << 30);
vector <int> L, pre, to, ptr, cap, flow, level;

void init(int n) {
    level = L = vector <int> (n, -1);
    pre.clear();
    to.clear();
    ptr.clear();
    cap.clear();
    flow.clear();
}

void add(int u, int v, int c = 1) {
    to.push_back(v);
    pre.push_back(L[u]);
    cap.push_back(c);
    flow.push_back(0);
    L[u] = to.size()-1;
}

void add_edge(int u, int v, int c = 1) {
    add(u, v, c);
    add(v, u, 0);
}

bool bfs(int s, int t) {
    int fr = 0, bk = 0;
    level = vector <int> (L.size(), -1);
    level[s] = 0;
    vector <int> Q(L.size());
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

int dfs(int u, int f, int t) {
    if (u == t || f == 0) {
        return f;
    }
    for (int & e = ptr[u]; e != -1; e = pre[e]) {
        int v = to[e];
        if (flow[e] < cap[e] && level[v] == level[u] + 1) {
            int pushed = dfs(v, min(f, cap[e] - flow[e]), t);
            if (pushed > 0) {
                flow[e] += pushed;
                flow[e ^ 1] -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int mf(int s, int t) {
    int ret = 0;
    while (bfs(s, t)) {
        ptr = L;
        while (int f = dfs(s, inf, t)) {
            ret += f;
        }
    }
    return ret;
}
