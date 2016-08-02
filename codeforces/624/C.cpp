#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int deg[505], n;
int adj[505][505];
string ans;

void dfs(int u, char c) {
    ans[u] = c;
    for (int i = 0; i < n; i ++) {
        if (adj[u][i] && ans[i] == '#') {
            dfs(i, c);
        }
    }
}

int main () {
	std::ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x-1][y-1] = 1;
        adj[y-1][x-1] = 1;
        deg[x-1] ++;
        deg[y-1] ++;
    }
    ans = string(n, '#');
    for (int i = 0; i < n; i ++) {
        if (deg[i] == n-1) {
            ans[i] = 'b';
            continue;
        }
    }
    string d = "ac";
    for (int i = 0; i < n && d != ""; i ++) {
        if (ans[i] == '#') {
            dfs(i, d[0]);
            d = d.substr(1);
        }
    }
    for (int i = 0; i < n; i ++) {
        if (ans[i] == '#') {
            cout << "No\n";
            return 0;
        }
        for (int j = 0; j < i; j ++) {
            if (int(abs(ans[i]-ans[j]) <= 1) ^ adj[i][j]) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    cout << ans <<"\n";
	return 0;
}
