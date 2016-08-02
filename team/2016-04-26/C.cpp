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

#define sq(x) (1ll*(x)*(x))

long long D[205][205];
int parent[205][205];

struct point {
public:
    int x, y, z;
    point(int x = 0, int y = 0, int z = 0) {
        this->x = x, this->y = y, this->z = z;
    }
};

long long sqdis(point a, point b) {
    return sqrt(1.0*sq(a.x-b.x)+sq(a.y-b.y)+sq(a.z-b.z));
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    bool first = true;
    while (cin >> n >> m) {
        if (!first) {
            cout << "\n";
        }
        first = false;
        vector <point> a(n);
        repe(&x, a) {
            int z;
            cin >> z >> x.x >> x.y;
            x.z = z*5;
        }
        rep(i, n) {
            rep(j, n) {
                D[i][j] = LLONG_MAX/3;
                parent[i][j] = -1;
            }
        }
        rep(i, n) {
            D[i][i] = 0;
        }
        rep(i, m) {
            int x, y;
            string way;
            cin >> x >> y >> way;
            if (way == "walking" || way == "stairs") {
                D[x][y] = min(sqdis(a[x], a[y]), D[x][y]);
                D[y][x] = min(sqdis(a[y], a[x]), D[y][x]);
            } else if (way == "lift") {
                D[x][y] = D[y][x] = 1;
            } else if (way == "escalator") {
                D[x][y] = 1;
                D[y][x] = min(D[y][x], sqdis(a[y], a[x])*3);
            } else {
                assert(false);
            }
        }
        rep(i, n) {
            rep(j, n) {
                if (i == j) {
                    continue;
                }
                if (D[i][j] < LLONG_MAX/3) {
                    parent[i][j] = j;
                }
            }
        }
        rep(k, n) {
            rep(i, n) {
                rep(j, n) {
                    if (D[i][j] > D[i][k]+D[k][j]) {
                        D[i][j] = D[i][k]+D[k][j];
                        parent[i][j] = parent[i][k];
                    }
                }
            }
        }
        int q;
        cin >> q;
        rep(i, q) {
            int x, y;
            cin >> x >> y;
            while (parent[x][y] != -1) {
                cout << x << " ";
                x = parent[x][y];
            }
            cout << y << "\n";
        }
    }
    return 0;
}
