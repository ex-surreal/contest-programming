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

int dp[20][100005];
vector <int> cmp;

void make() {
    rep(i, sz(cmp)) {
        dp[0][i] = i;
    }
    for (int j = 1; (1<<j) <= sz(cmp); j ++) {
        for (int i = 0; i+(1<<j)-1 < sz(cmp); i ++) {
            if (cmp[dp[j-1][i]] > cmp[dp[j-1][i+(1<<(j-1))]]) {
                dp[j][i] = dp[j-1][i];
            } else {
                dp[j][i] = dp[j-1][i+(1<<(j-1))];
            }
        }
    }
}

int get_min(int i, int j) {
    int d = 31-__builtin_clz(j-i+1);
    if (cmp[dp[d][i]] > cmp[dp[d][j-(1<<d)+1]]) {
        return dp[d][i];
    } else {
        return dp[d][j-(1<<d)+1];
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cmp.resize(n, n-1);
    rep(i, n-1) {
        cin >> cmp[i];
        cmp[i] --;
    }
    make();
    vector <long long> dp(n, 0);
    long long ans = dp.back();
    for (int i = n-2; i >= 0; i --) {
        int m = get_min(i+1, cmp[i]);
        dp[i] = dp[m] + n-i-1 - (cmp[i]-m);
        ans += dp[i];
    }
    cout << ans;
    return 0;
}
