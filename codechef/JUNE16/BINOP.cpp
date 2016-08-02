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
        string p, q;
        cin >> p >> q;
        if (*max_element(all(p)) == *min_element(all(p))) {
            cout << "Unlucky Chef\n";
            continue;
        }
        cout << "Lucky Chef\n";
        int x = 0, y = 0;
        rep(i, sz(p)) {
            x += p[i] == '0' && q[i] == '1';
            y += p[i] == '1' && q[i] == '0';
        }
        cout << max(x, y) << "\n";
    }
    return 0;
}
