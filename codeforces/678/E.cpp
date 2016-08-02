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

bool seen[1<<18][18];
double dp[1<<18][18];
int n;
vector <vector <double> > P;

double solve(int msk, int i) {
    if (msk == 0) {
        return 1.0;
    }
    if (seen[msk][i]) {
        return dp[msk][i];
    }
    double &ret = dp[msk][i];
    double a = 0, b = 1.0;
    rep(j, n) {
        if (!((msk>>j)&1)) {
            continue;
        }
        a += solve(msk^(1<<j), i)*P[i][j];
        b *= solve(msk^(1<<j), j)*P[i][j];
    }
    ret = max(a, b);
    return ret;
}

bool comp(int a, int b) {
    return __builtin_popcount(a) <__builtin_popcount(b);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    P.resize(n);
    repe(&e, P) {
        e.resize(n);
        repe(&c, e) {
            cin >> c;
        }
    }
    vector <int> s(1<<n);
    rep(i, 1<<n) {
        s[i] = i;
    }
    sort(all(s), comp);
    rep(j, n) {
        dp[1<<j][j] = 1;
    }
    repi(k, 1, 1<<n) {
        int p = s[k];
        rep(i, n) {
            if (!((p>>i)&1)) {
                continue;
            }
            rep(j, n) {
                if (!((p>>j)&1)) {
                    dp[p|(1<<j)][i] += P[i][j] * dp[p][i];
                    dp[p|(1<<j)][j] += P[j][i] * dp[p][i];
                }
            }
        }
    }
    cout.precision(12);
    cout.setf(ios::fixed);
    cout << dp[(1<<n)-1][0];
    return 0;
}
