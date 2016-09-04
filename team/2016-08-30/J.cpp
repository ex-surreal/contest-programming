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
vector <point> ans;
double T, r34 = sqrt(3.0)/4.0;

void go(point a, point b) {
  ans.push_back(a);
  double t = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
  if (t/2 < T) {
    return;
  }
  point c = mp((3*a.x+b.x)/4, (3*a.y+b.y)/4);
  point d = mp((a.x+3*b.x)/4, (a.y+3*b.y)/4);
  point e = mp((a.x+b.x)/2 - (b.y-a.y)*r34, (a.y+b.y)/2 + (b.x-a.x)*r34);
  ans.push_back(d);
  go(c, e);
  go(e, d);
}

bool comp(point a, point b) {
  if (fabs(a.x-b.x) < 1e-8) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

int main () {
  point a, b;
  int cas = 0;
  while (~scanf("%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &T) && T >= 1) {
    ans.clear();
    go(a, b);
    ans.push_back(b);
    sort(all(ans), comp);
    printf("Case %d:\n%d\n", ++cas, sz(ans));
    repe(e, ans) {
      printf("%.5lf %.5lf\n", e.x, e.y);
    }
  }
  return 0;
}
