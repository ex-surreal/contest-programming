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
	int n, t;
	cin >> n >> t;
	if (t == 10) {
		if (n == 1) {
			cout << -1;
		} else {
			cout << ("1" + string(n-1, '0'));
		}
		return 0;
	}
	if (n==1) {
		cout << t;
		return 0;
	}
	int r = 1 % t;
	rep(i, n-1) {
		r = r*10%t;
	}
	cout << ("1" + string(n-2, '0')) << (t-r)%t;
	return 0;
}
