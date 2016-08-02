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
    vector <int> a(n);
    repe(&x, a) {
        cin >> x;
    }
    map <int, int> C;
    long long ans = 0;
    for (int i = 0, j = 0; j < n; ) {
        bool flag = false;
        while (j < n) {
            C[a[j]] ++;
            j ++;
            if (C[a[j-1]] == k) {
                flag = true;
                break;
            }
        }
        while (i < j) {
            C[a[i]] --;
            i ++;
            if (!flag) {
                break;
            }
            ans += n-j+1;
            if (C[a[i-1]] == k-1) {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
