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

vector <int> adj[100005];
int L[100005];
int P[100005];
int C[100005];
int O[100005];
int D;

void dfs(int u, int w) {
    P[u] = w;
    L[u] = L[w]+1;
    repe(v, adj[u]) {
        if (v != w) {
            dfs(v, u);
        }
    }
}

void make(int u, int w) {
    if (O[u]) {
        C[u] = max(L[u], L[D]-L[u]);
    } else {
        C[u] = C[w] + 1;
    }
    repe(v, adj[u]) {
        if (v != w) {
            make(v, u);
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    L[0] = -1;
    dfs(1, 1);
    int S = max_element(L+1, L+n+1)-L;
    L[S] = -1;
    dfs(S, S);
    D = max_element(L+1, L+n+1)-L;
    int t = D;
    while (P[t] != t) {
        O[t] = 1;
        t = P[t];
    }
    O[t] = 1;
    make(S, S);
    rep(i, m) {
        int v, k;
        cin >> v >> k;
        cout << C[v] + 1ll*(k-1)*C[D] << "\n";
    }
    return 0;
}
