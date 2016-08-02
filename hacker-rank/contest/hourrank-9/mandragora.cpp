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
    int tst;
    cin >> tst;
    while (tst --) {
        int n;
        cin >> n;
        vector <long long> h(n);
        repe(&e, h) {
            cin >> e;
        }
        sort(all(h));
        reverse(all(h));
        repi(i, 1, n) {
            h[i] += h[i-1];
        }
        long long ans = 0;
        rep(i, n) {
            ans = max(h[i]*(n-i), ans);
        }
        cout << ans << "\n";
    }
    return 0;
}
