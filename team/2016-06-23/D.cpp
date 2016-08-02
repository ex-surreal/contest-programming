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
    int tst;
    cin >> tst;
    while (tst --) {
        int n;
        cin >> n;
        vector <int> l(n+1), r(n+1), p(n+1), q(n+1);
        repi(i, 1, n+1) {
            cin >> l[i] >> r[i];
        }
        int ans = 0;
        for (int i = n; i > 0; i --) {
            int xp = (l[i] == -1 ? 1 : p[l[i]]);
            int xq = (l[i] == -1 ? 1 : q[l[i]]);
            int yp = (r[i] == -1 ? 1 : p[r[i]]);
            int yq = (r[i] == -1 ? 1 : q[r[i]]);
            p[i] = min(xp, yp) + 1;
            q[i] = max(xq, yq) + 1;
            if (q[i]-p[i] > 1 || (xp != xq && yp != yq)) {
                ans = -1;
                break;
            }
            if (xp < yq) {
                swap(l[i], r[i]);
                ans ++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
