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

int di[] = {-1,  0, +1,  0};
int dj[] = { 0, +1,  0, -1};

map <char, vector <int> > jump = {
    mp('+', vector <int>({0, 1, 2, 3})),
    mp('-', vector <int>({1, 3})),
    mp('|', vector <int>({0, 2})),
    mp('<', vector <int>({3})),
    mp('>', vector <int>({1})),
    mp('^', vector <int>({0})),
    mp('v', vector <int>({2})),
    mp('U', vector <int>({1, 2, 3})),
    mp('R', vector <int>({0, 2, 3})),
    mp('D', vector <int>({0, 1, 3})),
    mp('L', vector <int>({0, 1, 2})),
    mp('*', vector <int>())
};

tuple <int, int, int> Q[4000006];
vector <string> B;

bool can(int x1, int y1, int x2, int y2, int d) {
    vector <int> v = jump[B[x1][y1]];
    repe(t, v) {
        int dx = di[(t+d)%4], dy = dj[(t+d)%4];
        int x = x1 + dx;
        int y = y1 + dy;
        if (x == x2 && y == y2) {
            return true;
        }
    }
    return false;
}

int D[1005][1005][4];

int bfs(int a, int b, int p, int q) {
    mem(D, -1);
    D[a][b][0] = 0;
    int fr = 0, bk = 0;
    Q[bk++] = make_tuple(a, b, 0);
    while (fr < bk) {
        int i, j, d;
        tie(i, j, d) = Q[fr++];
        vector <int> v = jump[B[i][j]];
        repe(t, v) {
            int dx = di[(t+d)%4], dy = dj[(t+d)%4];
            int x = i + dx;
            int y = j + dy;
            if (0 <= x && x < sz(B) && 0 <= y && y < sz(B.back())) {
                if (can(x, y, i, j, d) && D[x][y][d] == -1) {
                    D[x][y][d] = D[i][j][d] + 1;
                    Q[bk++] = make_tuple(x, y, d);
                }
            }
        }
        repi(t, 1, 2) {
            int td = (d+t)%4;
            if (D[i][j][td] == -1) {
                D[i][j][td] = D[i][j][d] + 1;
                Q[bk++] = make_tuple(i, j, td);
            }
        }
    }
    int ans = -1;
    rep(i, 4) {
        if (D[p][q][i] != -1) {
            if (ans == -1) {
                ans = D[p][q][i];
            } else {
                ans = min(ans, D[p][q][i]);
            }
        }
    }
    return ans;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    B.resize(m);
    rep(i, m) {
        cin >> B[i];
    }
    int a, b, p, q;
    cin >> a >> b >> p >> q;
    cout << bfs(a-1, b-1, p-1, q-1);
    return 0;
}
