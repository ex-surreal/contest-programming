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
    int n, m;
    cin >> n >> m;
    vector <int> brotherX(n+1, n+1), brotherY(n+1, 0);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        brotherX[x] = min(brotherX[x], y);
        brotherX[y] = min(brotherX[y], x);
        brotherY[x] = max(brotherY[x], y);
        brotherY[y] = max(brotherY[y], x);
    }
    vector <bool> left(n+1), right(n+1);
    bool l = false, r = false;
    repi(i, 1, n+1) {
        if (brotherX[i] < i) {
            l = true;
        }
        left[i] = l;
    }
    for (int i = n; i > 0; i --) {
        if (brotherY[i] > i) {
            r = true;
        }
        right[i] = r;
    }
    int ans = 0;
    repi(i, 1, n) {
        if (!left[i] && !right[i+1]) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
