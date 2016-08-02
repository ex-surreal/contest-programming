#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int cnt[200000];
int cst[200000];
int mx[200000];
int att[200000];
vector <vector <int> > adj;

int diff(int u) {
	if (u == -1) {
		return 0;
	}
	return 2*cnt[u] - cst[u];
}

void dfs1(int u, int w) {
	for (int i = 0; i < sz(adj[u]); i ++) {
		int v = adj[u][i];
		if (v != w) {
			dfs1(v, u);
			if (cnt[v] > 0 || att[v] == 1) {
				cnt[u] += cnt[v]+1;
				if (diff(mx[u]) <= diff(v)) {
					mx[u] = v;
				}
			}
		}
	}
	cst[u] = 2*cnt[u] - diff(mx[u]);
}

int cost = INT_MAX, start = 200000;

void dfs2(int u, int w) {
	// cout << u+1 <<": " << cst[u] << " " << cnt[u] << endl;
	if (cst[u] < cost) {
		cost = cst[u];
		start = u;
	} else if (cst[u] == cost && u < start) {
		start = u;
	}
	for (int i = 0; i < sz(adj[u]); i ++) {
		int v = adj[u][i];
		if (v != w) {
			int cntu = cnt[u] - cnt[v] - int(att[v] == 1 || cnt[v] > 0);
			int cstu = 0;
			if (mx[u] != v) {
				cstu = cst[u] - (cnt[v] + int(att[v] == 1 || cnt[v] > 0))*2;
			} else {
				int mx2 = -1;
				for (int j = 0; j < sz(adj[u]); j ++) {
					int x = adj[u][j];
					if (x != v && x != w && diff(mx2) <= diff(x)) {
						mx2 = x;
					}
				}
				cstu = cst[u] - cst[v] - int(att[v] == 1 || cnt[v] > 0) - diff(mx2);
			}
			cout << u << ", " << v << " = " << cstu << " " << cntu << endl;
			cnt[v] = cnt[v] + cntu + int(cntu > 0 || att[u] == 1);
			int diff2 = 2*cntu - cstu + int(cnt[u] > 0 || att[u] == 1);
			if (diff(mx[v]) <= diff2) {
				mx[v] = u;
				cst[v] = cnt[v]*2 - diff2;
			} else {
				cst[v] = cnt[v]*2 - diff(mx[v]);
			}
			dfs2(v, u);
		}
	}
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < n-1; i ++) {
		int u, v;
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	int u;
	for (int i = 0; i < m; i ++) {
		cin >> u;
		att[u - 1] = 1;
	}
	if (m == 1) {
		cout << u << "\n";
		cout << 0 << "\n";
		return 0;
	}
	memset(mx, -1, sizeof(mx));
	dfs1(0, 0);
	// for (int u = 0; u < n; u ++) {
	// 	cout << u+1 << ": " << mx[u] + 1 << " " << diff(mx[u]) << " " << cst[u] << " " << cnt[u] << endl;
	// }
	dfs2(0, 0);
	// cout << endl;
	cout << start+1 << "\n" << cost << "\n";
	return 0;
}