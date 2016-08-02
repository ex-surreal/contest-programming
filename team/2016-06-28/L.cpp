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

int gcd(int a, int b) {
    return __gcd(min(abs(a), abs(b)), max(abs(a), abs(b)));
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    repi(cas, 1, tst+1) {
        int m, n;
        cin >> m >> n;
        vector <tuple <int, int, int> > q;
        rep(i, m) {
            rep(j, n) {
                string p;
                cin >> p;
                if (p != "?") {
                    q.pb(make_tuple(i, j, stoi(p)));
                }
            }
        }
        int i, j, a = 0;
        if (sz(q) > 0) {
            tie(i, j, a) = *q.begin();
        }
        string ans = "Yes";
        set <pair <int, int> > st;
        for (int d = 1; d*d <= a; d ++) {
            if (a%d == 0) {
                int e = a/d;
                if (d > i && e > j) {
                    st.insert(mp(d-i, e-j));
                }
                if (e > i && d > j) {
                    st.insert(mp(e-i, d-j));
                }
            }
        }
        repe(e, q) {
            tie(i, j, a) = e;
            bool f = false;
            for (int d = 1; d*d <= a; d ++) {
                if (a%d == 0) {
                    int e = a/d;
                    if (d > i && e > j && st.find(mp(d-i, e-j)) != st.end()) {
                        f = true;
                    }
                    if (e > i && d > j && st.find(mp(e-i, d-j)) != st.end()) {
                        f = true;
                    }
                }
            }
            if (!f) {
                ans = "No";
                break;
            }
        }
        cout << "Case #" << cas << ": " << ans << "\n";
    }
    return 0;
}
