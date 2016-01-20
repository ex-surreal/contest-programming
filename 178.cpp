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

long long dp[40][1<<10][10];

long long solve(int id, int msk, int last) {
	if (id == 0) {
		return msk == (1<<10) - 1;
	}
	long long &ret = dp[id][msk][last];
	if (ret == -1) {
		ret = 0;
		if (last-1 >= 0) {
			ret += solve(id-1, msk|(1<<(last-1)), last-1);
		}
		if (last+1 < 10) {
			ret += solve(id-1, msk|(1<<(last+1)), last+1);
		}
	}
	return ret;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	for (int i = 1; i < 10; i++) {
		for (int digit = 1; digit <= 40; digit++) {
			ans += solve(digit - 1, 1<<i, i);
		}
	}
	cout << ans << endl;
	return 0;
}
