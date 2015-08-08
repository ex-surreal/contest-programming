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

int small[1000006];

void sieve(int n = 1000006) {
	for (int i = 4; i < n; i += 2) {
		small[i] = 2;
	}
	for (int i = 3; i*i < n; i += 2) {
		if (small[i] == 0) {
			for (int j = i*i; j < n; j += 2*i) {
				if (small[j] == 0) {
					small[j] = i;
				}
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (small[i] == 0) {
			small[i] = i;
		}
	}
}

int dp[1000006];

int main () {
	std::ios_base::sync_with_stdio(false);
	sieve();
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		dp[a]++;
	}
	repi(i, 2, 1000006) {
		int t = i, cnt = dp[i];
		while (t > 1) {
			int d = small[t];
			dp[i] = max(dp[i], dp[i/d]+cnt);
			while (t % d == 0) {
				t /= d;
			}
		}
	}
	cout << *max_element(dp, dp+1000006) << endl;
	return 0;
}
