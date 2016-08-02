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

int dp[2][505][505];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, g;
    cin >> n >> g;
    vector <int> c(n);
    repe(&x, c) {
        cin >> x;
    }
    int now = 0, pre = 1;
    dp[now][0][0] = 1;
    rep(i, n) {
        swap(now, pre);
        rep(j, g+1) {
            rep(k, g+1) {
                dp[now][j][k] = dp[pre][j][k];
                if (c[i] <= j) {
                    dp[now][j][k] |= dp[pre][j-c[i]][k];
                    if (c[i] <= k) {
                        dp[now][j][k] |= dp[pre][j-c[i]][k-c[i]];
                    }
                }
            }
        }
    }
    vector <int> a;
    rep(i, g+1) {
        if (dp[now][g][i]) {
            a.pb(i);
        }
    }
    cout << sz(a) << "\n";
    repe(e, a) {
        cout << e << " ";
    }
    return 0;
}
