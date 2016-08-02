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

#define in(x, a, b) ((a) <= (x) && (x) <= (b))

bool is_valid(string p) {
    if (sz(p) != 8) {
        return false;
    }
    if (!in(p[0], '1', '9') || p[0] != p[1]) {
        return false;
    }
    if (!in(p[2], '1', '9') || !in(p[3], '1', '9')) {
        return false;
    }
    if (!in(p[4], 'A', 'Z')) {
        return 0;
    }
    return in(p[5], '1', '9') && in(p[6], '1', '9') && in(p[7], '1', '9');
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        rep(i, n) {
            string s;
            cin >> s;
            if (is_valid(s)) {
                cout << s << "\n";
            }
        }
    }
    return 0;
}
