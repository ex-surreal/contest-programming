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

int cnt[15][15];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, k, r, c;
    cin >> r >> c >> n >> k;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        cnt[x][y] = 1;
    }
    repi(i, 1, r+1) {
        repi(j, 1, c+1) {
            cnt[i][j] += cnt[i-1][j]+cnt[i][j-1] - cnt[i-1][j-1];
        }
    }
    int ans = 0;
    repi(i, 1, r+1) {
        repi(j, 1, c+1) {
            repi(x, i, r+1) {
                repi(y, j, c+1) {
                    if (cnt[x][y]-cnt[x][j-1]-cnt[i-1][y]+cnt[i-1][j-1] >= k) {
                        ans ++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
