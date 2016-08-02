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

vector <int> ord;
vector <int> adj[1000006];
bool seen[1000006];
bool there[1000006];
int cnt[1000006];
int H[1000006], ch;

void dfs(int u) {
    seen[u] = true;
    repe(v, adj[u]) {
        if (!seen[v]){
            dfs(v);
        }
    }
    ord.pb(u);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n) {
        int k, x;
        cin >> k >> x;
        there[x] = true;
        rep(j, k-1) {
            int y;
            cin >> y;
            there[y] = true;
            adj[x].pb(y);
            x = y;
        }
    }
    rep(i, 1000000) {
        if (there[i+1] && !seen[i+1]) {
            dfs(i+1);
        }
    }
    reverse(all(ord));
    repe(u, ord) {
        repe(v, adj[u]) {
            cnt[v] ++;
        }
    }
    repe(u, ord) {
        if (cnt[u] == 0) {
            H[ch++] = -u;
            push_heap(H, H+ch);
        }
    }
    rep(i, sz(ord)) {
        pop_heap(H, H+ch);
        int u = -H[--ch];
        cout << u << " ";
        repe(v, adj[u]) {
            cnt[v] --;
            if (cnt[v] == 0) {
                H[ch++] = -v;
                push_heap(H, H+ch);
            }
        }
    }
    return 0;
}
