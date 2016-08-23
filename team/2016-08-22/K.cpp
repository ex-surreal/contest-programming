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

long long dp[35][35][35];
char buff[35];

int main () {
    int tst, cas = 0;
    cin.getline(buff, sizeof buff);
    tst = stoi(buff);
    while (tst --) {
        cin.getline(buff, sizeof buff);
        string p = buff;
        cin.getline(buff, sizeof buff);
        string q = buff;
        rep(i, 35) {
            dp[i][0][0] = dp[0][i][0] = 1;
        }
        int a = sz(p), b = sz(q);
        rep(i, a) {
            rep(j, b) {
                rep(k, min(a, b)+1) {
                    dp[i+1][j+1][k] = dp[i][j+1][k]+dp[i+1][j][k];
                    if (k > 0 && p[i] == q[j]) {
                        dp[i+1][j+1][k] = dp[i][j][k-1];
                    }
                }
            }
        }
        for (int k = min(a, b); k >= 0; k --) {
            if (dp[a][b][k] > 0) {
                printf("Case #%d: %d %lld\n", ++cas, a+b-k, dp[a][b][k]);
                break;
            }
        }
    }
    return 0;
}
