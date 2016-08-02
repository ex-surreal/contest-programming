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

int D[100005];
int B[100005];
int P[100005];
int ans;
vector <pair <int, int> > adj[100005];

void dfs(int u) {
    repe(v, adj[u]) {
        if (D[v.x] == -1) {
            P[v.x] = u;
            D[v.x] = D[u] + v.y;
            dfs(v.x);
        }
    }
}

int cnt(int u) {
    int ret = B[u];
    repe(v, adj[u]) {
        if (D[v.x] == -1) {
            D[v.x] = D[u] + v.y;
            int t = cnt(v.x);
            if (t > 0) {
                ans += 2*v.y;
            }
            ret += t;
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    rep(i, k) {
        int u;
        cin >> u;
        B[u] = 1;
    }
    rep(i, n-1) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
    }
    mem(D, -1);
    D[n] = 0;
    P[n] = n;
    dfs(n);
    int s = -1, t = -1;
    repi(i, 1, n+1) {
        if (B[i] && (s == -1 || D[s] < D[i])) {
            s = i;
        }
    }
    mem(D, -1);
    D[s] = 0;
    P[s] = s;
    dfs(s);
    repi(i, 1, n+1) {
        if (B[i] && (t == -1 || D[t] < D[i])) {
            t = i;
        }
    }
    ans = D[t];
    int p = t;
    mem(D, -1);
    while (P[p] != p) {
        D[p] = 0;
        p = P[p];
    }
    D[p] = 0;
    p = t;
    while (P[p] != p) {
        cnt(p);
        p = P[p];
    }
    cnt(p);
    cout << ans;
    return 0;
}

