#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <vector <int> > S(n, vector <int>(n));
    repe(&r, S) {
        repe(&c, r) {
            cin >> c;
        }
    }
    vector <int> a(n);
    if (n > 2) {
        a[0] = (S[0][1]-S[1][2]+S[0][2])/2;
        repi(i, 1, n) {
            a[i] = S[0][i] - a[0];
        }
    } else {
        a[0] = a[1] = 1;
    }
    string sp = "";
    repe(x, a) {
        assert(x != 0);
        cout << sp << x;
        sp = " ";
    }
    cout << "\n";
    return 0;
}
