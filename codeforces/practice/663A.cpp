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
    string str;
    getline(cin, str);
    vector <int> ans(1, 1);
    int minus = 0, plus = 1;
    repe(c, str) {
        if (c == '+') {
            ans.pb(1);
            plus ++;
        } else if (c == '-') {
            minus ++;
            ans.pb(-1);
        }
    }
    int n = 0;
    for (int i = sz(str) - 1, b = 1; i >= 0 && str[i] <= '9' && str[i] >= '0'; i --) {
        n = n + b*(str[i]-'0');
        b *= 10;
    }
    for (int d = minus; d <= n*minus; d ++) {
        if (plus <= n+d && n+d <= plus*n) {
            cout << "Possible\n";
            int a = n+d-plus, b = d-minus;
            for (int i = 0; i < sz(ans); i ++) {
                if (ans[i] > 0 && a > 0) {
                    int t = min(n-1, a);
                    a -= t;
                    ans[i] += t;
                } else if (ans[i] < 0 && b > 0) {
                    int t = min(n-1, b);
                    b -= t;
                    ans[i] -= t;
                }
            }
            rep(i, sz(ans)) {
                if (i > 0) {
                    cout << (ans[i] > 0 ? " + " : " - ");
                }
                cout << abs(ans[i]);
            }
            cout << " = " << n << "\n";
            return 0;
        }
    }
    cout << "Impossible\n";
    return 0;
}
