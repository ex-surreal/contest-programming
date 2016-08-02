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

int prefix[32*50005];
int child[32*50005][2];
int nodeNum = 0;

void insert(int x) {
    for (int b = 31, i = 0; b >= 0; b --) {
        int &c = child[i][(x>>b)&1];
        if (c == -1) {
            c = ++nodeNum;
        }
        prefix[c] ++;
        i = c;
    }
}

int query(int x) {
    int ret = 0;
    for (int b = 31, i = 0; b >= 0; b --) {
        int &c = child[i][(x>>b)&1];
        if (c == -1) {
            i = child[i][((x>>b)&1)^1];
            ret |= (((x>>b)&1)^1) << b;
        } else {
            i = c;
            ret |= ((x>>b)&1) << b;
        }
    }
    return ret;
}

void init(int n) {
    nodeNum = 0;
    rep(i, 32*n+5) {
        prefix[i] = 0;
        child[i][0] = child[i][1] = -1;
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    repi(cas, 1, tst+1) {
        int n;
        cin >> n;
        vector <int> a(n);
        rep(i, n) {
            cin >> a[i];
        }
        init(n);
        insert(0);
        int x = 0, mn = INT_MAX, mx = INT_MIN;
        rep(i, n) {
            x ^= a[i];
            mx = max(mx, x^query(~x));
            mn = min(mn, x^query(x));
            insert(x);
        }
        cout << "Case " << cas << ": " << mx << " " << mn << "\n";
    }
    return 0;
}
