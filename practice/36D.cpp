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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, k;
    cin >> t >> k;
    rep(i, t) {
        int n, m;
        cin >> n >> m;
        if (n > k && m > k && ((n%k == 1 && m > n/k*k) || (m%k == 1 && n > m/k*k))) {
            cout << "+\n";
        } else {
            int d = (n+m-2)&1;
            d ^= (min(n, m)+k-1)/k % 2 == 0;
            cout << (d ? "+\n" : "-\n");
        }
    }
    return 0;
}
