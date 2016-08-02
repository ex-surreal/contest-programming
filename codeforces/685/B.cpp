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

vector <vector <int> > adj;
vector <int> S, ans, parent, M;
set <pair <int, int> > R;

int dfs(int u, int w) {
    parent[u] = w;
    S[u] = 1;
    M[u] = 0;
    repe(v, adj[u]) {
        if (v != w) {
            int t = dfs(v, u);
            S[u] += t;
            M[u] = max(t, M[u]);
        }
    }
    return S[u];
}

void make(int u, int w) {
    auto it = R.lower_bound(mp(-2*S[u], -1));
    while (it != R.end()) {
        int t = it->y;
        if (S[t]-S[u] <= S[t]/2 && M[u] <= S[t]/2) {
            ans[t] = u + 1;
        } else {
            break;
        }
        auto r = it;
        it ++;
        R.erase(r);
    }
    R.insert(mp(-S[u], u));
    repe(v, adj[u]) {
        if (v != w) {
            make(v, u);
        }
    }
    R.erase(mp(-S[u], u));
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    ans.resize(n);
    parent.resize(n);
    S.resize(n);
    M.resize(n);
    adj.resize(n);
    repi(u, 1, n) {
        int v;
        cin >> v;
        v --;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    make(0, -1);
    rep(i, n) {
        if (ans[i] == 0) {
            ans[i] = i+1;
        }
    }
    rep(i, q) {
        int u;
        cin >> u;
        cout << ans[u-1] << "\n";
    }
    return 0;
}
