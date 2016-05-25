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

int mod = 1e9+7;

int pwr(int b, int e, int m = mod) {
    if (e == 0) {
        return 1%m;
    }
    int t = pwr(b, e/2, m);
    t = 1ll*t*t%m;
    if (e&1) {
        t = 1ll*t*b%m;
    }
    return t;
}

int fact[600006] = {1};

int func(int a, int c, int m) {
    int ret = 1ll*fact[a+c+m]*pwr(fact[a], mod-2, mod)%mod;
    ret = 1ll*ret*pwr(fact[c], mod-2, mod)%mod;
    ret = 1ll*ret*pwr(fact[m], mod-2, mod)%mod;
    return ret;
}

int dp[100][100][100][3];

int solve(int a, int b, int c, int d) {
    if(a == 0 && b == 0 && c == 0) {
        return 1;
    }
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }
    if (dp[a][b][c][d] == -1) {
        dp[a][b][c][d] = 0;
        dp[a][b][c][d] += solve(a-(d==0), b-(d==1), c-(d==2), (d+1)%3)%mod;
        dp[a][b][c][d] += (a+b+c > 1) * solve(a-(d==0), b-(d==1), c-(d==2), (d+2)%3)%mod;
        dp[a][b][c][d] %= mod;
    }
    return dp[a][b][c][d];
}

int solve(int a, int c, int m) {
    int ans = func(a, c, m);
    if (a > 1) {
        ans -= 1ll*func(a-2, c, m)*(c+m+1)%mod - mod;
        ans %= mod;
    }
    if (c > 1) {
        ans -= 1ll*func(a, c-2, m)*(a+m+1)%mod - mod;
        ans %= mod;
    }
    if (m > 1) {
        ans -= 1ll*func(a, c, m-2)*(a+c+1)%mod - mod;
        ans %= mod;
    }
    if (a > 1 && c > 1) {
        ans += 1ll*func(a-2, c-2, m)*(c-2+m+1)%mod*(a-1+m+1)%mod;
        ans %= mod;
    }
    if (a > 1 && m > 1) {
        ans += 1ll*func(a-2, c, m-2)*(c+m-2+1)%mod*(a-1+c+1)%mod;
        ans %= mod;
    }
    if (c > 1 && m > 1) {
        ans += 1ll*func(a, c-2, m-2)*(a+m-2+1)%mod*(a+c-1+1)%mod;
        ans %= mod;
    }
    if (a > 1 && c > 1 && m > 1) {
        ans -= 1ll*func(a-2, c-2, m-2)*(c-2+m-2+1)%mod*(a-1+m-2+1)%mod*(a-1+c-1+1)%mod - mod;
        ans %= mod;
    }
    return ans;
}

int fun(int a, int b, int c) {
    int ret = 0;
    rep(i, 3) {
        ret += solve(a, b, c, i);
        ret %= mod;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int a, c, m;
    mem(dp, -1);
    cin >> a >> c >> m;
    repi(i, 1, a+c+m+1) {
        fact[i] = 1ll*fact[i-1]*i%mod;
    }
    repi(i, 1, 100) {
        repi(j, 1, 100) {
            repi(k, 1, 100) {
                if (fun(i, j, k) != solve(i, j, k)) {
                    cout << i << ", " << j << ", " << k << endl;
                    cout << fun(i, j, k) << " " << solve(i, j, k) << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
