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

int mod = 1e9+7;

int pwr(int base, int exp, int mod) {
	int ret = 1;
	while (exp > 0) {
		if (exp&1) {
			ret = 1ll*ret*base % mod;
		}
		base = 1ll*base*base % mod;
		exp >>= 1;
	}
	return ret;
}

int fact[200005] = {1};
int inv[200005];

int C(int n, int r) {
	return 1ll*fact[n]*inv[r]%mod*inv[n-r]%mod;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	repi(i, 1, 200002) {
		fact[i] = 1ll*i*fact[i-1]%mod;
	}
	rep(i, 200002) {
		inv[i] = pwr(fact[i], mod-2, mod);
	}
	int h, w, n;
	cin >> h >> w >> n;
	h--, w--;
	vector <pair <int, int> > P(n);
	rep(i, n) {
		cin >> P[i].x >> P[i].y;
		P[i].x--, P[i].y--;
	}
	sort(P.begin(), P.end());
	vector <int> res(n, 0);
	rep(i, n) {
		res[i] = C(P[i].x+P[i].y, P[i].y);
		rep(j, i) {
			int x = P[i].x-P[j].x;
			int y = P[i].y-P[j].y;
			if (x >= 0 && y >= 0) {
				res[i] -= 1ll*C(x+y, y)*res[j]%mod;
				if (res[i] < 0) {
					res[i] += mod;
				}
			}
		}
	}
	int ans = C(h+w, w);
	rep(i, n) {
		int dx = h - P[i].x;
		int dy = w - P[i].y;
		ans -= 1ll*C(dx+dy, dy)*res[i]%mod;
		if (ans < 0) {
			ans += mod;
		}
	}
	cout << ans << endl;
	return 0;
}
