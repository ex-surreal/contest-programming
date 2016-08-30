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

char B[1005][1005];
int C[1005][1005];

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int m, n;
        scanf("%d%d", &m, &n);
        rep(i, m) {
            scanf("%s", B[i]);
            rep(j, n) {
                C[i+1][j+1] = 0;
                if (B[i][j] == '.') {
                    C[i+1][j+1] = C[i][j+1]+1;
                }
            }
        }
        vector <int> ans(m+n+1);
        repi(i, 1, m+1) {
            stack <int> S;
            vector <int> a(n+2);
            rep(j,  n+1) {
                while (!S.empty() && C[i][S.top()] >= C[i][j]) {
                    S.pop();
                }
                if (!S.empty()) {
                    a[j] = j-S.top()+max(a[S.top()], C[i][j]);
                }
                S.push(j);
            }
            repe(e, a) {
                ans[e] ++;
            }
        }
        repi(i, 1, m+n+1) {
            if (ans[i]) {
                printf("%d x %d\n", ans[i], 2*i);
            }
        }
    }
    return 0;
}
