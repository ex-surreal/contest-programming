#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
	std::ios_base::sync_with_stdio(false);
	string str[8];
	for (int i = 0; i < 8; i ++) {
		cin >> str[i];
	}
	int a = 8, b = 8;
	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 8; j ++) {
			if (str[i][j] == 'W') {
				bool f = true;
				for (int k = 0; k < i; k ++) {
					if (str[k][j] != '.') {
						f = false;
						break;
					}
				}
				if (f) {
					a = min(a, i);
				}
			}
		}
	}
	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 8; j ++) {
			if (str[i][j] == 'B') {
				bool f = true;
				for (int k = i+1; k < 8; k ++) {
					if (str[k][j] != '.') {
						f = false;
						break;
					}
				}
				if (f) {
					b = min(b, 7-i);
				}
			}
		}
	}
	if (a < b) {
		cout << "A";
	} else {
		cout << "B";
	}
	return 0;
}