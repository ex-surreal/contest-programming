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

#define eps 1e-9

bool isPossible(long double a, long double b, long double c, long double d, long double k) {
	long double minX = 1e20, maxX = -1e20, minY = 1e20, maxY = -1e20;
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			minX = min(minX, (a+i*k)*(d+j*k));
			maxX = max(maxX, (a+i*k)*(d+j*k));
			minY = min(minY, (b+i*k)*(c+j*k));
			maxY = max(maxY, (b+i*k)*(c+j*k));
		}
	}
	return (minX - eps <= minY && minY <= maxX + eps) || (minX - eps <= maxY && maxY <= maxX + eps);
}

int main () {
	std::ios_base::sync_with_stdio(false);
	long double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout.precision(10);
	cout.setf(ios::fixed);
	// cerr.precision(20);
	// cerr.setf(ios::fixed);
	long double low = 0, high = max(max(a, b), max(c, d));
	while (fabs(low-high) > eps) {
		long double mid = (low+high) / 2;
		// cerr << low << " " << high << " " << mid << " " << low+high << endl;
		if (isPossible(a, b, c, d, mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << low;
	return 0;
}
