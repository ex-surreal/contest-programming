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
    int tst, cas = 0;
    scanf("%d", &tst);
    while (tst --) {
        printf("Case #%d: ", ++cas);
        int n, l1, r1, a, b, c1, c2, m;
        scanf("%d%d%d%d%d%d%d%d", &n, &l1, &r1, &a, &b, &c1, &c2, &m);
        vector <pair <int, int> > p(1, mp(l1, r1));
        repi(i, 1, n) {
            int x = (1ll*a*p[i-1].x + 1ll*b*p[i-1].y + c1) % m;
            int y = (1ll*a*p[i-1].y + 1ll*b*p[i-1].x + c2) % m;
            p.push_back(mp(x, y));
        }
        rep(i, sz(p)) {
            if (p[i].x > p[i].y) {
                swap(p[i].x, p[i].y);
            }
            l1 = min(l1, p[i].x);
            r1 = max(r1, p[i].y);
        }
        p.push_back(mp(r1+1, r1+1));
        sort(all(p));
        int lst = l1-1, cnt = 0, ans = 0;
        rep(i, sz(p)-1) {
            if (p[i].x <= lst) {
                cnt += max(p[i].y - lst, 0);
            } else {
                cnt += p[i].y-p[i].x+1;
            }
            int j = i+1, l = max(lst, p[i].x-1), t = 0;
            while (j < sz(p)-1 && p[j].x <= p[i].y) {
                t += max(0, p[j].x-l-1);
                l = max(l, p[j].y);
                if (p[j].y >= p[i].y) {
                    break;
                }
                j ++;
            }
            t += max(0, p[i].y-l);
            ans = max(ans, t);
            lst = max(lst, p[i].y);
            i = j-1;
        }
        printf("%d\n", cnt-ans);
    }
    return 0;
}
