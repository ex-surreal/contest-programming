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

string str;
vector <tuple <int, int> > seg;

void init(int node, int i, int j) {
    if (i == j) {
        if (str[i] == '(') {
            seg[node] = make_tuple(0, 1);
        } else {
            seg[node] = make_tuple(1, 0);
        }
        return;
    }
    init(node*2+1, i, (i+j)/2);
    init(node*2+2, (i+j)/2+1, j);
    int lp, lq, rp, rq;
    tie(lp, rp) = seg[node*2+1];
    tie(lq, rq) = seg[node*2+2];
    seg[node] = make_tuple(lp+lq-min(rp, lq), rp+rq-min(rp, lq));
}

tuple <int, int> query(int node, int i, int j, int x) {
    if (j < x || i > x) {
        return make_tuple(0, 0);
    }
    if (i == j) {
        int l, r;
        tie(l, r) = seg[node];
        seg[node] = make_tuple(r, l);
        return seg[node];
    }
    if (x <= (i+j)/2) {
        query(node*2+1, i, (i+j)/2, x);
    } else {
        query(node*2+2, (i+j)/2+1, j, x);
    }
    int lp, lq, rp, rq;
    tie(lp, rp) = seg[node*2+1];
    tie(lq, rq) = seg[node*2+2];
    seg[node] = make_tuple(lp+lq-min(rp, lq), rp+rq-min(rp, lq));
    return seg[node];
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, cas = 0;
    while (cin >> n) {
        cin >> str;
        seg.resize(4*n);
        init(0, 0, n-1);
        int q;
        cin >> q;
        int l, r;
        tie(l, r) = seg[0];
        string lst = (l == 0 && r == 0 ? "YES" : "NO");
        cout << "Test " << ++cas << ":\n";
        rep(i, q) {
            int x;
            cin >> x;
            if (x == 0) {
                cout << lst << "\n";
            } else {
                tie(l, r) = query(0, 0, n-1, x-1);
                lst = (l == 0 && r == 0 ? "YES" : "NO");
            }
        }
    }
    return 0;
}
