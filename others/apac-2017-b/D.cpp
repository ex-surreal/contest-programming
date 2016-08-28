#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
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
    int tst, cas = 0;
    scanf("%d", &tst);
    while (tst --) {
        printf("Case #%d: ", ++cas);
        int n, m;
        scanf("%d%d", &n, &m);
        vector <int> fact(n+1, 1), f(n+1);
        repi(i, 1, n+1) {
            fact[i] = 1ll*i*fact[i-1] % m;
        }
        repi(i, 1, n+1) {
            f[i] = fact[i];
            repi(j, 1, i) {
                f[i] -= 1ll*f[i-j]*fact[j] % m;
                if (f[i] < 0) {
                    f[i] += m;
                }
            }
        }
        vector <int> p(n+1), q(n+1), r(n+1);
        p[0] = 1;
        repi(i, 1, n+1) {
            rep(j, i) {
                p[i] = (p[i] + 1ll*p[j]*f[i-j] % m) % m;
                q[i] = (q[i] + 1ll*(q[j]+p[j])%m*f[i-j]) % m;
                r[i] = (r[i] + 1ll*(r[j]+2ll*q[j]+p[j])%m*f[i-j]) % m;
            }
        }
        printf("%d\n", r[n]);
    }
    return 0;
}
