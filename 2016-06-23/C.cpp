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

int tree[(1<<10)+5][(1<<10)+5];

int read(int i, int j) {
    int ret = 0;
    while (i > 0) {
        int t = j;
        while (t > 0) {
            ret += tree[i][t];
            t -= t&-t;
        }
        i -= i&-i;
    }
    return ret;
}

void update(int i, int j, int v) {
    while (i <= (1<<10)) {
        int t = j;
        while (t <= (1<<10)) {
            tree[i][t] += v;
            t += t&-t;
        }
        i += i&-i;
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int o;
    while (cin >> o && o != 3) {
        switch (o) {
            case 0:
                int n;
                cin >> n;
                break;
            case 1:
                int x, y, v;
                cin >> x >> y >> v;
                update(x+1, y+1, v);
                break;
            case 2:
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                int sum = read(c+1, d+1) - read(a, d+1) - read(c+1, b) + read(a, b);
                cout << sum << "\n";
                break;
        }
    }
    return 0;
}
