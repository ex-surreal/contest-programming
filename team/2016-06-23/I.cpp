#include <iostream>
#include <vector>
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

#define eps 1e-9

/**
 * intersection point(s) between circle (0, 0), r and line ax+by+c = 0
 * */
std::vector <std::pair <double, double> > get_cl(double r, double a, double b, double c) {
    double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    std::vector <std::pair <double, double> > ret;
    if (c*c > r*r*(a*a + b*b) + eps) {
        return ret;
    }
    if (std::abs(c*c - r*r * (a*a + b*b)) < eps) {
        return ret;
    }
    else {
        double d = r * r - c * c / (a * a + b * b);
        double mult = sqrt (d / (a * a + b * b));
        double ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
        ret.push_back(std::make_pair(ax, ay));
        ret.push_back(std::make_pair(bx, by));
    }
    return ret;

}

/**
 * intersection point(s) between circles (0, 0), r and (x, y) r1
 * */

std::vector <std::pair <double, double> > get_cc(double r, double x, double y, double r1) {
    double a = -2*x, b = -2*y, c = x*x + y*y + r*r - r1*r1;
    return get_cl(r, a, b, c);
}

/**
 * tangent points from point (x, y) to circle (0, 0), r
 * */

std::vector <std::pair <double, double> > get_tangent(double r, double x, double y) {
    return get_cl(r, x, y, -r*r);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cout.precision(2);
    cout.setf(ios::fixed);
    int n;
    while (cin >> n && n) {
        int x, y;
        cin >> x >> y;
        vector <pair <double, int> > sweep;
        rep(i, n) {
            int h, k, r;
            cin >> h >> k >> r;
            vector <pair <double, double> > v = get_tangent(r, x-h, y-k);
            rep(j, sz(v)) {
                v[j].x += h, v[j].y += k;
            }
            double x1 = (y*v[0].x - x*v[0].y) / (y-v[0].y);
            double x2 = (y*v[1].x - x*v[1].y) / (y-v[1].y);
            if (x1 > x2) {
                swap(x1, x2);
            }
            sweep.pb(mp(x1, -1));
            sweep.pb(mp(x2, +1));
        }
        sort(all(sweep));
        double l = 0;
        int c = 0;
        rep(i, sz(sweep)) {
            pair <double, int> s = sweep[i];
            if (c == 0) {
                l = s.x;
            }
            c -= s.y;
            if (c == 0) {
                cout << l << " " << s.x << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
