#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int parent[200002];
long long weight[200002];
int edge[200002];
int level[200002];
vector <vector <int> > adj, id;
vector <vector <long long> > w;
vector <int> child[200002];

void dfs(int u, int x) {
	// cout << u << " " << x << endl;
	for (int i = 0; i < sz(adj[u]); i ++) {
		int v = adj[u][i];
		if (v != x) {
			level[v] = level[u] + 1;
			parent[v] = u;
			edge[id[u][i]] = v;
			weight[v] = w[u][i];
			dfs(v, u);
		}
	}
}

int E[200002];

void merge(int u, int x, int p) {
	for (int i = 0; i < sz(adj[u]); i ++) {
		int v = adj[u][i];
		if (v != x) {
			if (w[u][i] == 1) {
				merge(v, u, p);
			} else {
				parent[v] = p;
				child[p].pb(v);
				E[v] = sz(child[p]) - 1;
				merge(v, u, v);
			}
		}
	}
}

void merge(int e, long long c) {
	int v = edge[e];
	weight[v] = c;
	if (c == 1) {
		for (auto x: child[v]) {
			parent[x] = parent[v];
		}
		for (auto i = child[parent[v]].begin(); i != child[parent[v]].end(); i ++) {
			if (*i == v) {
				child[parent[v]].erase(i);
				break;
			}
		}
		child[parent[v]].splice(child[parent[v]].end(), child[v]);
	}
}

long long get(int u, int v, long long c) {
	while (c > 0 && u != v) {
		// cout << c << " " << u << " " << v << " " << level[u] << " " << level[v];
		// cout << " " << weight[u] << " " << weight[v] << endl;
		if (level[u] > level[v]) {
			c /= weight[u];
			u = parent[u];
		}  else if (level[u] < level[v]) {
			c /= weight[v];
			v = parent[v];
		} else {
			c /= weight[u];
			c /= weight[v];
			u = parent[u];
			v = parent[v];
		}
	}
	return c;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	id.resize(n);
	w.resize(n);
	for (int i = 0; i < n-1; i ++) {
		int u, v;
		long long x;
		cin >> u >> v >> x;

		adj[u-1].pb(v-1);
		id[u-1].pb(i);
		w[u-1].pb(x);

		adj[v-1].pb(u-1);
		id[v-1].pb(i);
		w[v-1].pb(x);
	}
	dfs(0, 0);
	merge(0, 0, 0);
	for (int i = 0; i < m; i ++) {
		int t, u, v, e;
		long long c;
		cin >> t;
		if (t == 1) {
			cin >> u >> v >> c;
			cout << get(u-1, v-1, c) << "\n";
		} else {
			cin >> e >> c;
			merge(e-1, c);
		}
	}
	return 0;
}