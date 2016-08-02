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
    long long s, x;
    cin >> s >> x;
    if (s < x) {
        cout << 0;
        return 0;
    }
    long long d = s-x;
    int l = 0;
    while (d > 0) {
        if (d&1ll) {
            if (!(l-1 >= 0 && ((1ll << (l-1))&x) == 0)) {
                cout << 0;
                return 0;
            }
        }
        d >>= 1;
        l ++;
    }
    cout << ((1ll << __builtin_popcountll(x)) -(s-x == 0ll)*2);
    return 0;
}
