#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define rep(i, n) for (int i=0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

double dp[100005];
double R[100005];
int T[100005];
vector <vector <int> > adj;

double dfs(int u, int w) {
	dp[u] = T[u];
	int deg = sz(adj[u]);
	rep(i, deg) {
		int v = adj[u][i];
		if (v != w) {
			dp[u] += dfs(v, u)/(deg - int(u != w));
		}
	}
	return dp[u];
}

void make(int u, int w) {
	int degu = sz(adj[u]);
	rep(i, degu) {
		int v = adj[u][i];
		if (v != w) {
			int degv = sz(adj[v]);
			R[v] = (((R[u] - T[u])*degu - dp[v])/(degu - int(degu > 1)) + T[u])/degv;
			R[v] += (dp[v] - T[v])*(degv - 1)/degv + T[v];
			make(v, u);
		}
	}
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
	}
	adj.resize(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	dfs(0, 0);
	R[0] = dp[0];
	make(0, 0);
	cout << (min_element(R, R+n) - R) + 1 << endl;
	return 0;
}