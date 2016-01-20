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

template<class type> type pwr(type base, type expo, type mod) {
	type ret(1);
	while (expo > 0) {
		if (expo&1) {
			ret = 1ll*ret*base%mod;
		}
		base = 1ll*base*base%mod;
		expo >>= 1;
	}
	return ret;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int prime = 1e9+21;
	vector <int> div;
	for (int i = 2; i*i <= prime-1; i++) {
		if ((prime-1) % i == 0) {
			div.pb(i);
			if (i != (prime-1)/i) {
				div.pb((prime-1)/i);
			}
		}
	}
	sort(div.begin(), div.end());
	std::vector<int> ans;
	repi(i, 1, prime) {
		rep(j, sz(div)) {
			if (pwr(i, div[j], prime) == 1) {
				goto hell;
			}
		}
		cout << "ans: " << i << endl;
		return 0;
		hell:;
	}
	cout << "ans(" << sz(ans) << "): ";
	repe(i, ans) {
		cout << *i << " ";
	} cout << endl;
	return 0;
}
