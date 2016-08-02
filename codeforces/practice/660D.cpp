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
    vector <int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    map <pair <int, int>, int> cnt;
    rep(i, n) {
        rep(j, i) {
            cnt[mp(x[i]+x[j], y[i]+y[j])] ++;
        }
    }
    long long ans = 0;
    repe(c, cnt) {
        ans += c.y*(c.y-1)/2;
    }
    cout << ans;
    return 0;
}
