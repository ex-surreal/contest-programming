#include <iostream>
#include <cstdio>
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

namespace point_update {
    #define invalid -(1<<30)
    typedef int type;
    const int N = 100000;
    type seg[4*N+5][2];
    std::vector <type> a;
     
    void init(int node, int u, int v) {
        if(u > v) {
            return;
        }
        if(u == v) {
            seg[node][0] = a[u];
            seg[node][1] = invalid;
            return;
        }
        init(2*node+1, u, (u+v)/2);
        init(2*node+2, (u+v)/2+1, v);
        for (int k = 0, i = 0, j = 0; k < 2; k ++) {
            if (seg[2*node+1][i] > seg[2*node+2][j]) {
                seg[node][k] = seg[2*node+1][i++];
            } else {
                seg[node][k] = seg[2*node+2][j++];
            }
        }
    }

    void init(std::vector <type> &d) {
        a = d;
        init(0, 0, int(a.size()-1));
    }
     
    void update(int node, int u, int v, int x, type val) {
        if(v < x || u > x){
            return;
        }
        if(u == v) {
            seg[node][0] = val;
            seg[node][1] = invalid;
            return;
        }
        if (x <= (u+v)/2) {
            update(2*node+1, u, (u+v)/2, x, val);
        } else {
            update(2*node+2, (u+v)/2+1, v, x, val);
        }
        for (int k = 0, i = 0, j = 0; k < 2; k ++) {
            if (seg[2*node+1][i] > seg[2*node+2][j]) {
                seg[node][k] = seg[2*node+1][i++];
            } else {
                seg[node][k] = seg[2*node+2][j++];
            }
        }
    }

    void update(int x, type val) {
        update(0, 0, int(a.size())-1, x, val);
    }
 
    vector <int> read(int node, int u, int v, int x, int y) {
        if (x > y || v < x || u > y) {
            return {invalid, invalid};
        }
        if(x <= u && v <= y) {
            return {seg[node][0], seg[node][1]};
        }
        auto a = read(2*node+1, u, (u+v)/2, x, y);
        auto b = read(2*node+2, (u+v)/2+1 ,v, x, y);
        auto c = a;
        for (int k = 0, i = 0, j = 0; k < 2; k ++) {
            if (a[i] > b[j]) {
                c[k] = a[i++];
            } else {
                c[k] = b[j++];
            }
        }
        return c;
    }

    type read(int u, int v) {
        auto x = read(0, 0, int(a.size())-1, u, v);
        return x[0] + x[1];
    }
};

using namespace point_update;

int main () {
    int n;
    scanf("%d\n", &n);
    vector <int> a(n);
    repe(&x, a) {
        scanf("%d", &x);
    }
    init(a);
    int q;
    scanf("%d", &q);
    rep(i, q) {
        char o[2];
        int l, r;
        scanf("%s%d%d", o, &l, &r);
        if (o[0] == 'U') {
            update(l-1, r);
        } else {
            printf("%d\n", read(l-1, r-1));
        }
    }
    return 0;
}
