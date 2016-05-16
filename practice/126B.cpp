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

vector <int> cal_pi(string p) {
    vector <int> pi(sz(p), 0);
    repi(i, 1, sz(p)) {
        int k = pi[i-1];
        while (k > 0 && p[i] != p[k]) {
            k = pi[k-1];
        }
        if (p[i] == p[k]) {
             k++;
        }
        pi[i] = k;
    }
    return pi;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    auto pi = cal_pi(p);
    int ans = 0;
    vector <bool> pos(sz(p)+1, false);
    int k = pi[sz(p)-1];
    while (k > 0) {
        pos[k] = true;
        k = pi[k-1];
    }
    repi(i, 1, sz(pi)-1) {
        if (pos[pi[i]]) {
            ans = max(ans, pi[i]);
        }
    }
    if (ans == 0) {
        cout << "Just a legend";
    } else {
        cout << p.substr(0, ans);
    }
    return 0;
}
