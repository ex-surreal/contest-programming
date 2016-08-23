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

const int lim = 100;
int dp[305][305][lim*2+6];
vector <int> I, J, p, q;

int solve(int i, int j, int d) {
    if (i == sz(I) && j == sz(J)) {
        return 0;
    }
    int &ret = dp[i][j][d+lim];
    if (ret == -1) {
        ret = 1<<29;
        if (d <= 0) {
            if (i < sz(I)) {
                int t = p[I[i]]+(j > 0 && I[i] == J[j-1] ? 0: d);
                ret = solve(i+1, j, t) + max(0, t);
            }
            if (j < sz(J)) {
                ret = min(ret, solve(i, j+1, -q[J[j]]) + q[J[j]]);
            }
        }
        if (d >= 0) {
            if (j < sz(J)) {
                int t = -q[J[j]]+(i > 0 && J[j] == I[i-1] ? 0: d);
                ret = solve(i, j+1, t) + max(0, -t);
            }
            if (i < sz(I)) {
                ret = min(ret, solve(i+1, j, p[I[i]]) + p[I[i]]);
            }
        }
    }
    return ret;
}

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n;
        scanf("%d", &n);
        p.resize(n);
        q.resize(n);
        repe(&e, p) {
            scanf("%d", &e);
        }
        repe(&e, q) {
            scanf("%d", &e);
        }
        int a, b;
        scanf("%d%d", &a, &b);
        I.resize(a);
        J.resize(b);
        repe(&e, I) {
            scanf("%d", &e);
            e --;
        }
        repe(&e, J) {
            scanf("%d", &e);
            e --;
        }
        rep(i, a+1) {
            rep(j, b+1) {
                mem(dp[i][j], -1);
            }
        }
        int ans = 1<<29;
        repi(k, -100, 101) {
            ans = min(ans, abs(k)+solve(0, 0, k));
        }
        printf("%d\n", ans);
    }
    return 0;
}
