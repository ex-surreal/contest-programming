#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int solve(vector <int> &a, int p, int q, int y) {
    vector <int> l(sz(a));
    int g = 0;
    for (int i = 0; i < sz(a); i ++) {
        g = __gcd(g, a[i]);
        l[i] = g;
    }
    g = 0;
    int ret = 0, k = 1;
    for (int i = sz(a) - 1; i >= 0; i--) {
        if (__gcd(g, a[i]) == 1) {
            if (k == 1) {
                k = 0;
                if (__gcd(g, a[i]+y) != 1) {
                    g = __gcd(g, a[i]+y);
                    ret += q;
                    continue;
                }
            }
            if (k == 0) {
                int j = i;
                while (j >= 0 && __gcd(l[j], g) == 1) {
                    j --;
                }
                ret += (i-j)*p;
                break;
            }
        }
    }
}

int main () {
	std::ios_base::sync_with_stdio(false);
	return 0;
}
