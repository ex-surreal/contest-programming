#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <unordered_map>
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

unordered_map<string, double> dp[32];
int n;

tuple<int, string> now(string v, int i, int j) {
    if (i > j) {
        swap(i, j);
    }
    v[i] += v[j];
    while (i+1 < sz(v) && v[i+1] < v[i]) {
        swap(v[i+1], v[i]);
        i ++;
    }
    v.erase(v.begin()+j-1);
    return mp(i-1, v);
}

double solve(int i, string v) {
    if (sz(v) == 1) {
        return 0.0;
    }
    if (dp[i].find(v) == dp[i].end()) {
        double &ret = dp[i][v] = 1.0*(n-1)/(n-v[i]);
        rep(j, sz(v)) {
            if (i == j) {
                continue;
            }
            int k;
            string g;
            tie(k, g) = now(v, i, j);
            ret += solve(k, g)*v[j]/(n-v[i]);
        }
    }
    return dp[i][v];
}

vector <vector <int> > adj;
vector <bool> seen;

int dfs(int u) {
    seen[u] = true;
    int ret = 1;
    repe(v, adj[u]) {
        if (!seen[v]) {
            ret += dfs(v);
        }
    }
    return ret;
}

int main () {
    int tst, cas = 0;
    scanf("%d", &tst);
    while (tst --) {
        int m;
        scanf("%d%d", &n, &m);
        rep(i, n) {
            dp[i].clear();
        }
        seen.clear(), seen.resize(n);
        adj.clear(), adj.resize(n);
        rep(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            u --, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string s = "";
        rep(i, n) {
            if (!seen[i]) {
                s.push_back(dfs(i));
            }
        }
        int u = 0;
        repi(i, 1, sz(s)) {
            if (s[i] < s[0]) {
                u ++;
            }
        }
        sort(all(s));
        printf("Case %d: %.10lf\n", ++cas, solve(u, s));
    }
    return 0;
}
