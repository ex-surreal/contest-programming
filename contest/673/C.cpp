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
    vector <int> c(n+1);
    repi(i, 1, n+1) {
        cin >> c[i];
    }
    vector <int> ans(n+1, 0);
    repi(i, 1, n+1) {
        ans[c[i]] ++;
        vector <int> cnt(n+1, 0);
        cnt[c[i]] ++;
        int id = i;
        repi(j, i+1, n+1) {
            cnt[c[j]] ++;
            if (cnt[c[j]] > cnt[c[id]]) {
                id = j;
            } else if (cnt[c[j]] == cnt[c[id]] && c[j] < c[id]) {
                id = j;
            }
            ans[c[id]] ++;
        }
    }
    repi(i, 1, n+1) {
        cout << ans[i] << " ";
    }
    return 0;
}
