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

int S[200005];
int W[500005];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    mem(W, -1);
    int ans = 0;
    rep(i, n) {
        int k;
        cin >> k;
        vector <int> d(k);
        repe(&c, d) {
            cin >> c;
        }
        map <int, int> cnt;
        repe(c, d) {
            if (W[c] != -1) {
                cnt[W[c]] ++;
            }
        }
        bool f = true;
        repe(e, cnt) {
            if (e.y != S[e.x]) {
                f = false;
                break;
            }
        }
        if (!f) {
            continue;
        }
        ans ++;
        repe(c, d) {
            if (W[c] != -1) {
                S[W[c]] = 0;
            }
            W[c] = i;
            S[i] ++;
        }
    }
    cout << ans << "\n";
    return 0;
}
