#include <iostream>
#include <cstdio>
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

const int N = 250000;
long long sum[N*4+5], seg[N*4+5], lazy[N*4+5], ser[2][N*4+5];

void push_down(int node, int ls, int rs, int u, int v, int m) {
    if (lazy[node] != 1000000) {
        seg[node] = lazy[node]*(v-u+1);
        if (u != v) {
            lazy[ls] = lazy[node];
            lazy[rs] = lazy[node];
            ser[0][ls] = ser[1][ls] = 0;
            ser[0][rs] = ser[1][rs] = 0;
            sum[ls] = sum[rs] = 0;
        }
        lazy[node] = 1000000;
    }
    if (ser[0][node] || ser[1][node]) {
        if (u != v) {
            sum[ls] += ser[1][node]*(v-m); 
            sum[rs] += ser[0][node]*(m+1-u); 
        }
        rep(i, 2) {
            seg[node] += ser[i][node]*(v-u+1)*(v-u+2)/2;
            if (u != v) {
                ser[i][ls] += ser[i][node];
                ser[i][rs] += ser[i][node];
            }
            ser[i][node] = 0;
        }
    }
    if (sum[node]) {
        seg[node] += sum[node]*(v-u+1);
        if (u != v) {
            sum[ls] += sum[node];
            sum[rs] += sum[node];
        }
        sum[node] = 0;
    }
}

long long get_sum(int a, int b) {
    return 1ll*b*(b+1)/2 - 1ll*a*(a-1)/2;
}

void update(int node, int u, int v, int x, int y, int t, int val = 0) {
    int ls = (node<<1)+1, rs = (node<<1)+2, m = (u+v)>>1;
    push_down(node, ls, rs, u, v, m);
    if (u > y || v < x) {
        return;
    }
    if (x <= u && v <= y) {
        if (t == 2) {
            seg[node] = 1ll*val*(v-u+1);
            if (u != v) {
                lazy[ls] = val;
                lazy[rs] = val;
                ser[0][ls] = ser[1][ls] = 0;
                ser[0][rs] = ser[1][rs] = 0;
                sum[ls] = sum[rs] = 0;
            }
        } else {
            if (t == 0) {
                seg[node] += get_sum(u-x+1, v-x+1);
            } else {
                seg[node] += get_sum(y-v+1, y-u+1);
            }
            if (u != v) {
                ser[t][ls] ++;
                ser[t][rs] ++;
                if (t == 1) {
                    sum[ls] += y-m;
                    sum[rs] += y-v;
                } else {
                    sum[rs] += m-x+1;
                    sum[ls] += u-x;
                }
            }
        }
        return;
    }
    update(ls, u, m, x, y, t, val);
    update(rs, m+1, v, x, y, t, val);
    seg[node] = seg[ls]+seg[rs];
}

long long query(int node, int u, int v, int x, int y) {
    int ls = (node<<1)+1, rs = (node<<1)+2, m = (u+v)>>1;
    push_down(node, ls, rs, u, v, m);
    if (u > y || v < x) {
        return 0;
    }
    if (x <= u && v <= y) {
        return seg[node];
    }
    long long p = query(ls, u, m, x, y);
    long long q = query(rs, m+1, v, x, y);
    return p+q;
}

int main () {
    int cas = 1, tst;
    scanf("%d", &tst);
    while (tst --) {
        int q;
        scanf("%d", &q);
        rep(i, 4*N+5) {
            lazy[i] = 1000000;
            sum[i] = ser[0][i] = ser[1][i] = seg[i] = 0;
        }
        printf("Case %d:\n", cas++);
        while (q --) {
            char o[2];
            int l, r;
            scanf("%s%d%d", o, &l, &r);
            if (o[0] == 'A') {
                update(0, 1, N, l, r, 0);
            } else if (o[0] == 'B') {
                update(0, 1, N, l, r, 1);
            } else if (o[0] == 'C') {
                int x;
                scanf("%d", &x);
                update(0, 1, N, l, r, 2, x);
            } else {
                printf("%lld\n", query(0, 1, N, l, r));
            }
        }
    }
    return 0;
}
