#include <iostream>
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
    int n, q;
    scanf("%d%d", &n, &q);
    vector <int> id(n);
    int d = sqrt(n);
    rep(i, n) {
        id[i] = i/d;
    }
    vector <vector <int> > S(id.back()+1);
    vector <int> a(n);
    rep(i, n) {
        scanf("%d", &a[i]);
        S[id[i]].pb(a[i]);
    }
    rep(i, sz(S)) {
        sort(all(S[i]));
    }
    rep(i, q) {
        char o[2];
        scanf("%s", o);
        if (o[0] == 'M') {
            int l, x;
            scanf("%d%d", &l, &x);
            l --;
            repe(&y, S[id[l]]) {
                if (a[l] == y) {
                    y = x;
                    break;
                }
            }
            a[l] = x;
            sort(all(S[id[l]]));
        } else {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l --, r --;
            int f = id[l], g = id[r];
            int ans = 0;
            if (f == g) {
                repi(j, l, r+1) {
                    if (a[j] <= x) {
                        ans ++;
                    }
                }
            } else {
                repi(j, l, d*(f+1)) {
                    if (a[j] <= x) {
                        ans ++;
                    }
                }
                repi(j, g*d, r+1) {
                    if (a[j] <= x) {
                        ans ++;
                    }
                }
            }
            repi(j, f+1, g) {
                ans += upper_bound(all(S[j]), x) - S[j].begin();
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
