#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

string printN(string a, int n) {
	string ret = "";
	for (int i = 0; i < int(n); i ++) {
		if (i > 0) {
			ret += " ";
		}
		ret += a;
	}
	return ret;
}

#define tostr(a) (a == 1? "1": "0")

int solve(vector <int> &arr, string &ans) {
	if ((*arr.begin()) ^ arr.back()) {
		ans = printN(tostr(*arr.begin()), arr.size()/2) + " " + printN(tostr(arr.back()), arr.size()/2);
	} else {
		ans = printN(tostr(arr.back()), arr.size());
	}
	return int(arr.size()/2 + arr.size()%2) - 1;
}

int main () {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < int(n); i ++) {
		cin >> a[i];
	}
	string sp = "", str = "";
	int ans = 0;
	for (int i = 0; i < int(a.size()); i ++) {
		if (str != "") {
			sp = " ";
		}
		if (i+1 < int(a.size()) && a[i] != a[i+1]) {
			vector <int> arr;
			while (i+1 < int(a.size()) && a[i] != a[i+1]) {
				arr.pb(a[i]);
				i ++;
			}
			arr.pb(a[i]);
			string ret = "";
			ans = max(ans, solve(arr, ret));
			str += sp + ret;
		} else {
			str += sp + tostr(a[i]);
		}
	}
	cout << ans << endl << str << endl;
	return 0;
}
