#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > adj;

int ans = 0;
vector <int> dp;
vector <int> black;

void dfs(int u, int w) {
    dp[u] = black[u];
    int mx = -1, smx = -1;
    for (auto v: adj[u]) {
        if (v != w) {
            dfs(v, u);
            if (black[u]) {
                dp[u] = max(dp[u], dp[v]+1);
                if (mx < dp[v]) {
                    smx = mx;
                    mx = dp[v];
                } else if (smx < dp[v]) {
                    smx = dp[v];
                }
            }
        }
    }
    if (black[u]) {
        mx = max(0, mx);
        smx = max(0, smx);
        ans = max(ans, mx+smx+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    adj.resize(n);
    dp.resize(n);
    black.resize(n);
    for (auto &b: black) {
        cin >> b;
    }
    for (int i = 0; i < n-1; i ++) {
        int p;
        cin >> p;
        adj[i+1].push_back(p-1);
        adj[p-1].push_back(i+1);
    }
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
