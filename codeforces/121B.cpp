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
    cin >> n >> k;
    string p;
    cin >> p;
    for (int i = 0, j = 0; j < k && i < n-1; j ++) {
        if (i < n-2 && !(i&1) && p[i] == '4' && p[i+1] == '4' && p[i+2] == '7') {
            if (1&(k-j)) {
                p[i+1] = '7';
            }
            break;
        }
        while (i < n-1) {
            if (p[i] == '4' && p[i+1] == '7') {
                if (i&1) {
                    p[i] = '7';
                    if (i > 0) {
                        i --;
                    }
                } else {
                    p[i+1] = '4';
                }
                break;
            }
            i ++;
        }
    }
    cout << p;
    return 0;
}
