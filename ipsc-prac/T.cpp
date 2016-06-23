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

vector <int> color;
vector <tuple <int, int, int> > circles;

bool dfs(int u, int c = 0) {
    color [u] = c;
    int x1, y1, r1;
    tie(x1, y1, r1) = circles[u];
    bool ret = true;
    rep(v, sz(circles)) {
        if (u == v) {
            continue;
        }
        int x2, y2, r2;
        tie(x2, y2, r2) = circles[v];
        x2 -= x1, y2 -= y1;
        if (1ll*x2*x2 + 1ll*y2*y2 > (r1+r2)*(r1+r2)) {
            continue;
        }
        if (color[v] == -1) {
            ret = ret && dfs(v, c^1);
        } else if (color[v] != (c^1)) {
            ret = false;
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string str[] = {"clockwise", "counterclockwise"};
    int tst;
    cin >> tst;
    while (tst --) {
        int n;
        cin >> n;
        circles.resize(n);
        color.resize(n);
        fill(all(color), -1);
        int r1 = -1, rn;
        rep(i, n) {
            int x, y, r;
            cin >> x >> y >> r;
            if (r1 == -1) {
                r1 = r;
            }
            rn = r;
            circles[i] = make_tuple(x, y, r);
        }
        int g = __gcd(r1, rn);
        r1 /= g, rn /= g;
        auto f = dfs(0, 0);
        if (color[n-1] != -1 && f) {
            cout << r1 << "/" << rn << " " << str[color[n-1]] << "\n";
        } else {
            cout << "does not rotate\n";
        }
    }
    return 0;
}
