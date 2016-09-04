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

typedef pair <int, int> point;

long long cross(point o, point a, point b) {
  return 1ll*(a.x-o.x)*(b.y-o.y) - 1ll*(a.y-o.y)*(b.x-o.x);
}

#define ijp f*cross(p[i], q[j], q[(j-1+n)%n])
#define ijn f*cross(p[i], q[j], q[(j+1+n)%n])
#define jip f*cross(q[j], p[i], p[(i-1+m)%m])
#define jin f*cross(q[j], p[i], p[(i+1+m)%m])

tuple <int, int> tangent(vector <point> &p, vector <point> &q, int f = 1) {
  int i = 0, j = 0, m = sz(p), n = sz(q);
  bool ok = false;
  while (!ok) {
    ok = true;
    while (ijp > 0 || ijn > 0) {
      j = (j+1+n)%n;
    }
    while (jip > 0 || jin > 0) {
      ok = false;
      i = (i+1+m)%m;
    }
  }
  if (f == 1 && jin == 0) {
    i = (i+1+m)%m;
  }
  if (f == -1 && jip == 0) {
    i = (i-1+m)%m;
  }
  return mp(i, j);
}

int main () {
  int n, m, cas = 0;
  while (~scanf("%d%d", &n, &m) && n) {
    vector <point> p(n), q(m);
    rep(i, n) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    rep(i, m) {
      scanf("%d%d", &q[i].x, &q[i].y);
    }
    int a, b, c, d;
    tie(a, b) = tangent(p, q);
    tie(c, d) = tangent(p, q, -1);
    printf("Instance %d:\n", ++cas);
    if (p[a].x == q[b].x) {
      printf("VERTICAL\n");
    } else {
      double t = 1.0*(p[a].y-q[b].y)/(p[a].x-q[b].x);
      if (fabs(t) < 9e-4) {
        t = 0.0;
      }
      printf("%.3lf\n", t);
    }
    do {
      printf("%d %d\n", p[a].x, p[a].y);
      a = (a+1+n)%n;
    } while (a != c);
    printf("%d %d\n", p[a].x, p[a].y);
    if (p[c].x == q[d].x) {
      printf("VERTICAL\n");
    } else {
      double t = 1.0*(p[c].y-q[d].y)/(p[c].x-q[d].x);
      if (fabs(t) < 9e-4) {
        t = 0.0;
      }
      printf("%.3lf\n", t);
    }
  }
  return 0;
}
