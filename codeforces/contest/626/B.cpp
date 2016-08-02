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

int dp[205][205][205];
int n;

bool solve(int i, int j, int k) {
    if (i+j+k > n || i+j+k <= 0) {
        return 0;
    }
    int &ret = dp[i][j][k];
    if (ret == -1) {
        ret = 0;
        if (i > 0) {
            ret = ret | solve(i+1, j, k) | solve(i-1, j+1, k+1);
        }
        if (j > 0) {
            ret = ret | solve(i, j+1, k) | solve(i+1, j-1, k+1);
        }
        if (k > 0) {
            ret = ret | solve(i, j, k+1) | solve(i+1, j+1, k-1);
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> n >> p;
    int b = count(p.begin(), p.end(), 'B');
    int g = count(p.begin(), p.end(), 'G');
    int r = count(p.begin(), p.end(), 'R');
    mem(dp, -1);
    dp[b][g][r] = 1;
    if (solve(1, 0, 0)) {
        cout << "B";
    }
    if (solve(0, 1, 0)) {
        cout << "G";
    }
    if (solve(0, 0, 1)) {
        cout << "R";
    }
    return 0;
}
