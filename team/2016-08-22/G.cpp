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

double dp[220][6][6][6][6];
bool seen[220][6][6][6][6];
vector <vector <pair <int, int> > > go;
vector <int> who;

double solve(int i, int a, int b, int c, int d) {
    if (i == sz(who)) {
        return 0;
    }
    double &ret = dp[i][a][b][c][d];
    if (!seen[i][a][b][c][d]) {
        seen[i][a][b][c][d] = true;
        vector <int> f = {
            (a < 5 ? go[who[i-4]][a].y : -1),
            (b < 5 ? go[who[i-3]][b].y : -1),
            (c < 5 ? go[who[i-2]][c].y : -1),
            (d < 5 ? go[who[i-1]][d].y : -1)
        };
        if (who[i] >= 0) {
            ret = 0;
            rep(j, sz(go[who[i]])) {
                if (find(all(f), go[who[i]][j].y) == f.end()) {
                    ret = max(ret, solve(i+1, b, c, d, j) + .01*go[who[i]][j].x);
                }
            }
        } else {
            ret = solve(i+1, b, c, d, 5);
        }
    }
    return ret;
}

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int n, m, g;
        scanf("%d%d%d", &n, &m, &g);
        go.clear(), go.resize(m);
        rep(i, m) {
            rep(j, n) {
                int p;
                scanf("%d", &p);
                go[i].push_back(mp(p, j));
            }
            sort(go[i].rbegin(), go[i].rend());
            go[i].resize(5);
        }
        who.resize(g+10);
        rep(i, g+10) {
            scanf("%d", &who[i]);
            who[i] --;
        }
        mem(seen, false);
        printf("%.2lf\n", solve(0, 5, 5, 5, 5));
    }
    return 0;
}
