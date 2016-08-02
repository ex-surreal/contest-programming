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

int D[505][505];
int X[505][505], Y[505][505];

class node {
public:
    int x, y;
    node(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

bool operator < (node a, node b) {
    return a.x*b.y < a.y*b.x;
}

bool seen[505];

void djk(int s, int n) {
    rep(i, n) {
        X[s][i] = 1, Y[s][i] = 0;
        seen[i] = false;
    }
    set <pair <node, int> > Q;
    X[s][s] = 0, Y[s][s] = 0;
    Q.insert(mp(node(X[s][s], Y[s][s]), s));
    while (!Q.empty()) {
        int u = Q.begin()->y;
        Q.erase(Q.begin());
        seen[u] = true;
        int ny = Y[s][u]+1, nx;
        rep(v, n) {
            nx = X[s][u]+D[u][v];
            if (!seen[v] && X[s][v]*ny > Y[s][v]*nx) {
                Q.erase(mp(node(X[s][v], Y[s][v]), v));
                X[s][v] = nx, Y[s][v] = ny;
                Q.insert(mp(node(X[s][v], Y[s][v]), v));
            }
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n) {
        rep(j, n) {
            cin >> D[i][j];
        }
    }
    rep(i, n) {
        djk(i, n);
    }
    int ansX = 1, ansY = 0;
    rep(i, n) {
        rep(j, n) {
            if (i == j) {
                continue;
            }
            int nx = X[i][j]+X[j][i];
            int ny = Y[i][j]+Y[j][i];
            if (1ll*ansX*ny > 1ll*ansY*nx) {
                ansX = nx, ansY = ny;
            }
        }
    }
    int g = __gcd(ansX, ansY);
    cout << ansX/g << "/" << ansY/g;
    return 0;
}
