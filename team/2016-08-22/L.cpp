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

unsigned long long dp[105][64];

int main () {
    rep(j, 64) {
        dp[1][j] = j;
    }
    repi(i, 2, 105) {
        dp[i][1] = 1;
        repi(j, 2, 64) {
            dp[i][j] = dp[i][j-1]+1+dp[i-1][j-1];
        }
    }
    unsigned long long n;
    int k;
    while (scanf("%d%llu", &k, &n) && k) {
        try {
            repi(i, 1, 64) {
                if (dp[k][i] >= n) {
                    throw i;
                }
            }
            printf("More than 63 trials needed.\n");
        } catch (int ans) {
            printf("%d\n", ans);
        }
    }
    return 0;
}
