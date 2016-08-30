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
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n, m;
        scanf("%d", &n);
        vector <pair <int, pair <int, bool> > > s(n);
        rep(i, n) {
            scanf("%d%d", &s[i].y.x, &s[i].x);
            s[i].y.y = false;
        }
        scanf("%d", &m);
        s.resize(n+m);
        rep(i, m) {
            scanf("%d%d", &s[i+n].y.x, &s[i+n].x);
            s[i+n].y.y = true;
        }
        sort(all(s));
        int ans = 1<<29, mn = 1<<29;
        rep(i, sz(s)) {
            if (s[i].y.y) {
                mn = min(mn, s[i].y.x-s[i].x);
            } else {
                ans = min(ans, s[i].x-s[i].y.x+mn);
            }
        }
        reverse(all(s));
        mn = 1<<29;
        rep(i, sz(s)) {
            if (s[i].y.y) {
                mn = min(mn, s[i].y.x+s[i].x);
            } else {
                ans = min(ans, -s[i].x-s[i].y.x+mn);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
