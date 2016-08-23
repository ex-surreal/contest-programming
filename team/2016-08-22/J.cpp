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

int main () {
    int m, n;
    double w, eps = 1e-9;
    while (scanf("%d%d%lf", &m, &n, &w) && m) {
        vector <double> p(m), q(n);
        repe(&e, p) {
            scanf("%lf", &e);
        }
        p.push_back(-0.5*w);
        p.push_back(75+0.5*w);
        repe(&e, q) {
            scanf("%lf", &e);
        }
        q.push_back(-0.5*w);
        q.push_back(100+0.5*w);
        sort(all(p));
        sort(all(q));
        bool dp1 = true, dp2 = true;
        repi(i, 1, sz(p)) {
            dp1 = dp1 && p[i-1]+w/2 >= p[i]-w/2-eps;
        }
        repi(i, 1, sz(q)) {
            dp2 = dp2 && q[i-1]+w/2 >= q[i]-w/2-eps;
        }
        printf(dp1 && dp2 ? "YES\n" : "NO\n");
    }
    return 0;
}
