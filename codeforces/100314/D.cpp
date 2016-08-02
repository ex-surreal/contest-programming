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

int alpha = 101;

vector<vector <int> > nxt, ids;

void init() {
    nxt.clear();
    ids.clear();
    nxt.pb(vector <int>(alpha, -1));
    ids.pb(vector <int>());
}

void insert(vector <int> &v, int id) {
    int u = 0;
    repe(x, v) {
        if (nxt[u][x] == -1) {
            nxt[u][x] = sz(nxt);
            nxt.pb(vector <int>(alpha, -1));
            ids.pb(vector <int>());
        }
        u = nxt[u][x];
    }
    ids[u].pb(id);
}

int find(vector <int> &v) {
    int u = 0;
    repe(x, v) {
        u = nxt[u][x];
        if (u == -1) {
            return 0;
        }
    }
    return u;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        string p;
        cin >> p;
        int n;
        cin >> n;
        vector <string> s(n);
        int t = 0;
        init();
        repe(&q, s) {
            cin >> q;
            vector <int> v(28);
            v[0] = *q.begin() - 'a'+1;
            if (sz(q) > 1) {
                v[27] = q.back() - 'a'+1;

            }
            repi(j, 1, sz(q)-1) {
                v[q[j]-'a'+1] ++;
            }
            insert(v, t++);
        }
        vector <int> dp(sz(p)+1, 0), go(sz(p));
        dp[sz(p)] = 1;
        for (int i = sz(p)-1; i >= 0; i --) {
            vector <int> v(28);
            v[0] = p[i] - 'a' + 1;
            int u = find(v);
            dp[i] = min(2, sz(ids[u])*dp[i+1]);
            if (dp[i]) {
                go[i] = ids[u][0];
            }
            for (int j = i+1; j < sz(p) && j-i+1 <= 100; j ++) {
                v[27] = p[j] - 'a' + 1;
                u = find(v);
                dp[i] = min(2, dp[i] + sz(ids[u])*dp[j+1]);
                if (sz(ids[u])*dp[j+1]) {
                    go[i] = ids[u][0];
                }
                v[p[j]-'a'+1] ++;
            }
        }
        if (dp[0] == 1) {
            int pos = 0;
            string sp = "";
            while (pos < sz(p)) {
                cout << sp << s[go[pos]];
                sp = " ";
                pos += sz(s[go[pos]]);
            }
            cout << "\n";
        } else if (dp[0] == 0) {
            cout << "impossible\n";
        } else {
            cout << "ambiguous\n";
        }
    }
    return 0;
}
