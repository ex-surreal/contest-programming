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
    int n;
    cin >> n;
    map <int, int> cnt;
    rep(i, n) {
        int a;
        cin >> a;
        cnt[a] ++;
    }
    int m;
    cin >> m;
    vector <int> b(m), c(m);
    rep(i, m) {
        cin >> b[i];
    }
    rep(i, m) {
        cin >> c[i];
    }
    int ans = 0;
    rep(i, m) {
        if (cnt[b[i]] > cnt[b[ans]]) {
            ans = i;
        } else if (cnt[b[i]] == cnt[b[ans]]) {
            if (cnt[c[i]] > cnt[c[ans]]) {
                ans = i;
            }
        }
    }
    cout << ans+1;
    return 0;
}
