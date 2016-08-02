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

long long big = LLONG_MAX;

int main () {
	std::ios_base::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <pair <pair <long long, long long>, int> > event;
	long long pl, pr;
	cin >> pl >> pr;
	rep (i, n - 1) {
		long long l, r;
		cin >> l >> r;
		event.pb(mp(mp(l-pr, r-pl), i));
		pl = l, pr = r;
	}
	rep (i, m) {
		long long a;
		cin >> a;
		event.pb(mp(mp(a, big), i));
	}
	sort(event.begin(), event.end());
	set <pair <long long, int> > active;
	vector <int> ans(n-1, -1);
	rep(i, sz(event)) {
		if (event[i].x.y != big) {
			active.insert(mp(event[i].x.y, event[i].y));
		} else {
			set <pair <long long, int> >::iterator it = active.lower_bound(mp(event[i].x.x, -1));
			if (it != active.end()) {
				ans[it->y] = event[i].y + 1;
				active.erase(*it);
			}
		}
	}
	rep (i, sz(ans)) {
		if (ans[i] == -1) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	rep (i, sz(ans)) {
		cout << ans[i] << " ";
	}
	return 0;
}
