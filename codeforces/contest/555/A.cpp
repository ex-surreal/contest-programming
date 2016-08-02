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

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	rep(i, k) {
		int m;
		cin >> m;
		vector <int> v(m);
		rep(j, m) {
			cin >> v[j];
		}
		int c = 0;
		if (v[0] == 1) {
			for (c = 1; c < m && v[c] == v[c-1]+1; c++);
			c--;
		}
		ans += (m-c-1) + (m-c);
	}
	cout << ans - 1;
	return 0;
}
