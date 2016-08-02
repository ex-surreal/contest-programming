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

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string p;
    cin >> p;
    vector <int> a(n);
    repe(&x, a) {
        cin >> x;
    }
    vector <int> nxt(n, -1), pre(n, -1), st(n, -1);
    set <pair <int, int> > Q;
    rep(i, n) {
        nxt[i] = (i+1 < n ? i+1 : -1);
        pre[i] = (i-1 >= 0 ? i-1 : -1);
        if (i+1 < n && p[i] != p[i+1]) {
            st[i] = abs(a[i]-a[i+1]);
            Q.insert(mp(st[i], i));
        }
    }
    vector <int> x, y;
    while (!Q.empty()) {
        int u = Q.begin()->y, v = nxt[u];
        Q.erase(Q.begin());
        if (pre[u] != -1 && nxt[v] != -1) {
            if (st[pre[u]] != -1) {
                Q.erase(mp(st[pre[u]], pre[u]));
            }
            if (st[v] != -1) {
                Q.erase(mp(st[v], v));
            }
            nxt[pre[u]] = nxt[v];
            pre[nxt[v]] = pre[u];
            if (p[pre[u]] != p[nxt[v]]) {
                st[pre[u]] = abs(a[pre[u]]-a[nxt[v]]);
                Q.insert(mp(st[pre[u]], pre[u]));
            }
        } else if (pre[u] != -1) {
            if (st[pre[u]] != -1) {
                Q.erase(mp(st[pre[u]], pre[u]));
            }
            nxt[pre[u]] = -1;
        } else if (nxt[v] != -1) {
            if (st[v] != -1) {
                Q.erase(mp(st[v], v));
            }
            pre[nxt[v]] = -1;
        }
        x.pb(u+1), y.pb(v+1);
    }
    cout << sz(x) << "\n";
    rep(i, sz(x)) {
        cout << x[i] << " " << y[i] << "\n";
    }
    return 0;
}
