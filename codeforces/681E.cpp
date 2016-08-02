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

vector <pair <double, double> > get_cl(double r, double a, double b, double c) {
    double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    vector <pair <double, double> > ret;
    if (c * c> r * r * (a * a + b * b) + eps) {
        return ret;
    }
    if (abs (c * c - r * r * (a * a + b * b)) < eps) {
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
        ret.pb(mp(ax, ay));
        ret.pb(mp(bx, by));
    }
    return ret;
}

vector <pair <double, double> > get_cc(double r, double x, double y, double r1) {
    double a = -2*x, b = -2*y, c = x*x + y*y + r*r - r1*r1;
    return get_cl(r, a, b, c);
}

vector <pair <double, double> > circle_int(double r, double x, double y, double r1) {
    auto v = get_cl(r, x, y, -r*r);
    double x1 = v[0].x, x2 = v[1].x;
    double y1 = v[0].y, y2 = v[1].y;
    if ((x1-x)*(x1-x) + (y1-y)*(y1-y) >= r1*r1) {
        return get_cc(r, x, y, r1);
    }
    vector <pair <double, double> > ret;
    ret.pb(mp(x1, y1));
    ret.pb(mp(x2, y2));
    return ret;
}

double pi = acos(-1.0);

double get_angle(double x, double y) {
    double th = acos(x/sqrt(x*x+y*y));
    if (y < 0) {
        th = 2*pi - th;
    }
    /* cout << "(" << x << ", " << y << ") = " << (180*th/pi) << endl; */
    return th;
}

bool is_less_angle(pair <double, double> a, pair <double, double> b) {
    return get_angle(a.x, a.y) < get_angle(b.x, b.y);
}

double cross(pair <double, double> a, pair <double, double> b) {
    return a.x*b.y - a.y*b.x;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);
    int n, x0, y0, v, T;
    cin >> x0 >> y0 >> v >> T;
    cin >> n;
    bool inside = false;
    double r0 = 1.0*v*T;
    vector <tuple <int, int, int> > hy;
    vector <pair <double, int> > sweep;
    rep(i, n) {
        int x, y, r;
        cin >> x >> y >> r;
        x -= x0, y -= y0;
        if (1ll*x*x + 1ll*y*y <= 1ll*r*r) {
            hy.pb(make_tuple(x, y, r));
            inside = true;
            continue;
        }
        if (r == 0 || v == 0 || T == 0) {
            continue;
        }
        auto v = circle_int(r, -x, -y, r0);
        repe(&p, v) {
            p.x += x;
            p.y += y;
        }
        if (sz(v)) {
            if (is_less_angle(v[1], v[0])) {
                swap(v[0], v[1]);
            }
            double a = get_angle(v[0].x, v[0].y);
            double b = get_angle(v[1].x, v[1].y);
            if (cross(v[0], v[1]) > 0) {
                sweep.pb(mp(a, -1));
                sweep.pb(mp(b, +1));
            } else {
                sweep.pb(mp(0, -1));
                sweep.pb(mp(a, +1));
                sweep.pb(mp(b, -1));
                sweep.pb(mp(2*pi, +1));
            }
        }
    }
    if (inside) {
        cout << 1.0;
        return 0;
    }
    sort(all(sweep));
    double sum = 0, lst = 0;
    int c = 0;
    repe(s, sweep) {
        if (c) {
            sum += s.x - lst;
        }
        c -= s.y;
        lst = s.x;
    }
    cout << 0.5*sum/pi;
    return 0;
}
