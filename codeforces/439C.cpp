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
    int n, k, p, odd = 0;
    cin >> n >> k >> p;
    vector <int> a(n);
    rep(i, n) {
        cin >> a[i];
        odd += a[i]%2;
    }
    if (odd < k-p || (odd-k+p)%2 || (odd-k+p)/2+(n-odd) < p) {
        cout << "NO\n";
        return 0;
    }
    vector <vector <int> > ans(k);
    int x = k-p, y = p;
    rep(i, n) {
        if (a[i]&1) {
            if (x > 0) {
                x --;
                ans[p+x].pb(a[i]);
            } else if (y > 0) {
                ans[y-1].pb(a[i]);
                if (sz(ans[y-1]) == 2) {
                    y --;
                }
            } else {
                ans[0].pb(a[i]);
            }
        } 
    }
    rep(i, n) {
        if ((a[i]&1) == 0) {
            if (y > 0) {
                y --;
            }
            ans[y].pb(a[i]);
        }
    }
    cout << "YES\n";
    rep(i, k) {
        cout << sz(ans[i]);
        repe(a, ans[i]) {
            cout << " " << a;
        } cout << "\n";
    }
    return 0;
}
