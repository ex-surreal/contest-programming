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
#include <ctime>
#include <cstdlib>
#include <cassert>

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

int get_per(vector <int> x, vector <int> y) {
    vector <pair <int, pair <int, int> > > sweep;
    for (int i = 0; i < sz(x); i += 2) {
        sweep.pb(mp(x[i], mp(-1, i)));
        sweep.pb(mp(x[i+1], mp(1, i)));
    }
    sort(all(sweep));
    vector <int> C(20005);
    int ret = 0;
    rep(i, sz(sweep)) {
        pair <int, pair <int, int> > s = sweep[i];
        repi(t, y[s.y.y], y[s.y.y+1]) {
            if (s.y.x == 1) {
                C[t+10000] --;
            }
            if (C[t+10000] == 0) {
                ret ++;
            }
            if (s.y.x == -1) {
                C[t+10000] ++;
            }
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> x(2*n), y(2*n);
    rep(i, 2*n) {
        cin >> x[i] >> y[i];
    }
    cout << get_per(x, y)+get_per(y, x) << "\n";
    return 0;
}
