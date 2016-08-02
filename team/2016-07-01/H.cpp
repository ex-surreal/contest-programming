#include <iostream>
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

vector <long long> seg;

long long read(int node, int u, int v, int x, int y) {
    if (y < u || x > v) {
        return 1ll<<50;
    }
    if (x <= u && v <= y) {
        return seg[node];
    }
    long long p = read(node*2+1, u, (u+v)/2, x, y);
    long long q = read(node*2+2, (u+v)/2+1, v, x, y);
    return min(p, q);
}

void update(int node, int u, int v, int i, int val) {
    if (i < u || i > v) {
        return;
    }
    if (u == v) {
        seg[node] = val;
        return;
    }
    update(node*2+1, u, (u+v)/2, i, val);
    update(node*2+2, (u+v)/2+1, v, i, val);
    seg[node] = min(seg[2*node+1], seg[2*node+2]);
}

int main () {
    int tst, cas = 0;
    scanf("%d", &tst);
    while (tst --) {
        int n;
        scanf("%d", &n);
        vector <int> h(n), t(n);
        rep(i, n) {
            scanf("%d%d", &t[i], &h[i]);
        }
        seg = vector <long long> (4*(n+1)+5, 1ll<<50);
        vector <int> cnt(*max_element(all(t))+1), rgt(n);
        int l = n-1, r = n-1;
        cnt[t[l]] ++;
        rgt[l --] = r;
        while (l >= 0) {
            cnt[t[l]] ++;
            while (cnt[t[l]] > 1) {
                cnt[t[r]] --;
                r --;
            }
            rgt[l--] = r;
        }
        stack <int> S;
        long long dp;
        update(0, 0, n, n, 0);
        for (int i = n-1; i >= 0; i --) {
            while (!S.empty() && h[S.top()] < h[i]) {
                S.pop();
            }
            int r;
            if (!S.empty()) {
                r = S.top();
            } else {
                r = n;
            }
            S.push(i);
            dp = read(0, 0, n, i+1, min(r, rgt[i]+1)) + h[i];
            if (i < r && r <= rgt[i]) {
                dp = min(dp, read(0, 0, n, r, r));
            }
            cout << i << " " << r << " " << dp << endl;
            update(0, 0, n, i, dp);
        }
        printf("Case %d: %lld\n", ++cas, dp);
    }
    return 0;
}
