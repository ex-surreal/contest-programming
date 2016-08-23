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

long long H[105][10005];
long long R[105][10005];
long long D[105][10005];
long long dp[105][10005];
long long W[105][10005];

int main () {
    int n, m, K;
    while (scanf("%d%d%d", &n, &m, &K) != EOF && n) {
        rep(i, n+1) {
            rep(j, m) {
                scanf("%lld", &H[i+1][j+1]);
            }
        }
        repi(i, 1, n+2) {
            R[i][m] = 0;
            for (int j = m-1; j >= 0; j --) {
                R[i][j] = R[i][j+1]+H[i][j+1];
            }
        }
        rep(i, n+1) {
            rep(j, m) {
                H[i+1][j+1] += H[i+1][j];
            }
        }
        rep(i, n+1) {
            rep(j, m) {
                scanf("%lld", &D[i+1][j+1]);
            }
        }
        repi(i, 1, n+2) {
            long long d = 0;
            deque <int> Q;
            Q.push_back(0);
            W[i][0] = dp[i-1][0];
            for (int j = 1, k = 0; j <= m; j ++) {
                d += D[i][j];
                while (k < j && d > K) {
                    if (!Q.empty() && Q.front() <= k) {
                        Q.pop_front();
                    }
                    d -= D[i][++ k];
                }
                W[i][j] = dp[i-1][j]-H[i][j];
                while (!Q.empty() && W[i][Q.back()] <= W[i][j]) {
                    Q.pop_back();
                }
                Q.push_back(j);
                dp[i][j] = W[i][Q.front()]+H[i][j];
            }
            dp[i][0] = dp[i-1][0];
            Q.clear();
            d = 0;
            Q.push_back(m);
            W[i][m] = dp[i-1][m];
            for (int j = m-1, k = m; j >= 0; j --) {
                d += D[i][j+1];
                while (k > j && d > K) {
                    if (!Q.empty() && Q.front() >= k) {
                        Q.pop_front();
                    }
                    d -= D[i][k --];
                }
                W[i][j] = dp[i-1][j]-R[i][j];
                while (!Q.empty() && W[i][Q.back()] <= W[i][j]) {
                    Q.pop_back();
                }
                Q.push_back(j);
                dp[i][j] = max(dp[i][j], W[i][Q.front()]+R[i][j]);
            }
        }
        long long ans = 0;
        repi(j, 0, m+1) {
            ans = max(dp[n+1][j], ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
