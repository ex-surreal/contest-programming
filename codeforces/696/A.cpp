#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>

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
    int q;
    cin >> q;
    map <long long, long long> cnt;
    rep(i, q) {
        int t;
        long long u, v, w;
        cin >> t >> u >> v;
        if (t == 1) {
            cin >> w;
            set <long long> st;
            for (long long p = u; p != 1; p /= 2) {
                st.insert(p);
                cnt[p] += w;
            }
            long long l = v;
            for (long long p = v; p != 1 && !st.count(p); p /= 2) {
                cnt[p] += w;
                l = p/2;
            }
            while (l > 1) {
                cnt[l] -= w;
                l /= 2;
            }
        } else {
            long long ans = 0;
            set <long long> st;
            for (long long p = u; p != 1; p /= 2) {
                st.insert(p);
                ans += cnt[p];
            }
            long long l = v;
            for (long long p = v; p != 1 && !st.count(p); p /= 2) {
                ans += cnt[p];
                l = p/2;
            }
            while (l > 1) {
                ans -= cnt[l];
                l /= 2;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
