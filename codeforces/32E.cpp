#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define rep(i, n) for (int i=0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define inRange(x, a, b) (min(a, b)-eps <= x && x <= max(a, b)+eps)

typedef pair <double, double> Point;

template <class X, class Y> ostream & operator << (ostream &o, pair <X, Y> a) {
	o << "(" << a.x << ", " << a.y << ")";
	return o;
}

double cross(Point a, Point b) {
	return a.x*b.y - a.y*b.x;
}

Point sub(Point a, Point b) {
	return mp(a.x-b.x, a.y-b.y);
}

double val(Point a) {
	return sqrt(a.x*a.x + a.y*a.y);
}

Point norm(Point a) {
	return mp(a.x/val(a), a.y/val(a));
}

bool isIntersects(Point a, Point b, Point c, Point d) {
	double d1 = cross(sub(b, a), sub(c, a));
	double d2 = cross(sub(b, a), sub(d, a));
	double d3 = cross(sub(d, c), sub(a, c));
	double d4 = cross(sub(d, c), sub(b, c));
	// cout << mp(mp(d1, d2), mp(d3, d4)) << endl;
	if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) {
		return true;
	}
	if (zero(d1) && inRange(c.x, a.x, b.x) && inRange(c.y, a.y, b.y)) {
		return true;
	}
	if (zero(d2) && inRange(d.x, a.x, b.x) && inRange(d.y, a.y, b.y)) {
		return true;
	}
	if (zero(d3) && inRange(a.x, c.x, d.x) && inRange(a.y, c.y, d.y)) {
		return true;
	}
	if (zero(d4) && inRange(b.x, c.x, d.x) && inRange(b.y, c.y, d.y)) {
		return true;
	}
	return false;
}

double getDiff(Point m0, Point m1, double t, Point A, Point B) {
	Point p = mp(m0.x + (m1.x-m0.x)*t, m0.y + (m1.y-m0.y)*t);
	Point v1 = norm(sub(A, p));
	Point v2 = norm(sub(B, p));
	Point n = norm(mp(m1.y-m0.y, m0.x-m1.x));
	if (cross(sub(m1, m0), sub(A, m0)) < 0) {
		n = sub(mp(0, 0), n);
	}
	return cross(n, v1) + cross(n, v2);
}

string solve(Point m0, Point m1, Point A, Point B, Point w0, Point w1) {
	if (!isIntersects(A, B, w0, w1) && !isIntersects(A, B, m0, m1)) {
		return "YES";
	}
	double d1 = cross(sub(m1, m0), sub(A, m0));
	double d2 = cross(sub(m1, m0), sub(B, m0));
	if ((d1 > -eps && d2 > -eps) || (d1 < eps && d2 < eps)) {
		double low = 0, high = 1;
		if (getDiff(m0, m1, low, A, B) > -eps && getDiff(m0, m1, high, A, B) < eps) {
			swap(high, low);
		}
		if ((getDiff(m0, m1, low, A, B) < -eps && getDiff(m0, m1, high, A, B) < -eps) || (getDiff(m0, m1, low, A, B) > eps && getDiff(m0, m1, high, A, B) > eps)) {
			return "NO";
		}
		while (!zero(high-low)) {
			double mid = (high+low)/2.0;
			if (getDiff(m0, m1, mid, A, B) < 0) {
				low = mid;
			} else {
				high = mid;
			}
		}
		Point p = mp(m0.x + (m1.x-m0.x)*low, m0.y + (m1.y-m0.y)*low);
		if (!isIntersects(p, A, w0, w1) && !isIntersects(p, B, w0, w1)) {
			return "YES";
		}
	}
	return "NO";
}

int main () {
	std::ios_base::sync_with_stdio(false);
	double m0x, m0y, w0x, w0y, Ax, Ay;
	double m1x, m1y, w1x, w1y, Bx, By;
	cin >> Ax >> Ay;
	cin >> Bx >> By;
	cin >> w0x >> w0y;
	cin >> w1x >> w1y;
	cin >> m0x >> m0y;
	cin >> m1x >> m1y;
	cout << solve(mp(m0x, m0y), mp(m1x, m1y), mp(Ax, Ay), mp(Bx, By), mp(w0x, w0y), mp(w1x, w1y));
	return 0;
}
