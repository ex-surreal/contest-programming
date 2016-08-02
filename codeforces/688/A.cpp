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

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector <int> a;
    rep(i, d) {
        string p;
        cin >> p;
        a.pb(p == string(n, '1'));
    }
    a.pb(1);
    int l = -1, ans = 0;
    rep(i, sz(a)) {
        if (a[i] == 1) {
            ans = max(i-l-1, ans);
            l = i;
        }
    }
    cout << ans;
    return 0;
}
