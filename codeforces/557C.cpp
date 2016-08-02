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

class Solver {
private:
	vector <pair <int, int> > P;
public:
	Solver(vector <int> &l, vector <int> &d) {
		rep (i, sz(l)) {
			P.pb(mp(l[i], d[i]));
		}
	}

	int solve() {
		int ret = INT_MAX;
		sort(P.begin(), P.end());
		vector <int> cnt(201, 0);
		int tot = 0;
		rep (i, sz(P)) {
			tot += P[i].y;
		}
		rep (i, sz(P)) {
			int c = 0;
			while (i+c < sz(P) && P[i+c].x == P[i].x) {
				tot -= P[i+c].y;
				c++;
			}
			i = i+c-1;
			int rem = max(0, i + 2 - 2*c), sum = tot;
			rep(j, 201) {
				if (rem < cnt[j]) {
					sum += rem * j;
					break;
				}
				rem -= cnt[j];
				sum += cnt[j] * j;
			}
			ret = min(ret, sum);
			repi (j, i-c+1, i+1) {
				cnt[P[j].y] ++;
			}
		}
		return ret;
	}
};

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> l(n), d(n);
	rep (i, n) {
		cin >>l[i];
	}
	rep (i, n) {
		cin >> d[i];
	}

	Solver solver = Solver(l, d);
	cout << solver.solve();
	return 0;
}
