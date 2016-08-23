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

pair <int, int> dp[2][2009];

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n;
        char s[6];
        scanf("%d%s", &n, s);
        vector <pair <int, int> > p(n);
        rep(i, n) {
            cin >> p[i].x >> p[i].y;
            p[i].y *= -1;
        }
        sort(all(p));
        rep(i, n) {
            p[i].y *= -1;
        }
        int now = 0;
        fill(dp[now], dp[now]+2*n+5, mp(-(1<<30), -(1<<30)));
        if (n&1) {
            if (s[0] == 'J') {
                dp[now][n+1-1] = mp(0, 0);
            } else {
                dp[now][n+1+1] = mp(0, 0);
            }
        } else {
            dp[now][n+1] = mp(0, 0);
        }
        rep(i, n) {
            now ^= 1;
            repi(j, -n, n+1) {
                dp[now][j+n+1] = mp(-(1<<30), -(1<<30));
                dp[now][j+n+1] = max(dp[now][j+n+1], mp(dp[now^1][j+n+1+1].x, dp[now^1][j+n+1+1].y+p[i].x));
                if (j > 0 || (j == 0 && s[0] == 'J')) {
                    dp[now][j+n+1] = max(dp[now][j+n+1], mp(dp[now^1][j-1+n+1].x+p[i].y, dp[now^1][j-1+n+1].y));
                }
                if (dp[now][j+1+n] < mp(0, 0)) {
                    dp[now][j+1+n] = mp(-1, -1);
                }
            }
        }
        printf("%d %d\n", dp[now][n+1].y, dp[now][n+1].x);
    }
    return 0;
}
