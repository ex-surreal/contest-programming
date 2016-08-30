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

#define sq(a) ((a)*(a))
#define dis(i, j) (sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]))

int main () {
    int n;
    while (~scanf("%d", &n)) {
        vector <int> x(n), y(n), z(n), p(n), cnt(n);
        rep(i, n) {
            scanf("%d%d%d%d", &x[i], &y[i], &z[i], &p[i]);
            p[i] = !p[i] ? -1 : p[i];
        }
        vector <pair <int, pair <int, int> > > D;
        rep(i, n) {
            rep(j, n) {
                D.push_back(mp(dis(i, j), mp(i, j)));
            }
        }
        sort(all(D));
        int ans = 0, d = 0, now = 0;
        rep(s, sz(D)) {
            int i = D[s].y.x, j = D[s].y.y;
            cnt[i] += p[j];
            if (p[i] == p[j]) {
                now -= cnt[i] == 0;
            } else {
                now += cnt[i]*p[i] == -1;
            }
            if (s < sz(D)-1 && D[s+1].x == D[s].x) {
                continue;
            }
            if (now > ans) {
                ans = now;
                d = D[s].x;
            }
        }
        printf("%d\n%.10lf\n", ans, sqrt(d));
    }
    return 0;
}
