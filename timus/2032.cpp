#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>

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
    vector <int> a(3);
    repe(&x, a) {
        cin >> x;
    }
    vector <tuple <int, int> > g[3];
    rep(i, 3) {
        for (int x = 0; x <= a[i]; x ++) {
            int y = sqrt(1.0*a[i]*a[i] - 1.0*x*x);
            if (1ll*y*y + 1ll*x*x == 1ll*a[i]*a[i]) {
                g[i].pb(make_tuple(x, y));
            }
        }
    }
    int di[] = {+1, -1, +1, -1};
    int dj[] = {+1, -1, -1, +1};
    rep(i, 3) {
        rep(j, i) {
            repe(r, g[i]) {
                int x, y; 
                tie(x, y) = r;
                repe(b, g[j]) {
                    rep(t, 4) {
                        int p, q;
                        tie(p, q) = b;
                        p *= di[t], q *= dj[t];
                        if (1ll*(x-p)*(x-p) + 1ll*(y-q)*(y-q) == 1ll*a[3-(i+j)]*a[3-(i+j)]) {
                            cout << "0 0\n";
                            cout << x << " " << y << "\n";
                            cout << p << " " << q << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
