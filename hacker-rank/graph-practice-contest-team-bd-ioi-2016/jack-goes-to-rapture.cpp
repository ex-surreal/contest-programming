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

int D[50005];
vector <pair <int, int> > adj[50005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
    }
    priority_queue <pair <int, int> > Q;
    mem(D, 0x7f);
    D[1] = 0;
    Q.push(mp(-D[1], 1));
    while (!Q.empty()) {
        int u = Q.top().y;
        int c = -Q.top().x;
        Q.pop();
        if (c > D[u]) {
            continue;
        }
        repe(v, adj[u]) {
            if (D[v.x] > max(D[u], v.y)) {
                D[v.x] = max(D[u], v.y);
                Q.push(mp(-D[v.x], v.x));
            }
        }
    }
    if (D[n] == D[50004]) {
        cout << "NO PATH EXISTS";
    } else {
        cout << D[n];
    }
    return 0;
}
