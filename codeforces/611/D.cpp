#include <iostream>
#include <string>

using namespace std;

int lcp[5005][5005];
int dp[5005][5005];
string s;
int n, mod = 1e9+7;

void makeLcp() {
    for (int i = n-1; i >= 0; i --) {
        for (int j = n-1; j > i; j --) {
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i+1][j+1] + 1;
            }
        }
    }
}

bool comp(int i, int j, int x, int y) {
    if (j-i != y-x) {
        return j-i < y-x;
    }
    if (lcp[i][x] >= j-i+1) {
        return false;
    }
    return s[i+lcp[i][x]] < s[x+lcp[i][x]];
}

int main () {
    cin >> n >> s;
    makeLcp();
    for (int j = 0; j < n; j ++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; i ++) {
        if (s[i] == '0') {
            continue;
        }
        for (int j = i, p = i-1, sum = 0; j < n; j ++) {
            while (p >= 0 && comp(p, i-1, i, j)) {
                sum += dp[p][i-1];
                if (sum >= mod) {
                    sum -= mod;
                }
                p --;
            }
            dp[i][j] = sum;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += dp[i][n-1];
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
