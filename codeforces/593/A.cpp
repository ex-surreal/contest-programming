#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> bit(n, 0), length(n, 0);
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		length[i] = sz(s);
		for (auto x: s) {
			bit[i] |= 1 << (x-'a');
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i ++) {
		for (int j = 0; j < i; j ++) {
			int b = (1<<i) | (1<<j), c = 0;
			for (int i = 0; i < n; i ++) {
				if ((b&bit[i]) == bit[i]) {
					c += length[i];
				}
			}
			ans = max(ans, c);
		}
	}
	cout << ans;
	return 0;
}