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

int zero(long long x) {
    int ret = 0;
    while (x > 0) {
        ret += x/5;
        x /= 5;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    long long n;
    while (cin >> n && n != -1) {
        long long ans = n;
        int pre = 1, k = 1, f = 0;
        n = n/5*5;
        while (n > 0) {
            ans = ans - pre*(n/5 + !f)/2*k;
            pre *= -1;
            n /= 5;
            k *= 5;
            f ^= 1;
        }
        cout << ans+1 << "\n";
    }
    return 0;
}
