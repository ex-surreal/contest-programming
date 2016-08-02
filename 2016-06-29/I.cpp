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

#include <vector>

const int n = 100000;
int seg[4 * n + 5][3];
int lazy[4 * n + 5];

void init(int node, int u, int v) {
    if (u > v) {
        return;
    }
    int ls = (node<<1)+1, rs = (node<<1)+2;
    lazy[node] = 0;
    if (u == v) {
        seg[node][0] = 1;
        return;
    }
    init(ls, u, (u + v) / 2);
    init(rs, (u + v) / 2 + 1, v);
    rep(i, 3) {
        seg[node][i] = seg[ls][i] + seg[rs][i];
    }
}

int tmp;

void update(int node, int u, int v, int x, int y) {
    if (u > v) {
        return;
    }
    int ls = (node<<1)+1, rs = (node<<1)+2;
    lazy[node] %= 3;
    if (lazy[node] != 0) { // lazy is not 0
        if (lazy[node] == 2) {
            tmp = seg[node][0];
            seg[node][0] = seg[node][1];
            seg[node][1] = seg[node][2];
            seg[node][2] = tmp;
        } else {
            tmp = seg[node][2];
            seg[node][2] = seg[node][1];
            seg[node][1] = seg[node][0];
            seg[node][0] = tmp;
        }
        if (u != v) {
            lazy[ls] += lazy[node];
            lazy[rs] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (v < x || u > y) {
        return;
    }
    if (x <= u && v <= y) {
        tmp = seg[node][2];
        seg[node][2] = seg[node][1];
        seg[node][1] = seg[node][0];
        seg[node][0] = tmp;
        if (u != v) {
            lazy[ls] ++;
            lazy[rs] ++;
        }
    } else {
        update(ls, u, (u + v) / 2, x, y);
        update(rs, (u + v) / 2 + 1, v, x, y);
        rep(i, 3) {
            seg[node][i] = seg[ls][i] + seg[rs][i];
        }
    }
}

int query(int node, int u, int v, int x, int y) {
    if (u > v) {
        return 0;
    }
    int ls = (node<<1)+1, rs = (node<<1)+2;
    lazy[node] %= 3;
    if (lazy[node] != 0) { // lazy is not 0
        if (lazy[node] == 2) {
            tmp = seg[node][0];
            seg[node][0] = seg[node][1];
            seg[node][1] = seg[node][2];
            seg[node][2] = tmp;
        } else {
            tmp = seg[node][2];
            seg[node][2] = seg[node][1];
            seg[node][1] = seg[node][0];
            seg[node][0] = tmp;
        }
        if (u != v) {
            lazy[ls] += lazy[node];
            lazy[rs] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (x > y || v < x || u > y) {
        return 0;
    }
    if (x <= u && v <= y) {
        return seg[node][0];
    }
    int a = query(ls, u, (u + v) / 2, x, y);
    int b = query(rs, (u + v) / 2 + 1, v, x, y);
    return a+b;
}

int main () {
    int n, q;
    scanf("%d%d", &n, &q);
    init(0, 0, n-1);
    rep(i, q) {
        int o, l, r;
        scanf("%d%d%d", &o, &l, &r);
        if (o == 0) {
            update(0, 0, n-1, l, r);
        } else {
            printf("%d\n", query(0, 0, n-1, l, r));
        }
    }
    return 0;
}
