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

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m, A, B;
    while (cin >> m >> n >> A >> B) {
        vector <string> s(m);
        vector <vector <int> > c(m);
        rep(i, m) {
            cin >> s[i];
            c[i] = vector <int>(n);
        }
        set <pair <int, pair <int, int> > > Q;
        long long cost = 0;
        rep(i, m) {
            rep (j, n) {
                rep(t, 4) {
                    int x = i+di[t];
                    int y = j+dj[t];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (s[i][j] != s[x][y]) {
                            c[i][j] ++;
                        }
                    }
                }
                cost += c[i][j]*A;
                Q.insert(mp(c[i][j], mp(i, j)));
            }
        }
        cost /= 2;
        long long ans = cost, r = 0;
        rep(p, m*n) {
            auto it = Q.end();
            it --;
            int w = it->x;
            int i = it->y.x;
            int j = it->y.y;
            Q.erase(it);
            c[i][j] = 0;
            rep(t, 4) {
                int x = i+di[t];
                int y = j+dj[t];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (s[i][j] != s[x][y]) {
                        Q.erase(mp(c[x][y], mp(x, y)));
                        c[x][y] --;
                        Q.insert(mp(c[x][y], mp(x, y)));
                    } else {
                        Q.erase(mp(c[x][y], mp(x, y)));
                        c[x][y] ++;
                        Q.insert(mp(c[x][y], mp(x, y)));
                        c[i][j] ++;
                    }
                }
            }
            s[i][j] = (s[i][j] == '.' ? '#' : '.');
            Q.insert(mp(c[i][j], mp(i, j)));
            cost -= w*A-c[i][j]*A;
            r += B;
            ans = min(ans, cost+r);
        }
        cout << ans << "\n";
    }
    return 0;
}
