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

typedef pair <double, double> point;

bool comp(point a, point b) {
    return a.y < b.y;
}

int main () {
    double pi = acos(-1.0);
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n, d;
        scanf("%d%d", &n, &d);
        vector <point> p;
        rep(i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x*x+y*y > d*d) {
                double th = atan2(y, x);
                double del = asin(1.0*d/sqrt(x*x+y*y));
                if (th+del > pi) {
                    th -= 2*pi;
                }
                p.push_back(mp(th-del, th+del));
            }
        }
        n = sz(p);
        sort(all(p), comp);
        int ans = n;
        rep(i, n) {
            int t = 1;
            double lst = p[i].y;
            repi(r, 1, n) {
                int j = (i+r)%n;
                double x = p[j].x, y = p[j].y;
                if (j < i) {
                    x += 2*pi;
                    y += 2*pi;
                }
                if (x > lst+1e-9) {
                    lst = y;
                    t ++;
                }
            }
            ans = min(ans, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
