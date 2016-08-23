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

vector <vector <int> > f, g;
vector <int> cnt;
vector <vector <tuple <int, int> > > adj;

void dfs(int u) {
    cnt[u] = 1;
    f[u][1] = g[u][1] = 0;
    repe(s, adj[u]) {
        int v, w;
        tie(v, w) = s;
        dfs(v);
        cnt[u] += cnt[v];
        for (int i = cnt[u]; i > 1; i --) {
            repi(j, 1, min(i, cnt[v]+1)) {
                f[u][i] = min(f[u][i], min(f[v][j]+g[u][i-j]+w, g[v][j]+f[u][i-j]+2*w));
                g[u][i] = min(g[u][i], g[v][j]+g[u][i-j]+2*w);
            }
        }
    }
}

int main () {
    int n, cas = 0;
    while (scanf("%d", &n) != EOF && n) {
        f.clear(), g.clear(), cnt.clear(), adj.clear();
        f.resize(n, vector <int> (n+1, 1<<29));
        g.resize(n, vector <int> (n+1, 1<<29));
        cnt.resize(n);
        adj.resize(n);
        vector <int> parent(n, -1);
        rep(i, n-1) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            parent[u] = v;
            adj[v].push_back(mp(u, w));
        }
        int r = min_element(all(parent))-parent.begin();
        dfs(r);
        rep(i, n) {
            f[i][0] = 0;
        }
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", ++cas);
        while (q --) {
            int c;
            scanf("%d", &c);
            for (int i = n; i >= 0; i --) {
                if (f[r][i] <= c) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
