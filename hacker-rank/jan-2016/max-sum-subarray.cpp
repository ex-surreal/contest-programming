#include <iostream>
#include <vector>

using namespace std;

int max_array(vector <int> &a) {
    long long ret = 0, dp = 0;
    for (auto x: a) {
        dp = max(1ll*x, x+dp);
        ret = max(ret, dp);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> t;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (x == 0) {
            ans = max(ans, max_array(t));
            t.clear();
        } else {
            t.push_back(x);
        }
    }
    ans = max(ans, max_array(t));
    cout << ans << "\n";
    return 0;
}
