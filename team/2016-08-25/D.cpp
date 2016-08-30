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
    int n, cas = 0;
    double e, th, pi = acos(-1.0);
    while (~scanf("%d%lf%lf", &n, &e, &th) && n) {
        vector <point> p(n);
        th = th*pi/180;
        repe(&e, p) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            e = mp(x*cos(th) + y*sin(th), -x*sin(th) + y*cos(th)); 
        }
        double ans = 1e18;
        sort(all(p));
        rep(i, n-1) {
            double dx2 = (p[i].x-p[i+1].x)/2;
            double dy2 = (p[i].y-p[i+1].y)/2;
            ans = min(ans, dx2*dx2 + dy2*dy2/(1-e*e));
            /* cout << ans << endl; */
        }
        sort(all(p), comp);
        rep(i, n-1) {
            double dx2 = (p[i].x-p[i+1].x)/2;
            double dy2 = (p[i].y-p[i+1].y)/2;
            ans = min(ans, dx2*dx2 + dy2*dy2/(1-e*e));
            /* cout << ans << endl; */
        }
        ans = pi*ans*sqrt(1-e*e);
        printf("Case %d:\n%.6lf\n", ++ cas, ans);
    }
    return 0;
}
