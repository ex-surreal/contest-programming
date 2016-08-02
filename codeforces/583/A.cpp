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
	int n;
	cin >> n;
	vector <bool> l(n, false), r(n, false);
	rep(i, n*n) {
		int x, y;
		cin >> x >> y;
		if (!l[x] && !r[y]) {
			cout << i+1 << " ";
			l[x] = r[y] = true;
		}
	}
	return 0;
}
