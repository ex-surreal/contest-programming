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

#define make(m, x, b) ((b) ? ((m)|(1 << (x))): ((m)&~(1 << (x))))

int D[(1<<20)+5];
int Q[(1<<20)+5];
int n;

int solve(int start) {
    mem(D, -1);
    int fr = 0, bk = 0;
    D[start] = 0;
    Q[bk++] = start;
    while (fr < bk) {
        int mask = Q[fr++];
        if (mask == 0) {
            break;
        }
        repi(i, 1, 4) {
            rep(j, i) {
                int m;
                int top[4] = {n, n, n, n};
                for (int i = n-1; i >= 0; i --) {
                    top[3&(mask>>(i<<1))] = i;
                }
                if (top[i] < top[j]) {
                    m = make(mask, top[i]<<1, j&1);
                    m = make(m, (top[i]<<1)|1, j>>1);
                } else if (top[i] > top[j]) {
                    m = make(mask, top[j]<<1, i&1);
                    m = make(m, (top[j]<<1)|1, i>>1);
                }
                if (D[m] == -1) {
                    D[m] = D[mask]+1;
                    Q[bk++] = m;
                }
            }
        }
    }
    return D[0];
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    int start = 0;
    rep(i, n) {
        int e;
        cin >> e;
        e --;
        start = make(start, i<<1, e&1);
        start = make(start, (i<<1)|1, e>>1);
    }
    cout << solve(start);
    return 0;
}
