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
    int n, m;
    cin >> n >> m;
    int now = 1, k = 0;
    while (n + m - k > 0) {
        now ++;
        if (now % 6 == 0) {
            k ++;
        } else if (now % 2 == 0 && n > 0) {
            n --;
        } else if (now % 3 == 0 && m > 0) {
            m --;
        }
    }
    cout << now;
    return 0;
}
