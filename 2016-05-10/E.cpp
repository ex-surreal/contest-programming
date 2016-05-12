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

vector <int> H;
unsigned dp[2005][2005];
bool seen[2005][2005];
unsigned mod = (1u<<31)-1;

unsigned solve(int n, int b) {
    if (n == sz(H)) {
        return 1;
    }
    unsigned &ret = dp[n][b];
    if (!seen[n][b]) {
        seen[n][b] = true;
        ret = 0;
        if (b < H[n-1]) {
            if (H[n] > b) {
                ret += solve(n+1, b);
            }
            if (H[n] < H[n-1]) {
                ret += solve(n+1, H[n-1]);
            }
        } else {
            if (H[n] < b) {
                ret += solve(n+1, b);
            }
            if (H[n] > H[n-1]) {
                ret += solve(n+1, H[n-1]);
            }
        }
        ret %= mod;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        H.resize(n);
        int B;
        cin >> B;
        rep(i, n) {
            cin >> H[i];
        }
        mem(seen, false);
        cout << solve(1, B) << "\n";
    }
    return 0;
}
