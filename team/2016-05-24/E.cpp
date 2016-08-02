#include <bits/stdc++.h>

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

const int MAX = 5000;
int least[MAX];

int coord(pair <int, int> a) {
    if (a.x > 0 && a.y > 0) {
        return 0;
    } else if (a.x > 0 && a.y < 0) {
        return 1;
    } else if (a.y < 0) {
        return 2;
    } 
    return 3;
}

bool comp(pair <int, int> a, pair <int, int> b) {
    if (coord(a) != coord(b)) {
        return coord(a) < coord(b);
    }
    return 1ll*a.x*b.y < 1ll*a.y*b.x;
}

vector <pair <int, int> > get(int n) {
    vector <pair <int, int>> ret;
    repi(i, 2, MAX) {
        repi(j, 1, i) {
            if (least[i] != least[j]) {
                ret.pb(mp(i, j));
                if (sz(ret) == n) {
                    return ret;
                }
                ret.pb(mp(j, i));
                if (sz(ret) == n) {
                    return ret;
                }
                ret.pb(mp(-i, -j));
                if (sz(ret) == n) {
                    return ret;
                }
                ret.pb(mp(-j, -i));
                if (sz(ret) == n) {
                    return ret;
                }
            }
        }
    }
    assert(sz(ret) < n);
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    for (int i = 2; i*i < MAX; i ++) {
        if (least[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                if (least[j] == 0) {
                    least[j] = i;
                }
            }
        }
    }
    int n;
    cin >> n;
    auto d = get(n);
    sort(all(d), comp);
    long long x = 0, y = 0;
    rep(i, n) {
        cout << x << " " << y << "\n";
        /* cout << "(" << x << ", " << y << ")"; */
        assert(0 <= x && x <= 40000000 && 0 <= y && y <= 40000000);
        x += d[i].x;
        y += d[i].y;
    }
    return 0;
}
