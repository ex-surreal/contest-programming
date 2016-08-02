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

vector <vector <int> > adj;
vector <int> seen;

int dfs(int u, int c) {
    seen[u] = c;
    int ret = -1;
    repe(v, adj[u]) {
        if (seen[v] == -1) {
            int t = dfs(v, c);
            if (t != -1) {
                ret = t;
            }
        } else if (seen[v] == c) {
            ret = u;
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> parent(n);
    adj.resize(n);
    seen = vector <int> (n, -1);
    rep(i, n) {
        cin >> parent[i];
        parent[i] --;
        adj[parent[i]].pb(i);
    }
    vector <int> v, u;
    rep(i, n) {
        if (seen[i] == -1) {
            int t = dfs(i, i);
            if (t == -1) {
                continue;
            }
            if (t == parent[t]) {
                u.push_back(t);
            } else {
                v.push_back(t);
            }
        }
    }
    int ans = 0, pre = -1;
    repe(now, v) {
        if (pre != -1) {
            parent[pre] = now;
            ans ++;
        }
        pre = now;
    }
    repe(now, u) {
        if (pre != -1) {
            parent[pre] = now;
            ans ++;
        }
        pre = now;
    }
    if (parent[pre] != pre) {
        ans ++;
        parent[pre] = pre;
    }
    cout << ans << "\n";
    repe(p, parent) {
        cout << p+1 << " ";
    }
    return 0;
}
