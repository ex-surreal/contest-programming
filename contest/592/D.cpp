#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int sum[200000];
int cnt[200000];
int cst[200000];
int mx[200000];
int att[200000];
vector <vector <int> > adj;

int diff(int u) {
	return 2*cnt[u] - cst[u];
}

void dfs1(int v, int u) {
	cnt[v] = 0;
	mx[v] = v;
	for (int i = 0; i < sz(adj[v]); i ++) {
		int x = adj[v][i];
		if (x != u) {
			dfs1(x, v);
			if (cnt[x] > 0 || att[x]) {
				cnt[v] += cnt[x] + 1;
				if (diff(mx[v]) <= cnt[x]+1) {
					mx[v] = x;
				}
			}
		}
	}
	cst[v] = cnt[v]*2 - cnt[mx[v]];
}

int cost = INT_MAX, start = 200000;

void dfs2(int v, int u) {
	int t = sum[u] - cnt[v];
	int s = t;
	for (int i = 0; i < sz(adj[v]); i ++) {
		int x = adj[v][i];
		if (x != u) {
			if (cnt[x] > 0 || att[x]) {
				s += cnt[x]+1;
			}
		}
	}
	sum[v] = s;
	int c = 0;
	if (c < cost) {
		cost = c;
		start = v;
	} else if (c == cost && start > v) {
		start = v;
	}
	for (int i = 0; i < sz(adj[v]); i ++) {
		int x = adj[v][i];
		if (x != u) {
			dfs2(x, v);
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
	for (int i = 0; i < m; i ++) {
		int u;
		cin >> u;
		att[u - 1] = 1;
	}
	dfs1(0, 0);
	sum[0] = cnt[0];
	dfs2(0, 0);
	for (int i = 0; i < n; i ++) {
		cout << cnt[i] << " ";
	} cout << endl;
	cout << start+1 << "\n" << cost << "\n";
	return 0;
}