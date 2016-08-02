#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long ans = 0;
    int last = INT_MAX;
    for (auto x: a) {
        if (x >= last) {
            last --;
        } else {
            last = x;
        }
        if (last < 0) {
            break;
        }
        ans += last;
    }
    cout << ans;
    return 0;
}
