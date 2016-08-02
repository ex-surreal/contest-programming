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

int H[1005][1005], m, n;
long long k;
bool seen[1005][1005];
vector <pair <int, int> > buffer, ba;
int ans[1005][1005];
int hn, cn;

bool comp(pair <int, int> a, pair <int, int> b) {
    return H[a.x][a.y] < H[b.x][b.y];
}

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};


bool dfs(int x, int y) {
    seen[x][y] = true;
    ba.pb(mp(x, y));
    cn --;
    if (cn == 0) {
        return true;
    }
    rep(t, 4) {
        int i = x+di[t], j = y+dj[t];
        if (i < 0 || i >= m || j < 0 || j >= n) {
            continue;
        }
        if (!seen[i][j] && H[i][j] >= hn) {
            if (dfs(i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    rep(i, m) {
        rep(j, n) {
            cin >> H[i][j];
            if (k % H[i][j] == 0) {
                buffer.pb(mp(i, j));
            }
        }
    }
    sort(all(buffer), comp);
    rep(i, sz(buffer)) {
        int j = i, h = H[buffer[i].x][buffer[i].y];
        mem(seen, false);
        while (j < sz(buffer) && H[buffer[j].x][buffer[j].y] == h) {
            hn = h, cn = k/h;
            ba.clear();
            if (dfs(buffer[j].x, buffer[j].y)) {
                cout << "YES\n";
                repe(x, ba) {
                    ans[x.x][x.y] = h;
                }
                rep(i, m) {
                    rep(j, n) {
                        cout << ans[i][j] << " ";
                    } cout << "\n";
                }
                return 0;
            }
            j ++;
        }
        i = j - 1;
    }
    cout << "NO\n";
    return 0;
}
