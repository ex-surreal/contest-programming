#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <unordered_map>
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

int dp[1005][7008];
int g[1005][7008];
int go[1005][7008];
long long sum[1005][7008];
int id[1000006];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    long long k;
    cin >> n >> k;
    vector <long long> a(n);
    repe(&e, a) {
        cin >> e;
    }
    vector <long long> r;
    for (int d = 1; 1ll*d*d <= k; d ++) {
        if (k % d) {
            continue;
        }
        r.push_back(d);
        if (d != k/d) {
            r.push_back(k/d);
        }
    }
    sort(all(r));
    int sq = sqrt(k);
    rep(i, sz(r)) {
        if (r[i] > sq) {
            break;
        }
        id[r[i]] = i;
    }
    rep(i, n) {
        rep(j, sz(r)) {
            long long t = r[j]/__gcd(a[i], r[j]);
            g[i][j] = (t <= sq ? id[t] : sz(r)-1-id[k/t]);
        }
    }
    mem(dp, -1);
    mem(go, -1);
    dp[0][0] = sum[0][0] = 0;
    repi(i, 1, n+1) {
        rep(j, sz(r)) {
            int k = g[i-1][j];
            if (dp[i-1][j] != -1) {
                dp[i][j] = dp[i-1][j];
                sum[i][j] = sum[i-1][j];
                go[i][j] = j;
            }
            if (dp[i-1][k] == -1) {
                continue;
            }
            if (dp[i][j] == -1 || dp[i][j] > dp[i-1][k]+1 || (dp[i][j] == dp[i-1][k]+1 && sum[i][j] > sum[i-1][k]+a[i-1])) {
                go[i][j] = k;
                dp[i][j] = dp[i-1][k]+1;
                sum[i][j] = sum[i-1][k]+a[i-1];
            }
        }
    }
    if (dp[n][sz(r)-1] == 0) {
        cout << "1\n" << min_element(all(a)) - a.begin()+1;
        return 0;
    }
    cout << dp[n][sz(r)-1] << "\n";
    int i = n, j = sz(r)-1;
    while (i > 0 && go[i][j] != -1) {
        if (go[i][j] != j) {
            cout << i << " ";
        }
        j = go[i][j];
        i --;
    }
    return 0;
}
