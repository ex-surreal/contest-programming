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

int seg[4*200000+5];

void update(int node, int l, int r, int i, int v) {
    if (r < i || l > i) {
        return;
    }
    if (l == r) {
        seg[node] = v;
        return;
    }
    update(node*2+1, l, (l+r)/2, i, v);
    update(node*2+2, (l+r)/2+1, r, i, v);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}

int read(int node, int l, int r, int x, int y) {
    if (r < x || l > y) {
        return 1<<30;
    }
    if (x <= l && r <= y) {
        return seg[node];
    }
    int p = read(node*2+1, l, (l+r)/2, x, y);
    int q = read(node*2+2, (l+r)/2+1, r, x, y);
    return min(p, q);
}

int main () {
    /* int st = clock(); */
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n;
        scanf("%d", &n);
        rep(i, 4*n) {
            seg[i] = 1<<30;
        }
        vector <int> x(n), y(n);
        rep(i, n) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            x[a-1] = b-1, y[a-1] = c-1;
        }
        int ans = n;
        rep(i, n) {
            if (read(0, 0, n-1, 0, x[i]-1) < y[i]) {
                ans --;
            }
            update(0, 0, n-1, x[i], y[i]);
        }
        printf("%d\n", ans);
    }
    /* cerr << (clock()-st)*1.0/CLOCKS_PER_SEC << endl; */
    return 0;
}
