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

int limit[3005][3005];
int dp[3005][3005];
int range[3005][3005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <long long> banana(n+1);
    repi(i, 1, n+1) {
        cin >> banana[i];
    }
    reverse(banana.begin()+1, banana.end());
    repi(i, 1, n+1) {
        banana[i] += banana[i-1];
    }
    limit[0][1] = n;
    repi(i, 1, n+1) {
        repi(j, i+1, n+1) {
            int high = n, low = j;
            while (low <= high) {
                int mid = (high+low)>>1;
                if (banana[mid] - banana[j-1] > banana[j-1] - banana[i-1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            limit[i][j] = high;
        }
    }
    for (int i = n; i > 0; i --) {
        range[i][i] = INT_MIN;
        repi(j, i+1, n+1) {
            if (limit[i][j]+1 > j) {
                dp[i][j] = range[j][limit[i][j]+1]+1;
            } else {
                dp[i][j] = INT_MIN;
            }
            range[i][j] = max(dp[i][j], range[i][j-1]);
        }
        dp[i][n+1] = 1;
        range[i][n+1] = max(dp[i][n+1], range[i][n]);
    }
    int ans = 0;
    repi(i, 2, n+2) {
        ans = max(dp[1][i], ans);
    }
    cout << ans << "\n";
    return 0;
}
