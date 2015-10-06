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

template <class x, class y> ostream & operator << (ostream &o, pair <x, y> p) {
	o << "(" << p.first << ", " << p.y << ")";
	return o;
}
template <class x> ostream & printAll(ostream &o, x v, string a, string b) {
	o << a;
	for (__typeof(v.begin()) i = v.begin(); i != v.end(); i++) {
		if (i != v.begin()) {
			o << ", ";
		}
		o << *i;
	}
	o << b;
	return o;
}
template <class x> ostream & operator << (ostream &o, vector <x> v) {
	return printAll(o, v, "{", "}");
}
template <class x> ostream & operator << (ostream &o, set <x> v) {
	return printAll(o, v, "[", "]");
}
template <class x> ostream & operator << (ostream &o, multiset <x> v) {
	return printAll(o, v, "[", "]");
}
template <class x, class y> ostream & operator << (ostream &o, map <x, y> v) {
	return printAll(o, v, "[", "]");
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map <int, int> c;
	rep(i, n*n) {
		int x;
		cin >> x;
		c[-x]++;
	}
	vector <int> ans;
	for (pair <const int, int> &p: c) {
		while (p.y > 0) {
			ans.pb(-p.x);
			rep(i, sz(ans)) {
				c[-__gcd(-p.x, ans[i])] -= 2;
			}
		}
	}
	for (int e: ans) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
