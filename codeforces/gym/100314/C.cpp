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

double dp[501][200][11][11];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, r, t;
    cin >> n >> r >> t;
    vector <double> P(2*n);
    vector <vector <int> > F(2*n), E(2*n);
    rep(i, 2*n) {
        cin >> P[i];
        int x, y;
        cin >> x >> y;
        F[i].resize(x);
        E[i].resize(y);
        repe(&e, F[i]) {
            cin >> e;
            e += (i >= n ? n : 0)-1;
        }
        repe(&e, E[i]) {
            cin >> e;
            e += (i < n ? n : 0)-1;
        }
    }
    dp[0][0][0][0] = 1.0;
    rep(i, t) {
        rep(j, 2*n) {
            rep(k, r) {
                rep(l, r) {
                    double a = dp[i][j][k][l]/(sz(F[j])+sz(E[j])+1);
                    if (a > 1e-9) {
                        repe(e, F[j]) {
                            dp[i+1][e][k][l] += a;
                        }
                        repe(e, E[j]) {
                            dp[i+1][e][k][l] += a;
                        }
                    }
                    dp[i+1][(j<n?n:0)][k+(j<n)][l+(j>=n)] += a*P[j];
                    dp[i+1][(j<n?n:0)][k][l] += a*(1.0-P[j]);
                }
            }
        }
    }
    vector <vector <double> > ans(r+1, vector <double>(r+1));
    rep(i, r) {
        rep(j, r) {
            rep(k, 2*n) {
                ans[i][j] += dp[t][k][i][j];
            }
        }
    }
    rep(j, r) {
        rep(k, t+1) {
            rep(i, 2*n) {
                ans[r][j] += dp[k][i][r][j];
                ans[j][r] += dp[k][i][j][r];
            }
        }
    }
    cout.precision(10);
    cout.setf(ios::fixed);
    rep(i, r+1) {
        rep(j, r+(i<r)) {
            cout << ans[i][j] << "\n";
        }
    }
    return 0;
}
