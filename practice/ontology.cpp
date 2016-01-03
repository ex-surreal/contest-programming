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

vector <vector <int> > adj;
map <string, int> id;
int to[100005];

int dfs(int u, int w) {
	to[u] = u;
	rep(i, sz(adj[u])) {
		int v = adj[u][i];
		if (v != w) {
			to[u] = max(dfs(v, u), to[u]);
		}
	}
	return to[u];
}

void buildTree(string &str, int n) {
	stringstream sin(str);
	string p;
	stack <int> S;
	int z = 0, last = -1;
	adj.clear();
	adj.resize(n);
	while (sin >> p) {
		if (p == "(") {
			S.push(last);
		} else if (p == ")") {
			S.pop();
		} else {
			last = z;
			if (!S.empty()) {
				adj[S.top()].pb(z);
				adj[z].pb(S.top());
			}
			id[p] = z++;
		}
	}
	dfs(0, 0);
}

int tree[100005];

int read(int id) {
	int sum = 0;
	while (id > 0) {
		sum += tree[id];
		id -= id & -id;
	}
	return sum;
}

int read(int x, int y) {
	return read(y) - read(x-1);
}

void update(int id, int val) {
	while (id < 100005) {
		tree[id] += val;
		id += id & -id;
	}
}

bool comp(string a, string b) {
	if (sz(b) < sz(a)) {
		a = a.substr(0, sz(b));
	} else {
		b = b.substr(0, sz(a));
	}
	return a <= b;
}

int upper_bound(vector <pair <string, int> > &sweep, string q) {
	int low = 0, high = sz(sweep) - 1;
	while (low <= high) {
		int mid = (low+high)/2;
		if (comp(sweep[mid].x, q)) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return low - 1;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	string line;
	getline(cin, line);
	int n = stoi(line);
	getline(cin, line);
	buildTree(line, n);
	getline(cin, line);
	int m = stoi(line);
	vector <pair <string, int> > sweep;
	sweep.pb(mp("#", -1));
	sweep.pb(mp("|", n));
	id["#"] = n;
	id["|"] = n + 1;
	rep(i, m) {
		getline(cin, line);
		int f = line.find_first_of(" ");
		string topic = line.substr(0, f-1);
		string question = line.substr(f+1);
		sweep.pb(mp(question, id[topic]));
	}
	sort(sweep.begin(), sweep.end());
	vector <vector <int> > u(m+2), q(m+2), s(m+2);
	getline(cin, line);
	int k = stoi(line);
	rep(i, k) {
		getline(cin, line);
		int f = line.find_first_of(" ");
		string topic = line.substr(0, f);
		string question = line.substr(f+1);
		int x = lower_bound(sweep.begin(), sweep.end(), mp(question, -1)) - sweep.begin();
		int y = upper_bound(sweep, question);
		if (y < x) {
			continue;
		}
		u[x].pb(id[topic]);
		q[x].pb(i);
		s[x].pb(0);
		u[y].pb(id[topic]);
		q[y].pb(i);
		s[y].pb(1);
	}
	vector <int> ans(k, 0);
	repi(i, 1, sz(sweep)) {
		rep(j, sz(u[i])) {
			if (s[i][j] == 0) {
				ans[q[i][j]] -= read(u[i][j]+1, to[u[i][j]]+1);
			}
		}
		update(sweep[i].y+1, 1);
		rep(j, sz(u[i])) {
			if (s[i][j] == 1) {
				ans[q[i][j]] += read(u[i][j]+1, to[u[i][j]]+1);
			}
		}
	}
	rep(i, sz(ans)) {
		cout << ans[i] << "\n";
	}
	return 0;
}