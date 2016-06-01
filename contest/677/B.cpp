#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

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
    int n, h, k;
    cin >> n >> h >> k;
    vector <int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int now = 0;
    long long ans = 0;
    repe(x, a) {
        if (now+x > h) {
            ans ++;
            now = 0;
        }
        now += x;
        ans += now/k;
        now %= k;
    }
    if (now > 0) {
         ans ++;
    }
    cout << ans;
    return 0;
}
