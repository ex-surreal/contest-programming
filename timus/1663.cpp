#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cassert>
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

long long dp[1005][1005];
vector <long long> P;
vector <int> id;

long long cst(int i, int j) {
    return P[j]*(1000ll/P[i]);
}

long long solve(int i, int j) {
    int k = max(i, (j == sz(P)-1 ? -1 : j))+1;
    if (k == sz(P) - 1) {
        return cst(i, sz(P)-1) + cst(j, 0);
    }
    long long &ret = dp[i][j];
    if (ret == -1) {
        long long p = solve(i, k) + cst(j, k);
        long long q = solve(k, j) + cst(i, k);
        ret = min(p, q);
    }
    return ret;
}

vector <int> F, B;

void go(int i, int j) {
    int k = max(i, (j == sz(P)-1 ? -1 : j))+1;
    if (k == sz(P) - 1) {
        return;
    }
    long long p = solve(i, k) + cst(j, k);
    long long q = solve(k, j) + cst(i, k);
    if (p >= q) {
        F.pb(id[k]);
        go(k, j);
    } else {
        B.pb(id[k]);
        go(i, k);
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <pair <int, int> > p(n);
    rep(i, n) {
        cin >> p[i].x;
        p[i].y = i+1;
    }
    sort(all(p));
    P.resize(n);
    id.resize(n);
    rep(i, n) {
        P[i] = p[i].x;
        id[i] = p[i].y;
    }
    mem(dp, -1);
    F.pb(id[0]);
    B.pb(id.back());
    go(0, n-1);
    repe(x, B) {
        F.pb(x);
    }
    int start = -1;
    rep(i, n) {
        if (F[i] == 1) {
            start = i;
            break;
        }
    }
    assert(start != -1);
    string space = "";
    rep(i, n) {
        cout << space << F[(i+start)%n];
        space = " ";
    }
    cout << "\n";
    return 0;
}
