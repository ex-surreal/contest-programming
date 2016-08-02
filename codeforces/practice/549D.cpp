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

int main () {
    std::ios_base::sync_with_stdio(false);
    string B[105];
    int n, m;
    cin >> m >> n;
    rep(i, m) {
        cin >> B[i];
    }
    int cum[105][105] = {0}, ans = 0;
    for (int i = m; i > 0; i --) {
        for (int j = n; j > 0; j --) {
            int t = (B[i-1][j-1] == 'W' ? 1 : -1);
            if (t != cum[i+1][j]+cum[i][j+1]-cum[i+1][j+1]) {
                ans ++;
            }
            cum[i][j] = t;
        }
    }
    cout << ans;
    return 0;
}
