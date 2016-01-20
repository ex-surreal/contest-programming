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

// char mem[(1u<<31)-1];

int limit = 1e9+21;

int main () {
	// std::ios_base::sync_with_stdio(false);
	freopen("out67.txt", "w", stdout);
	int r = 5765;
	printf("%d\n", limit-2);
	int two = 2;
	repi(i, 1, r) {
		printf("%d\n", two);
		two = two + two;
		if (two >= limit) {
			two -= limit;
		}
	}
	int rem = two;
	repi(i, r+1, limit) {
		two = two + two;
		if (two >= limit) {
			two -= limit;
		}
		printf("%d\n", two);
	}
	cerr << rem << endl;
	return 0;
}
