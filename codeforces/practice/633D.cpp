#include <bits/stdc++.h>

using namespace std;

const int limit = 1e9;

int main () {
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> d;
    for (auto &x: a) {
        cin >> x;
        d[x] ++;
    }
    int ans = count(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i != j && (a[i] != 0 || a[j] != 0)) {
                int c = 2;
                int x = a[i], y = a[j];
                d[x] --, d[y] --;
                while (abs(y) <= limit) {
                    int t = y;
                    y = x+y, x = t;
                    if (d.count(y) == 0 || d[y] == 0) {
                        break;
                    }
                    d[y] --;
                    c ++;
                }
                ans = max(ans, c);
                x = a[i], y = a[j];
                d[x] ++, d[y] ++;
                while (c > 2) {
                    int t = y;
                    y = x+y, x = t;
                    c --;
                    d[y] ++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
