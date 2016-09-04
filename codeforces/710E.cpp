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

long long dp[10000007];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    rep(i, n) {
        dp[i+1] = dp[i]+x;
        if (i&1) {
            dp[i+1] = min(dp[i+1], dp[(i+1)>>1]+y);
        }
    }
    cout << dp[n];
    return 0;
}
