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

int main () {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    long long sum = accumulate(all(a), 0ll);
    if (sum%2 == 0) {
        cout << sum;
        return 0;
    }
    int mn = INT_MAX;
    rep(i, n) {
        if (a[i] % 2 == 1) {
            mn = min(a[i], mn);
        }
    }
    cout << sum - mn;
    return 0;
}
