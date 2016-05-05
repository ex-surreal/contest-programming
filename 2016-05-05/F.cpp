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

int A[2][20];
int r[20], g[20];
int n;

bool back(int d, int now) {
    if (*max_element(A[now], A[now]+n) == n) {
        return true;
    }
    if (d > n) {
        return false;
    }
    int pre = now^1;
    rep(i, n) {
        A[now][i] = 0;
    }
    rep(i, n) {
        A[now][r[i]] += A[pre][i];
    }
    if (back(d+1, pre)) {
        return true;
    }
    rep(i, n) {
        A[now][i] = 0;
    }
    rep(i, n) {
        A[now][g[i]] += A[pre][i];
    }
    return back(d+1, pre);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int cas;
        cin >> cas >> n;
        rep(i, n) {
            cin >> r[i];
        }
        rep(i, n) {
            cin >> g[i];
        }
        rep(i, n) {
            A[1][i] = 1;
        }
        if (back(0, 0)) {
            cout << cas << " YES\n";
        } else {
            cout << cas << " NO\n";
        }
    }
    return 0;
}
