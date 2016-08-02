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
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (n == 4 || k < n+1) {
        cout << -1;
        return 0;
    }
    cout << a << " " << c;
    repi(i, 1, n+1) {
        if (i != a && i != b && i != c && i != d) {
            cout << " " << i;
        }
    }
    cout << " " << d << " " << b << "\n";
    cout << c << " " << a;
    repi(i, 1, n+1) {
        if (i != a && i != b && i != c && i != d) {
            cout << " " << i;
        }
    }
    cout << " " << b << " " << d << "\n";
    return 0;
}
