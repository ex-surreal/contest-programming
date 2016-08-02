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

vector <int> delta[2], inv;
int mod = 1e9+7;

int pwr(int b, int e) {
    int ret = 1;
    while (e > 0) {
        if (e&1) {
            ret = 1ll*ret*b % mod;
        }
        b = 1ll*b*b % mod;
        e >>= 1;
    }
    return ret;
}

vector <int> factor; 

void precompute(int n = 1000006) {
    factor.resize(n);
    inv.resize(n);
    delta[0].resize(n);
    delta[1].resize(n);
    factor[0] = factor[1] = 1;
    for (int i = 2; i < n; i ++) {
        if (factor[i] == 0) {
            for (int j = i; j < n; j += i) {
                factor[j] = i;
            }
        }
    }
    inv[1] = 1;
    repi(i, 2, n) {
        inv[i] = pwr(i, mod-2);
        if (factor[i] == i) {
            delta[0][i] = 1ll*(i-1)*inv[i] % mod;
            delta[1][i] = 1ll*i*inv[i-1] % mod;
        }
    }
}

vector <int> tree;

void update(int id, int v) {
    while (id < sz(tree)) {
        tree[id] = 1ll*tree[id]*v % mod;
        id += id&-id;
    }
}

int read(int id) {
    int ret = 1;
    while (id > 0) {
        ret = 1ll*ret*tree[id] % mod;
        id -= id&-id;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    precompute(1000005);
    vector <int> a(n), now(1000006);
    vector <vector <int> > pos(1000006);
    rep(i, n) {
        cin >> a[i];
        int t = a[i];
        while (t > 1) {
            int p = factor[t];
            pos[p].push_back(i);
            while (t % p == 0) {
                t /= p;
            }
        }
    }
    int q;
    cin >> q;
    vector <vector <int> > query(n), id(n);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        query[l-1].push_back(r-1);
        id[l-1].push_back(i);
    }
    tree = vector <int>(n+1, 1);
    rep(i, n) {
        update(i+1, a[i]);
        int t = a[i];
        while (t > 1) {
            int p = factor[t];
            while (t % p == 0) {
                t /= p;
            }
            if (pos[p][now[p]] == i) {
                update(i+1, delta[0][p]);
            }
        }

    }
    vector <int> ans(q);
    rep(i, n) {
        rep(j, sz(query[i])) {
            ans[id[i][j]] = read(query[i][j]+1);
        }
        int t = a[i];
        update(i+1, inv[a[i]]);
        while (t > 1) {
            int p = factor[t];
            while (t % p == 0) {
                t /= p;
            }
            update(i+1, delta[1][p] % mod);
            now[p] ++;
            if (now[p] < sz(pos[p])) {
                update(pos[p][now[p]]+1, delta[0][p]);
            }
        }
    }
    repe(e, ans) {
        cout << e << "\n";
    }
    return 0;
}
