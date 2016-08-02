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
int n, k;
vector <int> uni;
long long ans;

int dfs(int u, int w) {
    int ret = uni[u];
    repe(v, adj[u]) {
        if (v != w) {
            int t = dfs(v, u);
            ans += min(t, 2*k-t);
            ret += t;
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> k;
    adj.resize(n);
    uni.resize(n);
    fill(all(uni), 0);
    ans = 0;
    rep(i, 2*k) {
        int x;
        cin >> x;
        uni[x-1] = 1;
    }
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
