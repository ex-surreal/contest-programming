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

int cnt[1<<20];
int C[20][2], cost[20][2];
vector <string> s;

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    s.resize(n);
    rep(i, n) {
        cin >> s[i];
    }
    rep(i, m) {
        int t = 0;
        rep(j, n) {
            t |= int(s[j][i] == '1') << j;
        }
        cnt[t] ++;
    }
    rep(k, n) {
        rep(i, (1<<n)) {
            int t = __builtin_popcount(i);
            cost[k][(i>>k)&1] += min(t, n-t);
            C[k][(i>>k)&1] += cnt[i];
        }
    }
    int now = 0;
    int ans = cost[0][0]*C[0][0] + cost[0][1]*C[0][1];
    mem(cnt, 0);
    cnt[0] = 1;
    repi(i, 1, 1<<n) {
        rep(k, n) {
            if (cnt[now|(1<<k)] == 0) {
                now |= 1<<k;
                swap(C[k][0], C[k][1]);
                ans = min(ans, C[k][0]*cost[k][0]+C[k][1]*cost[k][1]);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
