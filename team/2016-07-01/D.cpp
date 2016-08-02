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

const int N = 10001;
int seg[4*N+5][6];
vector <int> a, cum;
 
void init(int node, int u, int v) {
    if(u > v) {
        return;
    }
    int ls = (node<<1)+1, rs = (node<<1)+2;
    if(u == v) {
        seg[node][0] = a[u];
        seg[node][1] = a[u];
        seg[node][2] = a[u];
        seg[node][3] = a[u];
        seg[node][4] = cum[u];
        seg[node][5] = cum[u];
        return;
    }
    init(ls, u, (u+v)/2);
    init(rs, (u+v)/2+1, v);
    seg[node][0] = seg[ls][0]+seg[rs][0];
    seg[node][1] = max(seg[ls][1], seg[rs][1]+seg[ls][0]);
    seg[node][2] = max(seg[rs][2], seg[ls][2]+seg[rs][0]);
    seg[node][3] = max(seg[ls][3], seg[rs][3]);
    seg[node][3] = max(seg[node][3], seg[ls][2]+seg[rs][1]);
    seg[node][4] = min(seg[ls][4], seg[rs][4]);
    seg[node][5] = max(seg[ls][5], seg[rs][5]);
}

tuple <int, int, int, int, int, int> read(int node, int u, int v, int x, int y) {
    if (x > y || v < x || u > y) {
        return make_tuple(0, -(1<<30), -(1<<30), -(1<<30), 1<<30, -(1<<30));
    }
    int lc = (node<<1)+1, rc = (node<<1)+2;
    if(x <= u && v <= y) {
        return make_tuple(seg[node][0], seg[node][1], seg[node][2], seg[node][3], seg[node][4], seg[node][5]);
    }
    int ls, ll, lr, lm, lx, ly;
    int rs, rl, rr, rm, rx, ry;
    tie(ls, ll, lr, lm, lx, ly) = read(lc, u, (u+v)/2, x, y);
    tie(rs, rl, rr, rm, rx, ry) = read(rc, (u+v)/2+1, v, x, y);
    int l, r, s, m, p, q;
    s = ls+rs;
    l = max(ll, rl+ls);
    r = max(rr, lr+rs);
    m = max(lm, max(rm, lr+rl));
    p = min(lx, rx);
    q = max(ly, ry);
    return make_tuple(s, l, r, m, p, q);
}

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n;
        scanf("%d", &n);
        a.resize(n+1);
        cum.resize(n+1);
        rep(i, n) {
            scanf("%d", &a[i+1]);
            cum[i+1] = a[i+1] + cum[i];
        }
        init(0, 0, n);
        int q;
        scanf("%d", &q);
        rep(i, q) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (y1 < x2) {
                int a, b, c, d, e, f, g;
                tie(a, b, c, d, f, e) = read(0, 0, n, x1-1, y1-1);
                tie(a, b, c, d, e, g) = read(0, 0, n, x2, y2);
                printf("%d\n", g-f);
            } else {
                int a, b, c, d, e, f, g;
                tie(a, b, c, d, f, e) = read(0, 0, n, x1-1, x2-1);
                tie(a, b, c, d, e, g) = read(0, 0, n, x2, y2);
                int ans = g-f;
                tie(a, b, c, d, f, e) = read(0, 0, n, x2-1, y1-1);
                tie(a, b, c, d, e, g) = read(0, 0, n, y1, y2);
                ans = max(ans, g-f);
                tie(a, b, c, d, e, f) = read(0, 0, n, x2, y1);
                ans = max(ans, d);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
