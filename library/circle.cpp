#include <iostream>
#include <cmath>
#include <vector>

#define eps 1e-9
#ifndef x
#define x first
#define y second
#endif

using namespace std;

typedef pair <double, double> point;

/**
 * intersection point(s) between circle (0, 0), r and line ax+by+c = 0
 * */
vector <point> get_cl(double r, double a, double b, double c) {
  double x0 = -a*c / (a*a + b*b), y0 = -b*c / (a*a + b*b);
  vector <point> ret;
  if (c*c > r*r*(a*a + b*b) + eps) {
    return ret;
  }
  if (abs(c*c - r*r * (a*a + b*b)) < eps) {
    return ret;
  }
  else {
    double d = r*r - c*c / (a*a + b*b);
    double mult = sqrt (d / (a*a + b*b));
    double ax, ay, bx, by;
    ax = x0 + b*mult;
    bx = x0 - b*mult;
    ay = y0 - a*mult;
    by = y0 + a*mult;
    ret.push_back(make_pair(ax, ay));
    ret.push_back(make_pair(bx, by));
  }
  return ret;

}

/**
 * intersection point(s) between circles (0, 0), r and (x, y) r1
 * */

vector <point> get_cc(double r, double x, double y, double r1) {
  double a = -2*x, b = -2*y, c = x*x + y*y + r*r - r1*r1;
  return get_cl(r, a, b, c);
}

/**
 * tangent points from point (x, y) to circle (0, 0), r
 * */

vector <point> get_tangent(double r, double x, double y) {
  return get_cl(r, x, y, -r*r);
}
