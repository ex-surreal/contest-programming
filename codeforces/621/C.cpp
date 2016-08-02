#include <bits/stdc++.h>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for(int i = 0; i < int(n); i ++)
#define repi(i, a, n) for(int i = int(a); i < int(n); i ++)

double dp[100005][2][2];
bool seen[100005][2][2];
double p[100005];
int N;

double solve(int n, int l, int o) {
    if (n == N-1) {
        return ((l == 0 ? 2000 : 0) + 2000)*p[n] + (o == 1 ? 2000 : 0)*(1-p[n]);
    }
    if (!seen[n][l][o]) {
        seen[n][l][o] = true;
        dp[n][l][o] = solve(n+1, 0, o)*(1 - p[n]);
        dp[n][l][o] += (2000 + (l == 0 ? 2000 : 0) + solve(n+1, 1, o))*p[n];
    }
    return dp[n][l][o];
}

int main () {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> N >> q;
    rep (i, N) {
        int l , r;
        cin >> l >> r;
        p[i] = 1.0*(r/q - (l-1)/q) / (r-l+1);
    }
    double ans = (solve(1, 1, 1) + 2000)*p[0] + solve(1, 0, 0)*(1-p[0]);
    cout.precision(10);
    cout.setf(ios::fixed);
    cout << ans;
    return 0;
}
