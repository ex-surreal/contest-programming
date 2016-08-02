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
    vector <int> a(n);
    int maxY = 0, minY = 0;
    int x = 0, y = 0;
    rep(i, n) {
        cin >> a[i];
        x += a[i];
        if (i&1) {
            y -= a[i];
        } else {
            y += a[i];
        }
        if (y > 0) {
            maxY = max(maxY, y);
        } else {
            minY = max(minY, -y);
        }
    }
    vector <string> ans(minY+maxY, string(x, ' '));
    x = 0, y = maxY - 1;
    int f = -1;
    rep(i, n) {
        while (a[i] --) {
            ans[y][x] = (f == -1 ? '/' : '\\');
            x ++, y += f;
        }
        y -= f;
        f *= -1;
    }
    repe(a, ans) {
        cout << a << "\n";
    }
    return 0;
}
