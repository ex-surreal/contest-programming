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

long long dp[2][3];

void div(int a, set <int> &d) {
    for (int t = 2; t*t <= a; t ++) {
        while (a % t == 0) {
            a /= t;
            d.insert(t);
        }
    }
    if (a > 1) {
        d.insert(a); 
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> q(n);
    repe(&x, q) {
        cin >> x;
    }
    set <int> d;
    for (int k = -1; k <= 1; k ++) {
        div(q[0]+k, d);
        div(q[n-1]+k, d);
    }
    long long ans = LLONG_MAX/3;
    repe(s, d) {
        int now = 0, pre = 1;
        mem(dp, 0);
        rep(i, n) {
            swap(now, pre);
            if (q[i] % s == 0) {
                dp[now][0] = min(dp[pre][0], dp[pre][1] + a);
                dp[now][1] = min(dp[pre][1] + a, dp[pre][2]);
                dp[now][2] = dp[pre][2];
            } else if ((q[i]+1) % s == 0 || (q[i]-1) % s == 0) {
                dp[now][0] = min(dp[pre][0] + b, dp[pre][1] + a);
                dp[now][1] = min(dp[pre][1] + a, dp[pre][2] + b);
                dp[now][2] = dp[pre][2] + b;
            } else {
                dp[now][0] = dp[now][1] = dp[pre][1] + a;
                dp[now][2] = LLONG_MAX/3;
            }
        }
        ans = min(ans, dp[now][0]);
    }
    cout << ans;
    return 0;
}
