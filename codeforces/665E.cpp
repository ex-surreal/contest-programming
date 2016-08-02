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

int prefix[32*(1<<20)];
int child[32*(1<<20)][2];
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

int query(int r, int k) {
    int ret = 0, i = 0;
    for (int b = 31; b >= 0 && i >= 0; b --) {
        if ((r>>b)&(k>>b)&1) {
            i = child[i][0];
        } else if ((r>>b)&1) {
            if (child[i][0] != -1) {
                ret += prefix[child[i][0]];
            }
            i = child[i][1];
        } else if ((k>>b)&1) {
            i = child[i][1];
        } else {
            if (child[i][1] != -1) {
                ret += prefix[child[i][1]];
            }
            i = child[i][0];
        }
    }
    return ret;
}


int main () {
    std::ios_base::sync_with_stdio(false);
    mem(child, -1);
    int n, k, x = 0;
    cin >> n >> k;
    insert(0);
    long long ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        x ^= a;
        ans += query(x, k-1);
        insert(x);
    }
    cout << ans;
    return 0;
}
