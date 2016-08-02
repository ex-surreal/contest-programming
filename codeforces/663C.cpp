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

vector <pair <int, bool> > adj[100005];
int color[100005];
vector <int> cnt[2];

void dfs(int u, bool c, int k) {
    color[u] = c;
    cnt[c].pb(u);
    repe(x, adj[u]) {
        int v = x.x, w = x.y;
        if (color[v] == -1) {
            dfs(v, w^k^c, k);
        } else if (color[v] != (w^k^c)) {
            throw -1;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        adj[x].pb(mp(y, s == "R"));
        adj[y].pb(mp(x, s == "R"));
    }
    int ans = INT_MAX;
    vector <int> a;
    rep(d, 2) {
        mem(color, -1);
        int t = 0;
        vector <int> f;
        try {
            repi(i, 1, n+1) {
                if (color[i] == -1) {
                    cnt[0].clear();
                    cnt[1].clear();
                    dfs(i, 0, d);
                    int h = sz(cnt[0]) > sz(cnt[1]);
                    t += sz(cnt[h]);
                    repe(x, cnt[h]) {
                        f.pb(x);
                    }
                }
            }
            if (t < ans) {
                ans = t;
                a = f;
            }
        } catch (int x) {
            
        }
    }
    if (ans == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << ans << "\n";
    repe(x, a) {
        cout << x << " ";
    }
    return 0;
}
