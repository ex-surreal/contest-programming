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
    long long k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    int high = 2000000000, low = 0;
    while (low <= high) {
        int mid = (1ll*high+low)/2;
        long long need = 0;
        rep(i, n) {
            need += max(1ll*a[i]*mid-b[i], 0ll);
            if (need > 1ll*k) {
                break;
            }
        }
        if (need > 1ll*k) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << high;
    return 0;
}
