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

string a, b;

bool isSame(int p, int q, int r, int s) {
	for (int i = p, j = r; i <= q; i++, j++) {
		if (a[i] != b[j]) {
			return false;
		}
	}
	return true;
}

bool isEquivalent(int p, int q, int r, int s) {
	if (p > q) {
		return true;
	}
	if (isSame(p, q, r, s)) {
		return true;
	}
	if ((q-p+1)%2) {
		return false;
	}
	return isEquivalent(p, (p+q)/2, r, (r+s)/2) && isEquivalent((p+q)/2+1, )
}

int main () {
	std::ios_base::sync_with_stdio(false);
	
	return 0;
}
