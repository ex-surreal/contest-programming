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

int mod = 1e9+7;
int fact[100006] = {1};

int pwr(int b, int e) {
    int ret = 1;
    while (e > 0) {
        if (e&1) {
            ret = 1ll*ret*b%mod;
        }
        b = 1ll*b*b%mod;
        e >>= 1;
    }
    return ret;
}

int C(int n, int r) {
    return 1ll*fact[n]*pwr(fact[r], mod-2)%mod*pwr(fact[n-r], mod-2)%mod;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    repi(i, 1, 100006) {
        fact[i] = 1ll*i*fact[i-1]%mod;
    }
    int tst;
    cin >> tst;
    while (tst --) {
        int n, k;
        cin >> n >> k;
        int z = 0;
        rep(i, n) {
            int x;
            cin >> x;
            z += x == 0;
        }
        int ans = 0;
        if (z) {
            ans = pwr(2, n-z);
        } else {
            for (int i = k&1; i <= k && i <= n; i += 2) {
                ans += C(n, i);
                ans %= mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
