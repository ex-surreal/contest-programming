#include <cstdio>
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

int spfa(int s, int t, vector <vector <pair <int, int> > > &adj) {
    int n = sz(adj);
    vector <int> D(n, 1<<30), Q(n);
    vector <bool> seen(n);
    D[s] = 0;
    seen[s] = true;
    int fr = 0, bk = 0;
    Q[bk % n] = s;
    bk ++;
    while (fr % n != bk % n) {
        int u = Q[fr % n];
        fr ++;
        seen[u] = false;
        rep(i, sz(adj[u])) {
            int v = adj[u][i].x;
            int w = adj[u][i].y;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                if (!seen[v]) {
                    Q[bk % n] = v;
                    bk ++;
                    seen[v] = true;
                }
            }
        }
    }
    return D[t];
}

int main () {
    int n;
    scanf("%d", &n);
    vector <int> u(n), v(n), w(n);
    rep(i, n) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    int s = 0;
    int t = *max_element(all(v))+1;
    vector <vector <pair <int, int> > > adj(t+1);
    repi(i, s, t) {
        adj[i].pb(mp(i+1, 0));
        adj[i+1].pb(mp(i, 1));
    }
    rep(i, n) {
        adj[u[i]].pb(mp(v[i]+1, -w[i]));
    }
    printf("%d\n", -spfa(s, t, adj));
    return 0;
}
