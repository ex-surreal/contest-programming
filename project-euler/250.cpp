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

int pow(int base, int exp, int mod) {
	int ret = 1;
	while (exp > 0) {
		if (exp&1) {
			ret = 1ll*ret*base % mod;
		}
		exp >>= 1;
		base = 1ll*base*base % mod;
	}
	return ret;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n = 250250, mod = 250;
	cin >> n >> mod;
	cerr << n << " " << mod << endl;
	long long dp[2][mod], now = 0, pre = 1, M = 1e16;
	memset(dp, 0, sizeof(dp));
	dp[now][0] = 1;
	for (int i = 1; i <= n; i++) {
		swap(now, pre);
		int x = pow(i%mod, i, mod);
		for (int j = 0; j < mod; j++) {
			dp[now][j] = dp[pre][j];
		}
		for (int j = 0; j < mod; j++) {
			if (dp[pre][j] == 0) {
				continue;
			}
			dp[now][(j+x)%mod] += dp[pre][j];
			if (dp[now][(j+x)%mod] >= M) {
				dp[now][(j+x)%mod] -= M;
			}
		}
	}
	cout << (dp[now][0]-1+M)%M << endl;
	return 0;
}
