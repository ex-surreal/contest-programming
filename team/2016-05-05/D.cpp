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

int phi(int n) {
    int t = n, r = 1, u = 1;
    for (int p = 2; p*p <= t; p ++) {
        if (t % p != 0) {
            continue;
        }
        r *= p;
        u *= p-1;
        while (t % p == 0) {
            t /= p;
        }
    }
    if (t > 1) {
        u *= t-1;
        r *= t;
    }
    return n/r*u;
}

int dp[10005] = {0, 2};

int main () {
    std::ios_base::sync_with_stdio(false);
    repi(i, 2, 10005) {
        dp[i] = dp[i-1] + phi(i);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int cas, n;
        cin >> cas >> n;
        cout << cas << " " << dp[n] << "\n";
    }
    return 0;
}
