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
    int n;
    cin >> n;
    vector <int> a(n);
    repe(&x, a) {
        cin >> x;
    }
    sort(all(a));
    int ans = 0;
    priority_queue <int> Q;
    rep(i, n) {
        int j = i;
        while (j < n && a[i] == a[j]) {
            j ++;
        }
        Q.push(-(j-i));
        i = j - 1;
    }
    int cur = 0;
    while (!Q.empty()) {
        int x = -Q.top(); Q.pop();
        ans += (x-cur)*Q.size();
        cur = x;
    }
    cout << ans;
    return 0;
}
