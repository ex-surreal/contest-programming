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
    seg[node] = max(seg[node*2+1], seg[node*2+2]);
}

int read(int node, int l, int r, int x, int y, int Y) {
    if (r < x || l > y) {
        return -1;
    }
    if (l == r) {
        return (seg[node] > Y ? l : -1);
    }
    if (x <= l && r <= y) {
        int q = -1;
        if (seg[node*2+1] > Y) {
            q = read(node*2+1, l, (l+r)/2, x, y, Y);
        } else if (seg[node*2+2] > Y) {
            q = read(node*2+2, (l+r)/2+1, r, x, y, Y);
        }
        return q;
    }
    int p = read(node*2+1, l, (l+r)/2, x, y, Y);
    int q = read(node*2+2, (l+r)/2+1, r, x, y, Y);
    if (p != -1) {
        q = p;
    }
    return q;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    repe(&e, seg) {
        e = -(1<<30);
    }
    int n;
    cin >> n;
    map <int, int> id;
    set <int> st;
    vector <int> x(n), y(n), val;
    vector <string> o(n);
    rep(i, n) {
        cin >> o[i] >> x[i] >> y[i];
        st.insert(x[i]);
    }
    repe(e, st) {
        id[e] = sz(val);
        val.pb(e);
    }
    multiset <int> X;
    vector <set <int> > Y(sz(val));
    vector <int> M(sz(val), -(1<<30));
    rep(i, n) {
        int a = id[x[i]], b = y[i];
        if (o[i] == "add") {
            X.insert(a);
            Y[a].insert(b);
            if (b > M[a]) {
                M[a] = b;
                update(0, 0, sz(val)-1, a, b);
            }
        } else if (o[i] == "remove") {
            X.erase(X.find(a));
            Y[a].erase(b);
            if (Y[a].begin() == Y[a].end()) {
                update(0, 0, sz(val)-1, a, -(1<<30));
                M[a] = -(1<<30);
            } else if (*Y[a].rbegin() < M[a]) {
                update(0, 0, sz(val)-1, a, *Y[a].rbegin());
                M[a] = *Y[a].rbegin();
            }
        } else {
            auto f = X.upper_bound(a);
            if (f == X.end()) {
                cout << "-1\n";
                continue;
            }
            int t = read(0, 0, sz(val)-1, *f, sz(val)-1, b);
            if (t == -1) {
                cout << "-1\n";
                continue;
            }
            auto k = Y[t].upper_bound(b);
            cout << val[t] << " " << *k << "\n";
        }
    }
    return 0;
}
