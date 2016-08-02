#include <bits/stdc++.h>

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

int dp[100005][19];

int read(int x, int k) {
    for (int i = 0; (1<<i) <= k; i ++) {
        if ((k>>i)&1) {
            x = dp[x][i];
        }
    }
    return x;
}

void add(int x, int y) {
    dp[y][0] = x;
    for (int i = 0; dp[x][i] != 0; i ++) {
        dp[y][i+1] = dp[x][i];
        x = dp[x][i];
    }
}

void remove(int x) {
    for (int i = 0; dp[x][i] != 0; i ++) {
        dp[x][i] = 0;
    } 
}

void init() {
    repi(j, 1, 19) {
        repi(i, 1, 100005) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int p;
        cin >> p;
        mem(dp, 0);
        rep(i, p) {
            int x, y;
            cin >> x >> y;
            dp[x][0] = y;
        }
        init();
        int q;
        cin >> q;
        rep(i, q) {
            int o, x, y;
            cin >> o;
            if (o == 0) {
                cin >> y >> x;
                add(y, x);
            } else if (o == 1) {
                cin >> x;
                remove(x);
            } else {
                cin >> x >> y;
                cout << read(x, y) << "\n";
            }
        }
    }
    return 0;
}
