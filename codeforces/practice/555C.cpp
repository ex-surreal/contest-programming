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
	// freopen("in.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	long long ans = 1ll*n*(n+1)/2;
	map <int, int> L, U;
	L[0] = 1;
	U[0] = 0;
	rep (i, q) {
		int x, y;
		string s;
		cin >> y >> x >> s;
		if (L.count(x) != 0 || U.count(y) != 0) {
			cout << "0\n";
			continue;
		}
		if (s == "L") {
			map <int, int>::iterator ix = L.upper_bound(x);
			map <int, int>::iterator iy = U.lower_bound(y);
			iy --;
			if (ix != L.end()) {
				int tx = n+1 - iy->x;
				if (x < tx && tx <ix->x) {
					L[x] = iy->x + 1;
				} else {
					L[x] = ix->y;
				}
			} else {
				L[x] = iy->x + 1;
			}
			ans = y - L[x] + 1;
		} else {
			map <int, int>::iterator ix = U.upper_bound(y);
			map <int, int>::iterator iy = L.lower_bound(x);
			iy --;
			if (ix != U.end()) {
				int ty = n+1 - iy->x;
				if (y < ty && ty <ix->x) {
					U[y] = iy->x + 1;
				} else {
					U[y] = ix->y;
				}
			} else {
				U[y] = iy->x + 1;
			}
			ans = x - U[y] + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
