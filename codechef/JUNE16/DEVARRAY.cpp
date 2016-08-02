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
    int n, tst;
    cin >> n >> tst;
    int mn = 1<<30, mx = 0;
    rep(i, n) {
        int a;
        cin >> a;
        mn = min(a, mn);
        mx = max(a, mx);
    }
    while (tst --) {
        int t;
        cin >> t;
        if (mn <= t && t <= mx) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
