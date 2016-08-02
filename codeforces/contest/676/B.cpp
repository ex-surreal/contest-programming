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
    int n, k;
    cin >> n >> k;
    int ans = (k == 0 ? 0 : 1);
    repi(i, 1, n) {
        int u = k-(1<<i)+1;
        int l = 1<<i;
        if (u >= l) {
            ans += 2;
        }
        if (u >= (l>>1)) {
            ans += i-1;
        }
    }
    cout << ans;
    return 0;
}
