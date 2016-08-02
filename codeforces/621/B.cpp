#include <bits/stdc++.h>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for(int i = 0; i < int(n); i ++)
#define repi(i, a, n) for(int i = int(a); i < int(n); i ++)

int pos[2005], neg[2005];

int main () {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        neg[x+y] ++;
        pos[1000+y-x] ++;
    }
    long long ans = 0;
    for (auto x: pos) {
        ans += 1ll*x*(x-1)/2;
    }
    for (auto x: neg) {
        ans += 1ll*x*(x-1)/2;
    }
    cout << ans;
    return 0;
}
