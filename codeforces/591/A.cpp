#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
	std::ios_base::sync_with_stdio(false);
	int l, p, q;
	cin >> l >> p >> q;
	cout.precision(10);
	cout.setf(ios::fixed);
	cout << 1.0*l*p/(p+q);
	return 0;
}
