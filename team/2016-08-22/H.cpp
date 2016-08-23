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

vector <bool> can, trap;
vector <int> f[2], lft, rgt;
vector <vector <int> > adj;

void dfs(int u, int w) {
    if (w != -1) {
        if (lft[w] == -1) {
            lft[w] = u;
        } else {
            rgt[w] = u;
        }
    }
    repe(v, adj[u]) {
        if (v != w) {
            dfs(v, u);
        }
    }
    if (trap[u]) {
        can[u] = false;
        f[0][u] = f[1][u] = 0;
        return;
    }
    if (lft[u] == -1) {
        can[u] = true;
        f[0][u] = 1, f[1][u] = 0;
    } else if (rgt[u] == -1) {
        can[u] = can[lft[u]];
        f[0][u] = f[0][lft[u]];
        f[1][u] = f[1][lft[u]];
    } else {
        can[u] = can[lft[u]] && can[rgt[u]];
        f[1][u] = 1<<29;
        if (can[rgt[u]]) {
            f[1][u] = min(f[1][u], min(f[1][lft[u]], f[0][lft[u]]));
        }
        if (can[lft[u]]) {
            f[1][u] = min(f[1][u], min(f[1][rgt[u]], f[0][rgt[u]]));
        }
        f[0][u] = f[0][lft[u]]+f[0][rgt[u]];
        if (can[u]) {
            f[0][u] = min(f[0][u], 1);
        } else {
            f[0][u] = min(f[0][u], f[1][u]+1);
        }
    }
}

int main () {
    int n, m;
    while (~scanf("%d%d", &n, &m) && n) {
        adj.clear(), adj.resize(n);
        trap.clear(), trap.resize(n, false);
        can.clear(), can.resize(n, false);
        lft.clear(), lft.resize(n, -1);
        rgt.clear(), rgt.resize(n, -1);
        f[0].clear(), f[0].resize(n);
        f[1].clear(), f[1].resize(n);
        rep(i, n) {
            int k;
            scanf("%d", &k);
            while (k --) {
                int j;
                scanf("%d", &j);
                adj[i].push_back(j-1);
            }
        }
        rep(i, m) {
            int j;
            scanf("%d", &j);
            trap[j-1] = true;
        }
        dfs(0, -1);
        printf("%d\n", f[0][0]);
    }
    return 0;
}
