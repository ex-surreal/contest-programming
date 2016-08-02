#include <iostream>
#include <numeric>
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

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string ans = "No";
    vector <int> d, f;
    for (int i = 2; i*i <= k; i ++) {
        if (k % i == 0) {
            int t = 1;
            while (k%i == 0) {
                k /= i;
                t *= i;
            }
            d.pb(t);
            f.pb(0);
        }
    }
    if (k > 1) {
        d.pb(k);
        f.pb(0);
    }
    rep(i, n) {
        int x;
        cin >> x;
        rep(j, sz(d)) {
            if (x % d[j] == 0) {
                f[j] = 1;
            }
        }
    }
    int y = 1;
    repe(e, f) {
        if (e == 0) {
            y = 0;
        }
    }
    if (y) {
        ans = "Yes";
    }
    cout << ans;
    return 0;
}
