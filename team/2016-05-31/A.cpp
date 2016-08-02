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
#include <cstdio>

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

int p, a, b, c, d;

double price(double k) {
    return p*(sin(a*k+b)+cos(c*k+d)+2);
}

int main () {
    int n;
    while (scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n) != EOF) {
        double mx = price(1), ans = 0;
        repi(i, 2, n+1) {
            double now = price(i);
            ans = max(ans, mx-now);
            mx = max(mx, now);
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
