#include <iostream>
#include <cstdio>
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
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector <int> a(n);
        rep(i, n) {
            scanf("%d", &a[i]);
        }
        rep(i, 31) {
            vector <int> st;
            rep(j, sz(a)) {
                if (!((a[j]>>i)&1)) {
                    st.pb(j);
                }
            }
            if (sz(st) == 1) {
                int t = min(n, k);
                repi(j, 1, t+1) {
                    a[(st[0]+j)%n] &= ~(1<<i);
                    a[(st[0]-j%n+n)%n] &= ~(1<<i);
                }
                continue;
            }
            rep(j, sz(st)) {
                int l = st[j], r = st[(j+1)%sz(st)], t = k;
                while ((r-l+n)%n > 1 && t > 0) {
                    l = (l+1) % n;
                    r = (r+n-1) % n;
                    a[l] &= ~(1<<i);
                    a[r] &= ~(1<<i);
                    t --;
                }
            }
        }
        rep(i, n) {
            printf("%s%d", (i > 0 ? " " : ""), a[i]);
        }
        printf("\n");
    }
    return 0;
}
