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

int D[200005];
int Q[5555];
bool G[5555][5555];

void bfs(int s, int n) {
    rep(i, n) {
        D[i] = -1;
    }
    D[s] = 0;
    int fr = 0, bk = 0;
    Q[bk++] = s;
    while (fr < bk) {
        int u = Q[fr++];
        rep(v, n) {
            if (v != u && !G[u][v] && D[v] == -1) {
                D[v] = D[u]+1;
                Q[bk++] = v;
            }
        }
    }
}

vector <int> adj[200005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int n, m, s;
        cin >> n >> m;
        rep(i, n) {
            adj[i].clear();
        }
        rep(i, m) {
            int x, y;
            cin >> x >> y;
            adj[x-1].pb(y-1);
            adj[y-1].pb(x-1);
        }
        cin >> s;
        s --;
        if (m <= n-2) {
            rep(i, n) {
                D[i] = 1;
            }
            repe(v, adj[s]) {
                D[v] = 2;
            }
            D[s] = 0;
        } else {
            rep(i, n) {
                rep(j, n) {
                    G[i][j] = false;
                }
            }
            rep(u, n) {
                repe(v, adj[u]) {
                    G[u][v] = G[v][u] = true;
                }
            }
            bfs(s, n);
        }
        bool first = true;
        rep(i, n) {
            if (D[i]) {
                if (!first) {
                    cout << " ";
                }
                first = false;
                cout << D[i];
            }
        } cout << "\n";
    }
    return 0;
}
