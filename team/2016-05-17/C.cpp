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


int dp[5005][2];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> h(n);
    repe(&x, h) {
        cin >> x;
    }
    rep(i, n) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        rep(j, i) {
            if (h[j] < h[i]) {
                dp[i][0] = max(dp[i][0], dp[j][1]+1);
            }
        }
        for (int j = i-1, r = 0; j >= 0; j--) {
            if (h[j] > h[i]) {
                dp[j][1] = max(dp[j][1], r+1);
            } else if (h[j] < h[i]) {
                r = max(r, dp[j][1]+1);
            }
        }
    }
    rep(i, n) {
        if (i > 0) {
            cout << " ";
        }
        cout << max(dp[i][0], dp[i][1]);
    }
    cout << "\n";
    return 0;
}
