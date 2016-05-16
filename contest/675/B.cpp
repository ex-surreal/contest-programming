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

#define in(x) (1 <= (x) && (x) <= n)

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long ans = 0;
    repi(x1, 1, n+1) {
        int x2 = x1+b-c;
        int x4 = x1+a-d;
        int x5 = x1+a+b-d-c;
        if (in(x2) && in(x4) && in(x5)) {
            ans += n;
        }
    }
    cout << ans;
    return 0;
}
