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

void median(vector<char> s,vector<int> X) {
	multiset <pair <int, int> > S;
	int t = 0, m = -1;
	rep(i, sz(s)) {
		if (s[i] == 'a') {
			S.insert(mp(X[i], i));
			t++;
			if (t == 1) {
				m = i;
				continue;
			}
			if (m <= X[i]) {
				if (t&1) {
					multiset <pair <int, int> > it = S.find(mp(X[m], m));
					it++;
					m = it->y;
				}
			} else {
				if (!(t&1)) {
					multiset <pair <int, int> > it = S.find(mp(X[m], m));
					it--;
					m = it->y;
				}
			}
		} else if (t > 0) {
			multiset <pair <int, int> > it = S.lower_bound(mp(X[i], -1));
			if (it != S.end()) {
				if (X[i] <= X[m]) {
					
				}
			}
			if (t&1) {
				cout << X[m] << "\n";
			} else {
				it = S.find(mp(X[m], m));
				it++;
				int s = X[m] + it->x;
				cout << s/2;
				if (s&1) {
					cout << ".5"
				}
				cout << "\n";
			}
		} else {
			cout << "Wrong!\n";
		}
	}
}

int main(void) {
	int N;
	cin >> N;
	vector<char> s;
	vector<int> X;
	char temp;
	int tempint;
	for(int i = 0; i < N; i++){
	  cin >> temp >> tempint;
		s.push_back(temp);
		X.push_back(tempint);
	}
	median(s,X);
	return 0;
}