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

#include "sieve.h"

vector <int> prime;
vector <long long> sq;
int limit, cnt;

long long back(int i, long long num, int f = 1) {
	if (i == sz(sq)) {
		return 0;
	}
	cnt ++;
	if (1.0*num*sq[i] < (1ll<<limit)) {
		return back(i+1, num*sq[i], f*-1) + f*(1ll<<limit)/(num*sq[i]) + back(i+1, num, f);
	}
	return 0;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	while (cin >> limit) {
		prime = sieve(1<<(limit/2));
		rep (i, sz(prime)) {
			sq.pb(1ll*prime[i]*prime[i]);
		}
		cout << back(0, 1) << endl;
		cout << cnt << endl;
	}
	return 0;
}
