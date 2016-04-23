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

list <int> A[100005];
int C[100005];
int T[100005];
int L[100005];
int G[100005];
int P[100005];
int S[100005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m , q;
    cin >> n >> m >> q;
    rep(i, n) {
        cin >> G[i+1];
        C[G[i+1]] ++;
    }
    rep(i, n) {
        P[i+1] = i+1;
        A[i+1].pb(i+1);
        S[i+1] = 1;
    }
    rep(i, q) {
        int u, v;
        cin >> u >> v;
        u = P[u], v = P[v];
        if (u == v) {
            continue;
        }
        if (S[u] < S[v]) {
            swap(u, v);
        }
        repe(x, A[v]) {
            P[x] = u;
            T[G[x]] = 0;
        }
        repe(x, A[v]) {
            T[G[x]] ++;
        }
        repe(x, A[v]) {
            if (T[G[x]] < C[G[x]]) {
                L[G[x]] = i+1;
            }
        }
        A[u].splice(A[u].end(), A[v]);
        S[u] += S[v];
        S[v] = 0;
    }
    repi(v, 1, n+1) {
        repe(x, A[v]) {
            T[G[x]] = 0;
        }
        repe(x, A[v]) {
            T[G[x]] ++;
        }
        repe(x, A[v]) {
            if (T[G[x]] < C[G[x]]) {
                L[G[x]] = -1;
            }
        }
    }
    repi(i, 1, m+1) {
        cout << L[i] << "\n";
    }
    return 0;
}
