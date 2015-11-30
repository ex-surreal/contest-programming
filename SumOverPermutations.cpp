#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int C[1<<12][1<<12];
int two[1<<12];

class SumOverPermutations {
	static const int mod = 1e9+7;
	void calculate(int n) {
		for (int i = 0; i < n + 1; i ++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j ++) {
				C[i][j] = (C[i-1][j]+C[i-1][j-1]) % mod;
			}
		}
		two[0] = 1;
		for (int i = 1; i < n; i ++) {
			two[i] = (two[i-1] + two[i-1]) % mod;
		}
	}
public:
	int findSum(int n) {
		calculate(n+5);
		int ret = 0;
		for (int k = n/2+n%2; k >= 1; k --) {
			for (int m = 2*k-1; m <= n; m ++) {
				int l = m - k;
				int p = k - 1;
				ret = (ret + 1ll*two[l-p]*C[l][p]) % mod;
			}
		}
		return ret;
	}
};

int main() {
	SumOverPermutations sum;
	int input[] = {2, 3, 10, 3900};
	for (auto in: input) {
		cout << sum.findSum(in) << endl;
	}
	return 0;
}