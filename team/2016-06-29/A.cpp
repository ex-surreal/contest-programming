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

const int N = 50000;
int seg[4*N+5][4];
vector <int> a;
 
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
        return;
    }
    init(ls, u, (u+v)/2);
    init(rs, (u+v)/2+1, v);
    seg[node][0] = seg[ls][0]+seg[rs][0];
    seg[node][1] = max(seg[ls][1], seg[rs][1]+seg[ls][0]);
    seg[node][2] = max(seg[rs][2], seg[ls][2]+seg[rs][0]);
    seg[node][3] = max(seg[ls][3], seg[rs][3]);
    seg[node][3] = max(seg[node][3], seg[ls][2]+seg[rs][1]);
}

tuple <int, int, int, int> read(int node, int u, int v, int x, int y) {
    if (x > y || v < x || u > y) {
        return make_tuple(0, -(1<<30), -(1<<30), -(1<<30));
    }
    int lc = (node<<1)+1, rc = (node<<1)+2;
    if(x <= u && v <= y) {
        return make_tuple(seg[node][0], seg[node][1], seg[node][2], seg[node][3]);
    }
    int ls, ll, lr, lm;
    int rs, rl, rr, rm;
    tie(ls, ll, lr, lm) = read(lc, u, (u+v)/2, x, y);
    tie(rs, rl, rr, rm) = read(rc, (u+v)/2+1, v, x, y);
    int l, r, s, m;
    s = ls+rs;
    l = max(ll, rl+ls);
    r = max(rr, lr+rs);
    m = max(lm, max(rm, lr+rl));
    return make_tuple(s, l, r, m);
}

int main () {
    int n;
    scanf("%d", &n);
    a.resize(n);
    rep(i, n) {
        scanf("%d", &a[i]);
    }
    init(0, 0, n-1);
    int q;
    cin >> q;
    rep(i, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        int a, b, c, ans;
        tie(a, b, c, ans) = read(0, 0, n-1, l-1, r-1);
        printf("%d\n", ans);
    }
    return 0;
}
