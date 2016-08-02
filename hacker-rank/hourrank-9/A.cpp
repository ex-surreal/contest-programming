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

int dp[1005][2][2];
vector <int> a;

int solve(int i, int j, int k) {
    if (i == -1) {
        return (j || k) ? 1<<29 : 0;
    }
    int &ret = dp[i][j][k];
    if (ret == -1) {
        if (j) {
            ret = solve(i-1, (a[i]+k+1)&1, 0) + 2;
        } else {
            ret = min(solve(i-1, (a[i]+k)&1, 0), solve(i-1, (a[i]+k+1)&1, 1)+2);
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    a.resize(n);
    repe(&e, a) {
        cin >> e;
    }
    mem(dp, -1);
    int ans = solve(n-1, 0, 0);
    if (ans > 1000000) {
        cout << "NO";
    } else {
        cout << ans;
    }
    return 0;
}
