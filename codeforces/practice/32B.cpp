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

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    rep(i, sz(p)) {
        if (p[i] == '.') {
            cout << 0;
        } else if (p[i+1] == '.') {
            i ++;
            cout << 1;
        } else {
            i ++;
            cout << 2;
        }
    }
    return 0;
}
