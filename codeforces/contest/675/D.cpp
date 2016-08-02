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

int dp[20][100005];
vector <int> cmp;

void make() {
    rep(i, sz(cmp)) {
        dp[0][i] = i;
    }
    for (int j = 1; (1<<j) <= sz(cmp); j ++) {
        for (int i = 0; i+(1<<j)-1 < sz(cmp); i ++) {
            if (cmp[dp[j-1][i]] < cmp[dp[j-1][i+(1<<(j-1))]]) {
                dp[j][i] = dp[j-1][i];
            } else {
                dp[j][i] = dp[j-1][i+(1<<(j-1))];
            }
        }
    }
}

int get_min(int i, int j) {
    int d = 31-__builtin_clz(j-i+1);
    if (cmp[dp[d][i]] < cmp[dp[d][j-(1<<d)+1]]) {
        return dp[d][i];
    } else {
        return dp[d][j-(1<<d)+1];
    }
}

int parent[100005];

void solve(int root, int low, int high) {
    if (low > high) {
        return;
    }
    int mid = get_min(low, high);
    parent[cmp[mid]] = root;
    solve(cmp[mid], low, mid-1);
    solve(cmp[mid], mid+1, high);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> p;
    vector <pair <int, int> > a(n);
    repe(&x, a) {
        cin >> x.x;
        x.y = sz(p);
        p.pb(x.x);
    }
    sort(all(a));
    repe(e, a) {
        cmp.pb(e.y);
    }
    make();
    solve(-1, 0, n-1);
    repi(i, 1, n) {
        cout << p[parent[i]] << " ";
    }
    return 0;
}
