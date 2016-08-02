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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int i = 0, j = 0;
    int a = 0, b = 0;
    int ans = 0;
    while (i < n && j < n) {
        if (s[j] == 'a') {
            a ++;
        } else {
            b ++;
        }
        j ++;
        if (min(a, b) <= k) {
            ans = max(ans, j-i);
        } else {
            if (s[i] == 'a') {
                a --;
            } else {
                b --;
            }
            i ++;
        }
    }
    cout << ans;
    return 0;
}
