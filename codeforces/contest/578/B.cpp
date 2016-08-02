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
	int n, k, x;
	cin >> n >> k >> x;
	vector <long long> a(n+1), left(n+2, 0), right(n+2, 0);
	repi(i, 1, n+1) {
		cin >> a[i];
	}
	repi(i, 1, n+1) {
		left[i] = left[i-1] | a[i];
	}
	for (int i = n; i > 0; i--) {
		right[i] = right[i+1] | a[i];
	}
	long long y = 1;
	rep(i, k) {
		y *= x;
	}
	long long ans = 0;
	repi(i, 1, n+1) {
		ans = max(ans, left[i-1]|right[i+1]|(a[i]*y));
	}
	cout << ans;
	return 0;
}
