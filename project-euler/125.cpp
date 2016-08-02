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

bool isPalindrom(int n) {
	int b = 0, a = n;
	while (a > 0) {
		b = 10*b+a%10;
		a /= 10;
	}
	return n == b;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set <int> st;
	for (int i = 1; i*i <= n; i++) {
		for (int j = i+1, sum = i*i; sum + j*j <= n; j++) {
			sum += j*j;
			if (isPalindrom(sum)) {
				st.insert(sum);
			}
		}
	}
	long long ans = 0;
	repe (i, st) {
		ans += *i;
	}
	cout << ans << endl;
	return 0;
}
