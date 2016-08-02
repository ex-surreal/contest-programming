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

bool isPrime(int n) {
	if (n == 2) {
		return false;
	}
	if (n%2 == 0) {
		return false;
	}
	for (int i = 3; 1ll*i*i <= n; i += 2) {
		if (n %i == 0) {
			return false;
		}
	}
	return true;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (isPrime(n)) {
		cout << 1 << "\n";
		cout << n << endl;
		return 0;
	}
	if (isPrime(n - 2)) {
		cout << 2 << "\n";
		cout << n-2 << " " << 2 << endl;
		return 0;
	}
	if (isPrime(n - 4)) {
		cout << 3 << "\n";
		cout << n-4 << " " << "2 2" << endl;
		return 0;
	}
	for (int i = 6;; i += 2) {
		if (isPrime(n - i)) {
			cout << 3 << endl;
			cout << n-i << " ";
			for (int j = 3; j < i ; j += 2) {
				if (isPrime(j) && isPrime(i-j)) {
					cout << i-j << " " << j << endl;
					return 0;
				}
			}
			return 0;
		}
	}
	return 0;
}
