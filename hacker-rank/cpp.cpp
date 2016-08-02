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


int random(int n) {
	static unsigned int seed = 0;
	int a = n/3 + int(n%3 > 0);
	int b = n/2 + int(n%2 > 0);
	int ret = (1ll*a*seed + b)%n;
	seed ++;
	// cout << a << " " << b << endl;
	return ret;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	// freopen("out.txt", "w", stdout);
	multiset <int> s;
	rep(i, 10) {
		cout << random(1000) << endl;
	}
	for (auto a: s) {
		cout << a << " ";
	} cout << endl;
	return 0;
}