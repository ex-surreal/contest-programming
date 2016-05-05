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

long long C[100][100];

int main () {
    std::ios_base::sync_with_stdio(false);
    repi(i, 0, 100) {
        C[i][0] = 1;
        repi(j, 1, i+1) {
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
    int tst;
    cin >> tst;
    while (tst --) {
        int cas, n;
        cin >> cas >> n;
        n /= 2;
        long long ans = 0;
        repi(i, 1, n+1) {
            if (i*2 <= n && i >= n-i*2) {
                int two = i, one = n-i*2;
                ans += C[one+two][one]*C[one+two][one];
            }
        }
        cout << cas << " " << ans << "\n";
    }
    return 0;
}
