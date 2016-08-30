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

char s[150006], t[150006];

int main () {
    int n, p;
    while (~scanf("%d%d", &n, &p) && n) {
        scanf("%s%s", s, t);
        vector <int> cnt(n+1, 0);
        rep(i, n) {
            cnt[i+1] = s[i] != t[i];
            cnt[i+1] += cnt[i];
        }
        rep(i, n) { 
            cnt[i+1] = 100*cnt[i+1] - p*(i+1);
        }
        int ans = 0;
        vector <int> S(1, 0), V(1, cnt[0]);
        repi(i, 1, n+1) {
            auto it = lower_bound(all(V), cnt[i]);
            if (it != V.end()) {
                ans = max(ans, i-S[it-V.begin()]);
            }
            if (V.back() < cnt[i]) {
                S.push_back(i);
                V.push_back(cnt[i]);
            }
        }
        if (ans == 0) {
            printf("No solution.\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
