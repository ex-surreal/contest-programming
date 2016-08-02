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
    int n, l, d;
    cin >> n >> d >> l;
    int o = n/2+n%2;
    repi(k, n/2, n/2*l+1) {
        if (o <= d+k && d+k <= o*l) {
            vector <int> ans(n, 1);
            int t = k - n/2, i = 1;
            while (t > 0) {
                int h = min(l-1, t);
                ans[i] += h;
                t -= h;
                i += 2;
            }
            t = d+k - o, i = 0;
            while (t > 0) {
                int h = min(l-1, t);
                ans[i] += h;
                t -= h;
                i += 2;
            }
            repe(a, ans) {
                cout << a << " ";
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}
