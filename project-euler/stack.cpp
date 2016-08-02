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

vector <list <int> > S;

int main () {
	std::ios_base::sync_with_stdio(false);
	int tst;
	cin >> tst;
	repi(cas, 1, tst+1) {
		cout << "Case " << cas << ":\n";
		int n, q;
		cin >> n >> q;
		S.clear();
		S.resize(n);
		rep(i, q) {
			string op;
			cin >> op;
			int x, y;
			if (op == "push") {
				cin >> x >> y;
				S[x-1].push_back(y);
			} else if (op == "pop") {
				cin >> x;
				if (S[x-1].begin() != S[x-1].end()) {
					S[x-1].pop_back();
				}
			} else if (op == "put") {
				cin >> x >> y;
				S[x-1].splice(S[x-1].end(), S[y-1]);
			} else {
				cin >> x;
				if (S[x-1].begin() != S[x-1].end()) {
					cout << S[x-1].back() << "\n";
				} else {
					cout << "Empty!\n";
				}
			}
		}
	}
	return 0;
}
