#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long x1, x2;
	cin >> x1 >> x2;
	vector <pair <int, int> > v(n), s;
	for (int i = 0; i < n; i ++) {
		long long m, c;
		cin >> m >> c;
		v[i] = mp(m*x1+c, m*x2+c);
	}
	sort(v.begin(), v.end());
	string ans = "NO";
	for (int i = 0; i < sz(s); i ++) {
		int j = i;
		while (j < n && v[j].x < v[i].y) {
			j++;
		}
		if (j < n && v[j].x < v[i].y) {
			ans = "YES";
		}
		i = j-1;
	}
	cout << ans;
	return 0;
}