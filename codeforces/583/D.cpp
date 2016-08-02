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

int lis(vector <int> a, int s, int r) {
	int n = sz(a);
	vector <int> I(n+1, 1<<30), L(n);
	I[0] = -(1<<30);
	int k = 0;
	for(int i = 0; i < n; i++ ) {
		int low = 0, high = k;
		while(low <= high) {
			int mid = (low + high) / 2;
			if(I[mid] <= a[i]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		I[low] = a[i];
		L[i] = low;
		if(k < low) {
			k = low;
		}
	}
	int ret = k, l = -1;
	for (int i = 0; i < s; i++) {
		int id = n-1-i;
		if (k == L[id] && (l == -1 || l == a[id])) {
			k--;
			l = a[id];
			ret += r;
		}
	}
	return ret;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, T;
	cin >> n >> T;
	vector <int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	int c = T;
	int r = 0;
	if (n*T > 1000000) {
		c = 1000000/n;
		r = T-c;
	}
	vector<int> v;
	rep(i, c) {
		rep(j, sz(a)) {
			v.pb(a[j]);
		}
	}
	// rep(i, sz(v)) {
	// 	cout << v[i] << " ";
	// } cout << endl;
	cout << lis(v, n, r) << endl;
	return 0;
}
