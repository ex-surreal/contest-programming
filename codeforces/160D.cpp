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

template <class x, class y> ostream & operator << (ostream &o, pair <x, y> p) {
	o << "(" << p.first << ", " << p.y << ")";
	return o;
}
template <class x> ostream & printAll(ostream &o, x v, string a, string b) {
	o << a;
	for (__typeof(v.begin()) i = v.begin(); i != v.end(); i++) {
		if (i != v.begin()) {
			o << ", ";
		}
		o << *i;
	}
	o << b;
	return o;
}
template <class x> ostream & operator << (ostream &o, vector <x> v) {
	return printAll(o, v, "{", "}");
}
template <class x> ostream & operator << (ostream &o, set <x> v) {
	return printAll(o, v, "[", "]");
}
template <class x> ostream & operator << (ostream &o, multiset <x> v) {
	return printAll(o, v, "[", "]");
}
template <class x, class y> ostream & operator << (ostream &o, map <x, y> v) {
	return printAll(o, v, "[", "]");
}

int last[100005], to[200005], pre[200005], cnt;
int low[100005];
int seen[100005];
int level[100005];
int z;
bool bridge[200005];

void init(int n) {
	rep(i, n) {
		last[i] = -1;
		seen[i] = -1;
	}
	z = cnt = 0;
}

void addEdge(int u, int v) {
	bridge[cnt] = false;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt++;
}

void add(int u, int v) {
	addEdge(u, v);
	addEdge(v, u);
}

void dfs(int u, int w, int c = -1) {
	low[u] = seen[u] = z++;
	for (int e = last[u]; e != -1; e = pre[e]) {
		int v = to[e];
		if (seen[v] == -1) {
			dfs(v, u, e);
			low[u] = min(low[u], low[v]);
			if (low[v] > seen[u]) {
				bridge[e] = true;
				bridge[e^1] = true;
			}
		} else if (c != (e^1)) {
			low[u] = min(low[u], seen[v]);
		}
	}
}

int parent[100005], rnk[100005];

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return find(parent[u]);
}

void join(int u, int v) {
	if (rnk[u] > rnk[v]) {
		parent[v] = u;
	} else {
		if (rnk[u] == rnk[v]) {
			rnk[v] ++;
		}
		parent[u] = v;
	}
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <pair <pair <int, int>, pair <int, int> > > edge(m);
	rep(i, m) {
		cin >> edge[i].y.x >> edge[i].y.y >> edge[i].x.x;
		edge[i].y.x --;
		edge[i].y.y --;
		edge[i].x.y = i;
	}
	sort(edge.begin(), edge.end());
	rep(i, n) {
		parent[i] = i;
		rnk[i] = 0;
	}
	vector <int> ans(m, 0);
	rep(i, m) {
		int j = i;
		set <int> st;
		vector <pair <pair <int, int>, int> > E;
		while (j < m && edge[j].x.x == edge[i].x.x) {
			int u = find(edge[j].y.x);
			int v = find(edge[j].y.y);
			if (u != v) {
				st.insert(u);
				st.insert(v);
				E.pb(mp(mp(u, v), edge[j].x.y));
				ans[edge[j].x.y] = 1;
			}
			j++;
		}
		repi(k, i, j) {
			int u = find(edge[k].y.x);
			int v = find(edge[k].y.y);
			if (u != v) {
				join(u, v);
			}
		}
		map <int, int> id;
		int g = 0;
		repe(k, st) {
			id[*k] = g++;
		}
		init(sz(st));
		// cout << st << endl;
		// cout << E << endl;
		repe(k, E) {
			add(id[k->x.x], id[k->x.y]);
		}
		int r = sz(st);
		rep(i, r) {
			if (seen[i] == -1) {
				dfs(i, i);
			}
		}
		rep(k, sz(E)) {
			if (bridge[k<<1]) {
				ans[E[k].y] = 2;
			}
		}
		i = j - 1;
	}
	string str[] = {"none", "at least one", "any"};
	rep(i, m) {
		cout << str[ans[i]] << "\n";
	}
	return 0;
}
