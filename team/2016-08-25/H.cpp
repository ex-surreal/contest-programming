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
    int n;
    while (~scanf("%d", &n) && n) {
        vector <int> a(n), b(n), id(n);
        repe(&e, a) {
            scanf("%d", &e);
            e --;
        }
        repe(&e, b) {
            scanf("%d", &e);
            e --;
        }
        rep(i, n) {
            id[b[i]] = i;
        }
        int ans = 0;
        rep(i, n) {
            int mn = n+1, mx = -1, c = 0;
            repi(j, i, n) {
                mn = min(mn, id[a[j]]);
                mx = max(mx, id[a[j]]);
                c ++;
                if (c > 1 && mx-mn+1 == c) {
                    ans ++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
