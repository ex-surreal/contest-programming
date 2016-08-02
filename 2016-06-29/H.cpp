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

const int N = 100000;
int seg[4 * N + 5];
int lazy[4 * N + 5];

void update(int node, int u, int v, int x, int y) {
    int ls = (node<<1)+1, rs = (node<<1)+2;
    if (lazy[node] != 0) { // lazy is not 0
        seg[node] = v-u+1 - seg[node]; // varies from problem to problem
        if (u != v) {
            lazy[ls] ^= lazy[node];
            lazy[rs] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    if (v < x || u > y) {
        return;
    }
    if (x <= u && v <= y) {
        seg[node] = v-u+1 - seg[node];
        if (u != v) {
            lazy[ls] ^= 1;
            lazy[rs] ^= 1;
        }
        return;
    }
    update(ls, u, (u + v) / 2, x, y);
    update(rs, (u + v) / 2 + 1, v, x, y);
    seg[node] = seg[ls]+seg[rs];
}

int query(int node, int u, int v, int x, int y) {
    int ls = (node<<1)+1, rs = (node<<1)+2;
    if (lazy[node] != 0) { // lazy is not 0
        seg[node] = v-u+1 - seg[node]; // varies from problem to problem
        if (u != v) {
            lazy[ls] ^= lazy[node];
            lazy[rs] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    if (x > y || v < x || u > y) {
        return 0;
    }
    if (x <= u && v <= y) {
        return seg[node];
    }
    int a = query(ls, u, (u + v) / 2, x, y);
    int b = query(rs, (u + v) / 2 + 1, v, x, y);
    return a+b;
}

int main () {
    int n, q;
    scanf("%d%d", &n, &q);
    rep(i, q) {
        int o, l, r;
        scanf("%d%d%d", &o, &l, &r);
        if (o == 0) {
            update(0, 0, n-1, l-1, r-1);
        } else {
            printf("%d\n", query(0, 0, n-1, l-1, r-1));
        }
    }
    return 0;
}
