#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> t(n);
    for (auto &a: t) {
        cin >> a;
    }
    int ans = t[0];
    sort(t.begin(), t.end());
    for (auto i = 1u; i < t.size(); i ++) {
        if (t[i] > ans) {
            ans = t[i];
        } else {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}
