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
    int n;
    cin >> n;
    int C[100] = {0};
    rep(i, n) {
        int t;
        cin >> t;
        C[t] = 1;
    }
    int k = 0, ans = 0;
    repi(i, 1, 91) {
        if (C[i] == 0) {
            k ++;
        } else {
            k = 0;
        }
        ans ++;
        if (k == 15) {
            break;
        }
    }
    cout << ans;
    return 0;
}
