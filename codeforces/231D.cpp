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
    int x, y, z, a, b, c;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int s[6];
    repe(&q, s) {
        cin >> q;
    }
    int ans = 0;
    if (b < 0) {
        ans += s[0];
    } else if (b > y) {
        ans += s[1];
    }
    if (c < 0) {
        ans += s[2];
    } else if (c > z) {
        ans += s[3];
    }
    if (a < 0) {
        ans += s[4];
    } else if (a > x) {
        ans += s[5];
    }
    cout << ans;
    return 0;
}
