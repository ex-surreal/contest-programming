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

vector <int> parent, choose, ans;
vector <vector <int> > adj;

void dfs(int u) {
    repe(v, adj[u]) {
        dfs(v);
    }
    if (choose[u] == u) {
        ans.pb(choose[u] + 1);
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    choose.resize(n);
    adj.resize(n);
    rep(i, n) {
        parent[i] = i;
        choose[i] = -1;
    }
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        parent[b] = a;
        adj[a].pb(b);
    }
    rep(i, n) {
        int a, t = i;
        cin >> a;
        a --;
        while (true) {
            if (choose[t] == -1) {
                choose[t] = a;
            } else if (choose[t] != a) {
                cout << "-1\n";
                return 0;
            }
            if (t == a) {
                break;
            }
            t = parent[t];
        }
    }
    ans.clear();
    rep(i, n) {
        if (parent[i] == i) {
            dfs(i);
        }
    }
    cout << sz(ans) << "\n";
    repe(e, ans) {
        cout << e << "\n";
    }
    return 0;
}
