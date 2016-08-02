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

vector <int> pi;
string p, q, v;
vector <vector <int> > nxt;

void make_pi() {
    pi.resize(sz(v));
    pi[0] = -1;
    repi(i, 1, sz(v)) {
        int k = pi[i-1];
        while (k >= 0 && v[i] != v[k+1]) {
            k = pi[k];
        }
        if (v[k+1] == v[i]) {
            k ++;
        }
        pi[i] = k;
    }
    nxt.resize(sz(v));
    rep(i, sz(v)) {
        nxt[i].resize(26);
        rep(j, 26) {
            int t = i-1;
            while (t >= 0 && v[t+1] != j+'A') {
                t = pi[t];
            }
            if (v[t+1] == 'A'+j) {
                nxt[i][j] = t+2;
            }
        }
    }
}

int dp[105][105][105];

int solve(int i, int j, int k) {
    if (k == sz(v)) {
        return -(1<<28);
    }
    if (i == sz(p) || j == sz(q)) {
        return 0;
    }
    int &ret = dp[i][j][k];
    if (ret == -1) {
        ret = max(solve(i+1, j, k), solve(i, j+1, k));
        if (p[i] == q[j]) {
            ret = max(ret, solve(i+1, j+1, nxt[k][p[i]-'A'])+1);
        }
    }
    return ret;
}

string back(int i, int j, int k) {
    if (i == sz(p) || j == sz(q)) {
        return "";
    }
    if (solve(i, j, k) == solve(i+1, j, k)) {
        return back(i+1, j, k);
    } else if (solve(i, j, k) == solve(i, j+1, k)) {
        return back(i, j+1, k);
    }
    return p[i]+back(i+1, j+1, nxt[k][p[i]-'A']);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> p >> q >> v;
    make_pi();
    mem(dp, -1);
    if (solve(0, 0, 0) == 0) {
        cout << 0;
    } else {
        cout << back(0, 0, 0);
    }
    return 0;
}
