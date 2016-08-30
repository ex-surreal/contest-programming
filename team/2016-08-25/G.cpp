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

const double pi = acos(-1.0), eps = 1e-9;
typedef pair <int, int> point;

bool comp(point a, point b) {
    return atan2(a.x, a.y) < atan2(b.x, b.y);
}

#define dis(p) ((p).x*(p).x + (p).y*(p).y)

double solve(vector <point> &p, int k) {
    if (k <= 1) {
        return 0.0;
    }
    sort(all(p), comp);
    vector <double> S, T;
    vector <int> D;
    repe(e, p) {
        D.push_back(dis(e));
        S.push_back(sqrt(D.back()));
        T.push_back(atan2(e.x, e.y));
    }
    double ret = 1e18;
    int n = sz(p);
    rep(i, n) {
        vector <int> id;
        rep(j, n) {
            if (D[j] <= D[i]) {
                id.push_back(j);
            }
        }
        if (sz(id) < k) {
            continue;
        }
        int d = sz(id);
        rep(t, d) {
            int a = id[t], b = id[(t+k-1)%d];
            double th = T[b]-T[a];
            th = (b < a ? 2*pi+th: th);
            ret = min(ret, S[i]*S[i]*th/2);
        }
    }
    return ret;
}

int main () {
    int n, k, cas = 0;
    while (~scanf("%d%d", &n, &k) && n) {
        vector <point> p(n);
        repe(&e, p) {
            scanf("%d%d", &e.x, &e.y);
            cout << atan2(e.y, e.x) << endl;
        }
        printf("Case #%d: %.2lf\n", ++cas, solve(p, k));
    }
    return 0;
}
