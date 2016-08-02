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
	int k;
	cin >> k;
	if (k % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << 4*k-2 << " " << 2*(k-1)*(k-1) + 2*(k-1) + (k-1) + 1<< "\n";
	repi(i, 1, k) {
		repi(j, 1, k) {
			cout << i << " " << k+j-1 << "\n";
			cout << 2*k+i << " " << 3*k+j-1 << "\n";
		}
	}
	cout << 2*k-1 << " " << 2*k << "\n";
	repi(i, 1, k) {
		cout << 2*k-1 << " " << i+k-1 << "\n";
		cout << 2*k << " " << 2*k+i << "\n";
	}
	for (int i = 1; i < k-1; i += 2) {
		cout << i << " " << i+1 << "\n";
		cout << 3*k+i-1 << " " << 3*k+i << "\n";
	}
	return 0;
}
