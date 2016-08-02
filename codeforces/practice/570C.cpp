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

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	set <int> st;
	int ans = 0, last = -1;
	st.insert(-1);
	rep(i, n) {
		if (str[i] != '.') {
			if (i - last - 1 > 1) {
				ans += i - last - 2;
			}
			st.insert(i);
			last = i;
		}
	}
	if (n - last - 1 > 1) {
		ans += n - last - 2;
	}
	st.insert(n);
	// cout << ans << endl;
	rep(i, m) {
		int id;
		string ch;
		cin >> id >> ch;
		if ((ch == "." && str[id-1] != '.') || (ch != "." && str[id-1] == '.')) {
			int f = 1;
			if (ch != ".") {
				st.insert(id-1);
				f = -1;
			}
			set <int> :: iterator x, y;
			x = st.find(id-1);
			int l = 0, r = 0;
			y = x;
			y --;
			l = *x - *y - 1;
			y = x;
			y ++;
			r = *y - *x - 1;
			ans += -f * (max(0, l-1) + max(0, r-1));
			ans += f * (l+r);
			str[id-1] = ch[0];
			if (ch == ".") {
				st.erase(id-1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
