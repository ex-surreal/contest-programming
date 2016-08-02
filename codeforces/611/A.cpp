#include <bits/stdc++.h>

using namespace std;

int main () {
    string weeks = "";
    for (int i = 0, start = 5; i < 366; i ++) {
        weeks.push_back('0' + start);
        start ++;
        if (start == 8) {
            start = 1;
        }
    }
    int x;
    string a, b;
    cin >> x >> a >> b;
    if (b == "week") {
        int ans = 0;
        for (auto y: weeks) {
            if (x == y - '0') {
                ans ++;
            }
        }
        cout << ans;
    } else {
        if (x == 31) {
            cout << 7;
        } else if (x == 30) {
            cout << 11;
        } else {
            cout << 12;
        }
    }
    return 0;
}
