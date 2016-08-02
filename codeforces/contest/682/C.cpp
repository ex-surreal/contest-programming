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

vector <vector <tuple <int, int> > > adj;
vector <int> a, cnt;

int make(int u, int w) {
    cnt[u] = 1;
    repe(x, adj[u]) {
        int v, c;
        tie(v, c) = x;
        if (v != w) {
            cnt[u] += make(v, u);
        }
    }
    return cnt[u];
}

int dfs(int u, int w, long long c, long long mn) {
    if (c - mn > a[u]) {
        return cnt[u];
    }
    int ret = 0;
    repe(x, adj[u]) {
        int v, f;
        tie(v, f) = x;
        if (v != w) {
             ret += dfs(v, u, c+f, min(mn, c+f));
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    adj.resize(n);
    a = cnt = vector <int> (n);
    repe(&x, a) {
        cin >> x;
    }
    repi(u, 1, n) {
        int v, w;
        cin >> v >> w;
        v --;
        adj[u].pb(make_tuple(v, w));
        adj[v].pb(make_tuple(u, w));
    }
    make(0, 0);
    cout << dfs(0, 0, 0, 0);
    return 0;
}
