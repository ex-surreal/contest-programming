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

int pwr(int a, int n, int m) {
	if (n == 0) {
		return 1%m;
	}
	int t = pwr(a, n/2, m);
	if (n&1) {
		return 1ll*t*t%m*a%m;
	}
	return 1ll*t*t%m;
}

int mod = 1e9+7;

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << ((pwr(3, 3*n, mod) - pwr(7, n, mod))%mod + mod)%mod;
	return 0;
}
