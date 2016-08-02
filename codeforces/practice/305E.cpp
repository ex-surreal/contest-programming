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

int g[5005];

int grundy(string p) {
    vector <bool> s(sz(p), false);
    repi(i, 1, sz(p)-1) {
        if (p[i-1] == p[i+1]) {
            s[i] = true;
        }
    }
    int nim = 0;
    rep(i, sz(s)) {
        if (!s[i]) {
            continue;
        }
        int c = 0;
        while (s[i]) {
            c ++;
            i ++;
        }
        nim ^= g[c];
    }
    return nim;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    repi(i, 1, 5005) {
        vector <bool> seen(1<<13, false);
        repi(j, 1, i+1) {
            seen[g[max(0, i-j-1)]^g[max(0, j-2)]] = true;
        }
        g[i] = 0;
        while (seen[g[i]]) {
            g[i] ++;
        }
    }
    string p;
    cin >> p;
    repi(i, 1, sz(p)-1) {
        if (p[i-1] == p[i+1]) {
            if ((grundy(p.substr(0, i)) ^ grundy(p.substr(i+1))) == 0) {
                cout << "First\n" << i+1 << "\n";
                return 0;
            }
        }
    }
    cout << "Second\n";
    return 0;
}
