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

int seg[400004];
long long sum[400004];
int a[100005];

long long read(int node, int x, int y, int u, int v) {
	if (y < u || x > v || x > y) {
		return 0;
	}
	if (u <= x && y <= v) {
		return sum[node];
	}
	long long p = read(2*node + 1, x, (x+y)/2, u, v);
	long long q = read(2*node + 2, (x+y)/2 + 1, y, u, v);
	return p+q;
}

void update(int node, int x, int y, int u, int val) {
	if (y < u || x > u || x > y) {
		return;
	}
	if (x == y) {
		seg[node] = val;
		sum[node] = val;
		return;
	}
	update(2*node + 1, x, (x+y)/2, u, val);
	update(2*node + 2, (x+y)/2 + 1, y, u, val);
	seg[node] = max(seg[2*node + 1], seg[2*node + 2]);
	sum[node] = sum[2*node + 1] + sum[2*node + 2];
}

void modUpdate(int node, int x, int y, int u, int v, int mod) {
	if (y < u || x > v || x > y) {
		return;
	}
	if (u <= x && y <= v && seg[node] < mod) {
		return;
	}
	if (x == y) {
		seg[node] = seg[node] % mod;
		sum[node] = sum[node] % mod;
		return;
	}
	modUpdate(2*node + 1, x, (x+y)/2, u, v, mod);
	modUpdate(2*node + 2, (x+y)/2 + 1, y, u, v, mod);
	seg[node] = max(seg[2*node + 1], seg[2*node + 2]);
	sum[node] = sum[2*node + 1] + sum[2*node + 2];
}

void init(int node, int x, int y) {
	if (x==y) {
		seg[node] = a[x];
		sum[node] = a[x];
		return;
	}
	init(2*node + 1, x, (x+y)/2);
	init(2*node + 2, (x+y)/2 + 1, y);
	seg[node] = max(seg[2*node + 1], seg[2*node + 2]);
	sum[node] = sum[2*node + 1] + sum[2*node + 2];
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	rep (i, n) {
		cin >> a[i];
	}
	init(0, 0, n-1);
	rep (i, m) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			cout << read(0, 0, n-1, l-1, r-1) << "\n";
		} else if (op == 2) {
			int l, r, mod;
			cin >> l >> r >> mod;
			modUpdate(0, 0, n-1, l-1, r-1, mod);
		} else {
			int u, x;
			cin >> u >> x;
			update(0, 0, n-1, u-1, x);
		}
		// cerr << "\n***************\n";
		// rep(i, n) {
		// 	cerr << read(0, 0, n-1, i, i) << " ";
		// } cerr << endl;
		// cerr << "\n***************\n";
	}
	return 0;
}
