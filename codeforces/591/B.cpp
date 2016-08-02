#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	string p;
	cin >> n >> m >> p;
	list<int> replace[26];
	for (int i = 0; i < int(n); i ++) {
		replace[p[i] - 'a'].pb(i);
	}
	for (int i = 0; i < int(m); i ++) {
		string a, b;
		cin >> a >> b;
		replace[a[0]-'a'].swap(replace[b[0] - 'a']);
	}
	for (int i = 0; i < int(26); i ++) {
		for (auto x: replace[i]) {
			p[x] = 'a' + i;
		}
	}
	cout << p;
	return 0;
}
