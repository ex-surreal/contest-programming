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
    repi(cas, 1, tst+1) {
        int k;
        long long n;
        cin >> n >> k;
        vector <long long> lcm(1<<k), a(k);
        rep(i, k) {
            cin >> a[i];
            lcm[1<<i] = a[i];
        }
        repi(i, 1, 1<<k) {
            rep(j, k) {
                if (!((i>>j)&1) && lcm[i] != 0) {
                    long long g = __gcd(lcm[i], a[j]);
                    if (lcm[i]/g*1.0*a[j] <= 1.0*n + 1e-9) {
                        lcm[i|(1<<j)] = lcm[i]/g*a[j];
                    }
                }
            }
        }
        long long ans = 0;
        rep(i, 1<<k) {
            if (lcm[i] > 0) {
                int p = __builtin_popcountll(i);
                if (p&1) {
                    ans += 1ll*p*n/lcm[i];
                } else {
                    ans -= 1ll*p*n/lcm[i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
