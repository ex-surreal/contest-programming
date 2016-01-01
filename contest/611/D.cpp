#include <bits/stdc++.h>

using namespace std;

int maxMatch[5005][5005];

void makeMaxMatch(string &s) {
    for (int i = s.size(); i > 0; i --) {
        for (int j = s.size(); j > i; j --) {
            if (s[i-1] == s[j-1]) {
                maxMatch[i][j] = min(maxMatch[i+1][j+1]+1, min(int(s.size())-j+1, j-i));
            }
        }
    }
}

bool can[5005][5005];

void makeCan(string &s) {
    int n = s.size();
    for (int j = 1; j <= n; j ++) {
        for (int i = 1; i < j; i ++) {
            if (n-j+1 >= j-i && i+maxMatch[i][j] < j && j+maxMatch[i][j] <= n) {
                can[i][j] = s[i+maxMatch[i][j]-1] < s[j+maxMatch[i][j]-1];
            }
        }
    }
}

int zero[5005];

void makeZero(string &s) {
    for (int i = s.size(), cnt = 0; i > 0; i --) {
        if (s[i-1] == '0') {
            cnt ++;
        } else {
            cnt = 0;
        }
        zero[i] = cnt;
    }
}

int dp[5005][5005];
int sum[5005];
int mod = 1e9+7;

int makeDp(string &s) {
    makeMaxMatch(s);
    makeCan(s);
    makeZero(s);
    int n = s.size();
    for (int i = 1; i <= n; i ++) {
        dp[0][i] = 1;
        sum[i] = (sum[i-1] + dp[0][i])%mod;
    }
    for (int i = 1; i < n; i ++) {
        if (s[i] == '0') {
            continue;
        }
        for (int j = 1; j <= n; j ++) {
            sum[j] = sum[j-1] + dp[i-1][j];
        }
        for (int j = 1; j <= n-i; j ++) {
            int st = max(1, i-j+1);
            st = st + zero[i];
            if (i < j || (can[st][i+1] && st < i)) {
                dp[i][j] = (sum[i-1] - sum[st-1] + mod) % mod;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i ++) {
        ans = (ans + dp[i][n-i]) % mod;
    }
    return ans;
}

int main () {
    int n;
    string str;
    cin >> n >> str;
    cout << makeDp(str);
    return 0;
}
