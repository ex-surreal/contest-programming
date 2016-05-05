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

int dp[50];
int m, k;

int solve(int n) {
    if (n == 0) {
        return 1;
    }
    int &ret = dp[n];
    if (ret == -1) {
        ret = 0;
        repi(i, 1, n+1) {
            if ((i-m)%k) {
                ret += solve(n-i);
            }
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int cas, n;
        cin >> cas >> n >> m >> k;
        mem(dp, -1);
        cout << cas << " " << solve(n) << "\n";
    }
    return 0;
}
