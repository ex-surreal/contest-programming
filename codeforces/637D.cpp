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
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector <int> a(n);
    repe(&x, a) {
        cin >> x;
    }
    sort(all(a));
    int l = 0;
    vector <int> ans;
    rep(i, n) {
        if (a[i]-l-1 < s || d < 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (a[i]-l-1 > 0) {
            ans.pb(a[i]-l-1);
        }
        int j = i+1;
        while (j < n && a[j]-a[i]+2 <= d && a[j]-a[j-1]-2 < s) {
            j ++;
        }
        ans.pb(a[j-1]-a[i]+2);
        l = a[j-1]+1;
        i = j-1;
    }
    if (l < m) {
        ans.pb(m-l);
    }
    rep(i, sz(ans)) {
        if (i&1) {
            cout << "JUMP " << ans[i] << "\n";
        } else {
            cout << "RUN " << ans[i] << "\n";
        }
    }
    return 0;
}
