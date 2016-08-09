#include <iostream>
#include <cstdio>
#include <bitset>
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

vector <int> tree;

void update(int i, int v) {
    while (i < sz(tree)) {
        tree[i] ^= v;
        i += i&-i;
    }
}

int read(int i) {
    int ret = 0;
    while (i > 0) {
        ret ^= tree[i];
        i -= i&-i;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a(n+1), x(n+1);
    a.resize(n+1);
    tree.resize(n+1);
    rep(i, n) {
        cin >> a[i+1];
        x[i+1] = a[i+1] ^ x[i];
    }
    int m;
    cin >> m;
    vector <vector <pair <int, int> > > q(n+1);
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        q[r].push_back(mp(l, i));
    }
    map <int, int> last;
    vector <int> ans(m);
    repi(i, 1, n+1) {
        if (last.find(a[i]) != last.end()) {
            update(last[a[i]], a[i]);
        }
        update(i, a[i]);
        last[a[i]] = i;
        repe(p, q[i]) {
            ans[p.y] = read(i)^read(p.x-1)^x[i]^x[p.x-1];
        }
    }
    repe(a, ans) {
        cout << a << "\n";
    }
    return 0;
}
