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
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector <int> a = {1, 2, 3}, c(k);
        a.resize(n);
        repi(i, 3, n) {
            a[i] = (a[i-1]+a[i-2]+a[i-3]) % m + 1;
        }
        rep(i, n) {
            a[i] --;
        }
        int z = k, ans = 1<<29;
        int i = 0, j = 0;
        while (j < n) {
            if (z) {
                if (a[j] < k) {
                    z -= c[a[j]] == 0;
                    c[a[j]] ++;
                }
                j ++;
            } else {
                if (a[i] < k) {
                    c[a[i]] --;
                    z += c[a[i]] == 0;
                }
                i ++;
            }
            if (!z) {
                ans = min(ans, j-i); 
            }
        }
        if (ans == (1<<29)) {
            printf("Case %d: sequence nai\n", ++cas);
        } else {
            printf("Case %d: %d\n", ++cas, ans);
        }
    }
    return 0;
}
