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
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (b > a) {
            swap(a, b);
        }
        int d = a-b;
        int ans = 1;
        long long l = 1ll*(a+1)/__gcd(a+1, b+1)*(b+1);
        for (int p = 1; 1ll*p*p <= d; p ++) {
            if (d % p) {
                continue;
            }
            int n = (-a%p+p)%p;
            n = (n == 0 ? p : n);
            if (__gcd(a+n, b+n) == p) {
                long long t = 1ll*(a+n)/p*(b+n);
                if (t < l || (t == l && n < ans)) {
                    ans = n;
                    l = t;
                }
            }
            int q = d/p;
            n = (-a%q+q)%q;
            n = (n == 0 ? q : n);
            if (__gcd(a+n, b+n) == q) {
                long long t = 1ll*(a+n)/q*(b+n);
                if (t < l || (t == l && n < ans)) {
                    ans = n;
                    l = t;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
