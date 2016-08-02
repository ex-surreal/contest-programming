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

int dp[2][5005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector <int> s(n);
    repe(&d, s) {
        double x;
        cin >> d >> x;
        d --;
    }
    int now = 0, pre = 1;
    rep(i, n) {
        swap(now, pre);
        rep(j, m) {
            dp[now][j] = dp[pre][j] + int(s[i] != j);
            if (j > 0) {
                dp[now][j] = min(dp[now][j], dp[now][j-1]);
            }
        }
    }
    cout << *min_element(dp[now], dp[now]+m);
    return 0;
}
