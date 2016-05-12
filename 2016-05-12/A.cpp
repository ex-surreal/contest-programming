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
    cin >> n;
    vector <int> u(n), v(n), w(n);
    int x = 0, y = 0, z = 0;
    rep(i, n) {
        cin >> u[i] >> v[i] >> w[i];
    }
    vector <string> ans(n, "Yes");
    rep(j, n) {
        rep(i, n) {
            if (i == j) {
                continue;
            }
            x = max(x, u[i]);
            y = max(y, v[i]);
            z = max(z, w[i]);
        }
        if (u[j] <= x && v[j] <= y && w[j] <= z) {
            ans[j] = "No";
        }
    }
    repe(a, ans) {
        cout << a << "\n";
    }
    return 0;
}
