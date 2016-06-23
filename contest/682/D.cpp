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

int dp[1005][1005][15][2];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    string p, q;
    cin >> p >> q;
    repi(i, 1, n+1) {
        repi(j, 1, m+1) {
            repi(k, 1, s+1) {
                rep(f, 2) {
                    dp[i][j][k][f] = max(
                        dp[i-1][j][k-f][0], dp[i][j-1][k-f][0]
                    );
                    if (p[i-1] == q[j-1]) {
                        dp[i][j][k][f] = max(
                            dp[i][j][k][f], dp[i-1][j-1][k][1] + 1
                        );
                    }
                }
            }
        }
    }
    cout << dp[n][m][s][0];
    return 0;
}
