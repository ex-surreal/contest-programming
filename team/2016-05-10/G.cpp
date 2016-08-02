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
    int p, k;
    while (cin >> p >> k) {
        int ans = 0;
        rep(t, p) {
            int n;
            cin >> n;
            vector <int> c(n+1), g(n+1, 0);
            repi(i, 1, n+1) {
                cin >> c[i];
            }
            repi(i, 1, n+1) {
                map <int, bool> seen;
                rep(j, k+1) {
                    if (i-j == 0) {
                        break;
                    }
                    if (i-j-c[i-j] >= 0) {
                        seen[g[i-j-c[i-j]]] = true;
                    }
                }
                int d = 0;
                while (seen[d]) {
                    d ++;
                }
                g[i] = d;
            }
            ans ^= g[n];
        }
        cout << (ans ? "Alice can" : "Bob will") << " win.\n";
    }
    return 0;
}
