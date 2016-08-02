#include <iostream>
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

vector <int> seg, lazy;

void push_down(int node, int ls, int rs, int u, int v) {
    if (lazy[node] != 0) {
        seg[node] = lazy[node];
        if (u != v) {
            lazy[ls] = lazy[node];
            lazy[rs] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int u, int v, int x, int y, int val) {
    int ls = (node<<1)+1, rs = ls + 1, m = (u+v) >> 1;
    push_down(node, ls, rs, u, v);
    if (y < u || x > v) {
        return;
    }
    if (x <= u && v <= y) {
        seg[node] = val;
        if (u != v) {
            lazy[ls] = val;
            lazy[rs] = val;
        }
        return;
    }
    update(ls, u, m, x, y, val);
    update(rs, m+1, v, x, y, val);
    seg[node] = 0;
    if (seg[ls] == seg[rs]) {
        seg[node] = seg[ls];
    }
}

int read(int node, int u, int v, int i) {
    int ls = (node<<1)+1, rs = ls + 1, m = (u+v) >> 1;
    push_down(node, ls, rs, u, v);
    if (u == v) {
        return seg[node];
    }
    if (i <= m) {
        return read(ls, u, m, i);
    } else {
        return read(rs, m+1, v, i);
    }
}

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n;
        scanf("%d", &n);
        vector <int> l(n), r(n);
        set <int> st;
        rep(i, n) {
            scanf("%d%d", &l[i], &r[i]);
            st.insert(l[i]);
            st.insert(r[i]);
        }
        map <int, int> id;
        int z = 0;
        repe(s, st) {
            id[s] = z ++;
        }
        seg = lazy = vector <int>(z*4+5);
        rep(i, n) {
            update(0, 0, z-1, id[l[i]], id[r[i]], i+1);
        }
        vector <bool> seen(n+1, false);
        seen[0] = true;
        int ans = 0;
        rep(i, z) {
            int t = read(0, 0, z-1, i);
            if (!seen[t]) {
                ans ++;
            }
            seen[t] = true;
        }
        printf("%d\n", ans);
    }
    return 0;
}
