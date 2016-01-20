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

long long C[27][27];

void makeC() {
	rep(i, 27) {
		C[i][0] = 1;
		repi(j, 1, i+1) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
}

long long countWays(int len) {
	long long ret = 0;
	repi(i, 1, len) {
		ret += (1ll << (i-1)) * (len - i);
	}
	return ret;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	makeC();
	long long ans = 0;
	repi(i, 2, 27) {
		ans = max(ans, C[26][i]*countWays(i));
	}
	cout << ans << endl;
	return 0;
}
