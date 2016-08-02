#include <bits/stdc++.h>

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
    string p;
    cin >> n >> p;
    vector <int> x(1), y(1);
    repe(c, p) {
        int a = x.back();
        int b = y.back();
        switch (c) {
            case 'U':
                b ++;
                break;
            case 'D':
                b --;
                break;
            case 'L':
                a --;
                break;
            case 'R':
                a ++;
                break;
            default:;
        }
        x.pb(a);
        y.pb(b);
    }
    int ans = 0;
    rep(i, sz(x)) {
        rep(j, i) {
            if (x[i] == x[j] && y[i] == y[j]) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}
