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
	int n;
	cin >> n;
	vector <int> x(n), y(n);
	rep (i, n) {
		cin >> x[i] >> y[i];
	}
	long long ans = 0;
	rep (i, n) {
		map <pair <int, int>, int> cnt;
		rep (j, n) {
			if (i == j) {
				continue;
			}
			int dx = x[j] - x[i];
			int dy = y[j] - y[i];
			int d = __gcd(dy, dx);
			dx /= d, dy /= d;
			cnt[mp(dy, dx)]++;
		}
		repe (j, cnt) {
			if (j->y >= 2) {
				ans += 1ll*(j->y)*(j->y-1);
			}
		}
	}
	cout << (1ll*n*(n-1)*(n-2)/6 - ans/6);
	return 0;
}
