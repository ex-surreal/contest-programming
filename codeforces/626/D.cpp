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

int dp[2][20005][3][3];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a(n);
    repe(&x, a) {
        cin >> x;
    }
    sort(all(a));
    int now = 0, pre = 1;
    dp[now][0][0][0] = 1;
    rep(i, n) {
        swap(now, pre);
        repi(j, -10000, 10001) {
            rep(a, 3) {
                rep(b, 3) {
                    dp[now][j][a][b] = 0;
                }
            }
            dp[now][j+10000][2][2] += dp[pre][j+10000+a[i]][1][2];
            dp[now][j+10000][2][2] += dp[pre][j+10000+a[i]][2][1];
            dp[now][j+10000][2][2] += dp[pre][j+10000+2*a[i]][1][2];
            
            dp[now][j+10000][2][1] += dp[pre][j+10000+a[i]][1][1];
            dp[now][j+10000][2][1] += dp[pre][j+10000-a[i]][2][0];
            dp[now][j+10000][2][1] += dp[pre][j+10000][1][0];
            
            dp[now][j+10000][1][2] += dp[pre][j+10000+a[i]][1][1];
            dp[now][j+10000][1][2] += dp[pre][j+10000-a[i]][0][2];
            dp[now][j+10000][1][2] += dp[pre][j+10000][0][1];

            dp[now][j+10000][1][1] += dp[pre][j+10000-a[i]][1][0];
            dp[now][j+10000][1][1] += dp[pre][j+10000-a[i]][0][1];
            dp[now][j+10000][1][1] += dp[pre][j+10000-2*a[i]][0][0];
        }
    }
    return 0;
}
