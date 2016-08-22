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

vector <vector <int> > adj, O;
vector <vector <pair <int, int> > > J;
vector <vector <bool> > is;
vector <bool> inv;
vector <int> cnt, ans;
int m;

void dfs(int u, int c = 0) {
    ans[u] = c;
    rep(r, sz(adj[u])) {
        int v = adj[u][r];
        int o = O[u][r], i, j;
        tie(i, j) = J[u][r];
        switch (o) {
            case 1:
                if (is[i][j] == inv[i]) {
                    is[i][j] = !is[i][j];
                    cnt[i] += (inv[i] ? -1 : +1);
                    dfs(v, c+1);
                    is[i][j] = !is[i][j];
                    cnt[i] += (inv[i] ? +1 : -1);
                } else {
                    dfs(v, c);
                }
                break;
            case 2:
                if (is[i][j] != inv[i]) {
                    is[i][j] = !is[i][j];
                    cnt[i] += (inv[i] ? +1 : -1);
                    dfs(v, c-1);
                    is[i][j] = !is[i][j];
                    cnt[i] += (inv[i] ? -1 : +1);
                } else {
                    dfs(v, c);
                }
                break;
            case 3:
                inv[i] = !inv[i];
                dfs(v, c + (inv[i] ? m-2*cnt[i] : 2*cnt[i]-m));
                inv[i] = !inv[i];
                break;
            default:
                dfs(v, c);
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> m >> q;
    is.resize(n+1, vector <bool>(m+1));
    inv.resize(n+1);
    cnt.resize(n+1);
    ans.resize(q+1);
    adj.resize(q+1);
    O.resize(q+1);
    J.resize(q+1);
    rep(r, q) {
        int i, j = -1, o, t = r;
        cin >> o >> i;
        if (o <= 2) {
            cin >> j;
        }
        if (o == 4) {
            t = i;
        }
        adj[t].push_back(r+1);
        O[t].push_back(o);
        J[t].push_back(mp(i, j));
    }
    dfs(0);
    repi(i, 1, q+1) {
        cout << ans[i] << "\n";
    }
    return 0;
}
