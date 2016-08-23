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

double dp[2005][2005];
bool seen[2005][2005];
vector <pair <int, int> > p;

double dis(int i, int j) {
    return sqrt(1.0*(p[i].x-p[j].x)*(p[i].x-p[j].x) + 1.0*(p[i].y-p[j].y)*(p[i].y-p[j].y));
}

double solve(int i, int j) {
    int k = min(i, j)-1;
    if (k == 0) {
        return dis(k, i) + dis(k, j);
    }
    double &ret = dp[i][j];
    if (!seen[i][j]) {
        seen[i][j] = true;
        ret = min(solve(k, j)+dis(i, k), solve(i, k)+dis(j, k));
    }
    return ret;
}

int main () {
    int n;
    while (scanf("%d", &n) != EOF) {
        p.resize(n);
        rep(i, n) {
            cin >> p[i].x >> p[i].y;
        }
        if (n == 1) {
            printf("%.2lf\n", 0.);
            continue;
        }
        sort(all(p));
        rep(i, n) {
            rep(j, n) {
                seen[i][j] = false;
            }
        }
        printf("%.2lf\n", solve(n-1, n-1));
    }
    return 0;
}
