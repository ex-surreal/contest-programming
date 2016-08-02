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
	cout.precision(10);
	cout.setf(ios::fixed);
	int a, b;
	cin >> a >> b;
	if (b > a) {
		cout << -1;
		return 0;
	}
	if (a == b) {
		cout << 1.0*a;
		return 0;
	}
	int k1 = (a-b)/(2*b);
	double x1 = 1e15;
	if (k1 != 0) {
		x1 = 0.5*(a-b)/k1;
	}
	int k2 = (a+b)/(2*b) - 1;
	double x2 = 0.5*(a+b)/(k2+1);
	cout << min(x1, x2);
	return 0;
}
