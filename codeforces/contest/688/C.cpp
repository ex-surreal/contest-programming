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

vector <int> color;
vector <vector <int> > adj;

bool dfs(int u, int c) {
    color[u] = c;
    bool ret = true;
    repe(v, adj[u]) {
        if (color[v] == -1) {
            ret = dfs(v, c^1) && ret;
        } else if (color[v] != (c^1)) {
            ret = false;
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    color.resize(n);
    adj.resize(n);
    fill(all(color), -1);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool f = true;
    rep(i, n) {
        if (color[i] == -1) {
            f = dfs(i, 0) && f;
        }
    }
    if (!f) {
        cout << -1;
    } else {
        vector <int> ans[2];
        rep(i, n) {
            ans[color[i]].pb(i+1);
        }
        rep(i, 2) {
            cout << sz(ans[i]) << "\n";
            repe(x, ans[i]) {
                cout << x << " ";
            } cout << "\n";
        }
    }
    return 0;
}
