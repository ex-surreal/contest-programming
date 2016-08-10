#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
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

long long dp[2][5005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, s, e;
    cin >> n >> s >> e;
    s --, e --; 
    vector <int> x(n), a(n), b(n), c(n), d(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> d[i];
    int now = 0, pre = 1;
    fill(dp[now], dp[now]+n+2, 1ll<<60);
    dp[now][0] = 0;
    rep(i, n) {
        swap(now, pre);
        fill(dp[now], dp[now]+n+2, 1ll<<60);
        rep(j, n+1) {
            if (i < n-1 && j == 0 && j - (e > i) + (s > i) == 0) {
                continue;
            }
            if (i == s) {
                dp[now][j] = dp[pre][j] +x[i]+c[i];
                if (j > 0) {
                    dp[now][j] = min(dp[now][j], dp[pre][j-1] -x[i]+d[i]);
                }
            } else if (i == e) {
                dp[now][j] = dp[pre][j+1] +x[i]+a[i];
                if (j > 0 || s > i) {
                    dp[now][j] = min(dp[now][j], dp[pre][j] -x[i]+b[i]);
                }
            } else {
                dp[now][j] = dp[pre][j+1] +2*x[i]+a[i]+c[i];
                if (j > 0 && j - (e > i) + (s > i) > 0) {
                    dp[now][j] = min(dp[now][j], dp[pre][j-1] -2*x[i]+b[i]+d[i]);
                }
                if (j - (e > i) + (s > i) > 0) {
                    dp[now][j] = min(dp[now][j], dp[pre][j] +b[i]+c[i]);
                }
                if (j > 0) {
                    dp[now][j] = min(dp[now][j], dp[pre][j] +a[i]+d[i]);
                }
            }
        }
    }
    cout << dp[now][0];
    return 0;
}
