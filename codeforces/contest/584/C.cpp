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

char getDiffChar(char a, char b) {
	if (a != 'a' && b!= 'a') {
		return 'a';
	}
	if (a != 'b' && b!= 'b') {
		return 'b';
	}
	return 'c';
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	string a, b;
	cin >> a >> b;
	int dif = 0;
	rep(i, n) {
		dif += int(a[i] != b[i]);
	}
	string ans = string(n, '*');
	if (t >= dif) {
		rep(i, n) {
			if (t == 0) {
				break;
			}
			if (a[i] != b[i]) {
				ans[i] = getDiffChar(a[i], b[i]);
				t--;
			}
		}
		rep(i, n) {
			if (t == 0) {
				break;
			}
			if (a[i] == b[i]) {
				ans[i] = getDiffChar(a[i], b[i]);
				t--;
			}
		}
		rep(i, n) {
			if (ans[i] == '*') {
				ans[i] = a[i];
			}
		}
	} else if (t >= dif/2+dif%2) {
		int r = 2*t - dif;
		rep(i, n) {
			if (r == 0) {
				break;
			}
			if (a[i] != b[i]) {
				ans[i] = getDiffChar(a[i], b[i]);
				r--;
			}
		}
		// cout << ans << endl;
		int k = t - (2*t - dif);
		rep(i, n) {
			if (k == 0) {
				break;
			}
			if (ans[i] == '*' && a[i] != b[i]) {
				ans[i] = b[i];
				k--;
			}
		}
		// cout << ans << endl;
		k = t - (2*t - dif);
		rep(i, n) {
			if (k == 0) {
				break;
			}
			if (ans[i] == '*' && a[i] != b[i]) {
				ans[i] = a[i];
				k--;
			}
		}
		// cout << ans << endl;
		rep(i, n) {
			if (ans[i] == '*') {
				ans[i] = a[i];
			}
		}
	} else {
		ans = "-1";
	}
	cout << ans;
	return 0;
}
