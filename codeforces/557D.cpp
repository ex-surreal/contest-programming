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

vector<vector<int> > adj, tree;
vector<int> low, seen, level, odd, even, bcc;
int timer, bccCount;
bool hasOddCircle;
stack<pair<int, int> > S;

void dfs(int u, int w) {
	low[u] = seen[u] = timer++;
	level[u] = level[w]^1;
	int c = 0;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (seen[v] == -1) {
			c ++;
			S.push(make_pair(u, v));
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if ((u == w && c > 1) || (u !=w && low[v] >= seen[u])) {
				int f = 0;
				while(!S.empty()) {
					int x = S.top().x;
					int y = S.top().y;
					if (x == u && y == v) {
						break;
					}
					S.pop();
					bcc[x] = bcc[y] = bccCount;
					f = 1;
				}
				bccCount += f;
			}
		} else if (v != w && seen[v] < seen[u]) {
			low[u] = min(low[u], seen[v]);
			S.push(make_pair(u, v));
			if (level[u] == level[v]) {
				hasOddCircle = true;
			}
		}
	}
}

void getBCCTree() {
	fill(seen.begin(), seen.end(),  -1);
	bccCount = timer = 0;
	for (int u = 0; u < (int)adj.size(); u++) {
		if (seen[u] == -1) {
			level[u] = 0;
			dfs(u, u);
		}
	}
	for (int i = 0; i < (int)bcc.size(); i++) {
		cerr << bcc[i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < (int)bcc.size(); i++) {
		if (bcc[i] == -1) {
			bcc[i] = bccCount++;
		}
	}
	tree = vector<vector<int> >(bccCount, vector<int>());
	for (int u = 0; u < (int)adj.size(); u++) {
		for (int j = 0; j < (int)adj[u].size(); j++) {
			int v = adj[u][j];
			if (bcc[u] != bcc[v]) {
				tree[bcc[u]].push_back(bcc[v]);
			}
		}
	}
}

void makeGraph(int n, vector<int> u, vector<int> v) {
	adj = vector<vector<int> >(n);
	low = vector<int>(n);
	seen = vector<int>(n);
	level = vector<int>(n);
	hasOddCircle = false;
	odd = vector<int>(n);
	even = vector<int>(n);
	bcc = vector<int>(n, -1);
	for (int i = 0; i < (int)u.size(); i++) {
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	getBCCTree();
}

long long count(int u, int w) {
	seen[u] = 0;
	long long ret = 0, oddSq = 0, oddSum = 0, evenSq = 0, evenSum = 0;
	even[u] = odd[u] = 0;
	for (int i = 0; i < (int)tree[u].size(); i++) {
		int v = tree[u][i];
		if (seen[v] == -1) {
			ret += count(v, u);
			even[u] += odd[v];
			odd[u] += even[v] + 1;
			oddSum += odd[v];
			oddSq += ((long long)odd[v])*odd[v];
			evenSum += even[v] + 1;
			evenSq += ((long long)even[v] + 1)*(even[v] + 1);
			ret += odd[v];
		}
	}
	ret += (oddSum*oddSum - oddSq)/2 + (evenSum*evenSum - evenSq)/2;
	return ret;
}

long long count() {
	vector<int> cnt(bccCount);
	for (int i = 0; i < (int)bcc.size(); i++) {
		cnt[bcc[i]]++;
	}
	long long ret = 0;
	for (int i = 0; i < (int)cnt.size(); i++) {
		if (cnt[i] >= 4) {
			ret += ((long long)cnt[i]/2)*(cnt[i]/2 -1);
		}
	}
	fill(seen.begin(), seen.end(), -1);
	for (int u = 0; u < (int)tree.size(); u++) {
		if (seen[u] == -1) {
			ret += count(u, u);
		}
	}
	return ret;
}

bool checkForOddCircle() {
	return hasOddCircle;
}

class Solver {
	int caseNum, n, m;
public:
	Solver(int n, vector<int> u, vector<int> v) {
		this->n = n;
		this->m = u.size();
		makeGraph(n, u, v);
		caseNum = getCaseNum(n, u, v);
	}
	
	vector<long long> solve() {
		vector<long long> ret(2);
		if (caseNum == 0) {
			ret[0] = 3;
			ret[1] = ((long long)n)*(n-1)*(n-2)/6;
		} else if (caseNum == 1) {
			ret[0] = 2;
			ret[1] = ((long long)m)*(n-2);
		} else if (checkForOddCircle()) {
			ret[0] = 0;
			ret[1] = 1;
		} else {
			ret[0] = 1;
			ret[1] = count();
		}
		return ret;
	}
	
	int getCaseNum(int n, vector<int> u, vector<int> v) {
		if (m == 0) {
			return 0;
		}
		vector<int> deg(n, 0);
		for (int i = 0; i < m; i++) {
			deg[u[i]]++;
			deg[v[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if (deg[i] > 1) {
				return 2;
			}
		}
		return 1;
	}
};

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <int> u(m), v(m);
	rep (i, m) {
		cin >> u[i] >> v[i];
		// u[i] --, v[i] --;
	}
	Solver solver(n, u, v);
	vector<long long> ret = solver.solve();
	cout << ret[0] << " " << ret[1] << endl;
	return 0;
}
