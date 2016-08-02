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
    int dp[2][27] = {0};
    int can[27][27] = {0};
    string p;
    cin >> p;
    int k;
    cin >> k;
    rep(i, k) {
        string q;
        cin >> q;
        can[q[0]-'a'][q[1]-'a'] = 1;
        can[q[1]-'a'][q[0]-'a'] = 1;
    }
    int now = 0, pre = 1;
    rep(i, sz(p)) {
        swap(now, pre);
        rep(j, 27) {
            dp[now][j] = dp[pre][j] + 1;
            if (!can[p[i]-'a'][j]) {
                dp[now][j] = min(dp[now][j], dp[pre][p[i]-'a']);
            }
        }
    }
    cout << dp[now][26];
    return 0;
}
