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

const int lim = 100005;
int tree[lim];

int read(int id) {
	int sum = 0;
	while (id > 0) {
		sum += tree[id];
		id -= id&-id;
	}
	return sum;
}

void update(int id, int val) {
	while (id < lim) {
		tree[id] += val;
		id += id&-id;
	}
}

int main () {
	std::ios_base::sync_with_stdio(false);
	repi(i, 1, lim) {
		update(i, 1);
	}
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(k, m) {
		int x, i, j;
		cin >> x >> i >> j;
		if (x == 1) {

		} else {
			
		}
		update(j+1, i-n);
		update(i, (n-j+1));
		rep(i, n) {
			cout << read(i+1) << " ";
		} cout << endl;
	}
	vector <int> ans(n);
	rep(i, n) {
		ans[read(i+1) - 1] = a[i];
	}
	cout << abs(ans[0] - ans[n-1]) << "\n";
	rep(i, n) {
		if (i > 0) {
			cout << " ";
		}
		cout << ans[i];
	}
	cout << endl;
	return 0;
}