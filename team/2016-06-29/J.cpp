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

vector <int> tree[20];
vector <int> id;

void merge_sort(int d, int u, int v) {
    if (u == v) {
        tree[d][u] = id[u];
        return;
    }
    int m = (u+v) >> 1;
    merge_sort(d+1, u, m);
    merge_sort(d+1, m+1, v);
    merge(
        tree[d+1].begin()+u,
        tree[d+1].begin()+m+1,
        tree[d+1].begin()+m+1,
        tree[d+1].begin()+v+1,
        tree[d].begin()+u
    );
}

int query(int x, int y, int k) {
    int u = 0, v = sz(id) - 1, d = 0;
    while (u != v) {
        int m = (u+v) >> 1;
        int c = upper_bound(
            tree[d+1].begin()+u, tree[d+1].begin()+m+1, y
        ) - lower_bound(
            tree[d+1].begin()+u, tree[d+1].begin()+m+1, x
        );
        if (c >= k) {
            v = m;
        } else {
            k -= c;
            u = m+1;
        }
        d ++;
    }
    return u;
}

int main () {
    int n, q;
    scanf("%d%d", &n, &q);
    vector <int> a(n);
    rep(i, 20) {
        tree[i].resize(n);
    }
    set <int> st;
    rep(i, n) {
        cin >> a[i];
        st.insert(a[i]);
    }
    id.resize(n);
    int z = 0;
    map <int, int> X;
    repe(s, st) {
        X[s] = z++;
    }
    rep(i, n) {
        id[X[a[i]]] = i;
    }
    merge_sort(0, 0, n-1);
    rep(i, q) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", a[id[query(l-1, r-1, k)]]);
    }
    return 0;
}
