#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

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
    cout.precision(10);
    cout.setf(ios::fixed);
    int n, w, u, v, t1, t2;
    while (cin >> n >> w >> u >> v >> t1 >> t2) {
        vector <pair <double, int> > sweep;
        repi(i, 1, n+1) {
            string q;
            int m;
            cin >> q >> m;
            rep(j, m) {
                int l, p;
                cin >> l >> p;
                if (q == "E") {
                    p = -p;
                }
                if (l+p <= 0) {
                    continue;
                }
                if (p < 0) {
                    l += p;
                    p = 0;
                }
                sweep.pb(mp(max(1.0*t1, min(1.0*t2, 1.0*p/u - 1.0*w*i/v)), -1));
                sweep.pb(mp(max(1.0*t1, min(1.0*t2, 1.0*(p+l)/u - 1.0*w*(i-1)/v)), +1));
            }
        }
        sort(all(sweep));
        double ans = 0;
        double last = t1;
        int c = 0;
        repe(s, sweep) {
            if (c == 0) {
                ans = max(ans, s.x-last);
            }
            last = s.x;
            c -= s.y;
        }
        ans = max(ans, t2-last);
        cout << ans << "\n";
    }
    return 0;
}
