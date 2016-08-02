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

int lft[1005][1005];
int rgt[1005][1005];
int up[1005][1005];
int dwn[1005][1005];
int row[4][1005][1005];
int col[4][1005][1005];
int pos[4][1005][1005];
int neg[4][1005][1005];

bool bigger(int x1, int x2, int y1, int y2) {
    return (x1-x2)*log(2) + (y1-y2)*log(3) > 1;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <string> s(n);
    repe(&e, s) {
        cin >> e;
    }

    rep(i, n) {
        for (int j = 0, lst = -1; j < n; j ++) {
            if (s[i][j] == '0') {
                lst = j;
            }
            lft[i][j] = lst;
        }
        for (int j = n-1, lst = n; j >= 0; j --) {
            if (s[i][j] == '0') {
                lst = j;
            }
            rgt[i][j] = lst;
        }
        for (int j = 0, lst = -1; j < n; j ++) {
            if (s[j][i] == '0') {
                lst = j;
            }
            up[j][i] = lst;
        }
        for (int j = n-1, lst = n; j >= 0; j --) {
            if (s[j][i] == '0') {
                lst = j;
            }
            dwn[j][i] = lst;
        }
    }
    rep(i, n) {
        rep(j, n) {
            rep(k, 4) {
                row[k][i][j] = (s[i][j] == '0'+k) + (j > 0 ? row[k][i][j-1] : 0);
                col[k][j][i] = (s[j][i] == '0'+k) + (i > 0 ? row[k][i-1][j] : 0);
            }
        }
    }
    int x = 0, y = -1;
    rep(i, n) {
        rep(j, n) {
            if (s[i][j] != '0') {
                int d = min(min(i-up[i][j], dwn[i][j]-i), min(j-lft[i][j], rgt[i][j]-j));
                int x1 = row[2][i][j+d]-row[2][i][j-d-1] + col[2][i+d][j]-col[2][i-d-1][j] - (s[i][j] == '2');
                int y1 = row[3][i][j+d]-row[3][i][j-d-1] + col[3][i+d][j]-col[3][i-d-1][j] - (s[i][j] == '3');
                if (bigger(x1, y1, x, y)) {
                    x = x1, y = y1;
                }
            }
        }
    }
    int ans = 0;
    if (y != -1) {
        ans = 1;
        int mod = 1e9+7;
        rep(i, x) {
            ans = (ans+ans)%mod;
        }
        rep(i, y) {
            ans = 3ll*ans%mod;
        }
    }
    cout << ans;
    return 0;
}
