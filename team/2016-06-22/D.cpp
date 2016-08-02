#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>

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
    int n, m, mod = 1e9+7;
    string p;
    while (cin >> n >> m >> p) {
        vector <int> dp(n+1), q(m+1);
        int d = 20, r = m, f = 0, b = 1%r;
        while (r % 5 == 0 || r % 2 == 0) {
            r = (r % 2 == 0 ? r/2 : r);
            r = (r % 5 == 0 ? r/5 : r);
        }
        dp[n] = 1;
        for (int i = n-1; i >= 0 && i+d >= n; i --, b = b*10%r) {
            int now = 0;
            f = (b*(p[i]-'0') + f) % r;
            repi(j, i, n) {
                now = (10*now + p[j]-'0') % m;
                if (now == 0) {
                    dp[i] = (dp[i] + dp[j+1]) % mod;
                }
            }
        }
        vector <int> t(d), B(d);
        rep(i, d) {
            for (int j = d-1; j >= i; j --) {
                t[i] = (t[i]*10 + p[n-j-1]) % m;
            }
        }
        for (int i = d-1, g = 10%m; i >= 0; i --, g = 10*g%m) {
            B[i] = g;
        }
        for (int i = n-d-1; i >= 0; i --, b = b*10%r) {
            f = (b*(p[i]-'0') + f) % r;
            dp[i] = q[f];
            rep(j, d) {
                t[j] = (t[j] + B[j]*(p[i]-'0')) % m;
                if (t[j] == 0) {
                    dp[i] = (dp[i] + dp[n-j-1]) % mod;
                }
                B[j] = 10*B[j] % m;
            }
            q[f] ++;

        }
        cout << dp[0] << "\n";
    }
    return 0;
}
