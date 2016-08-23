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
    vector <long long> f(32, 1), ax(32, 1), xx(32, 1);
    repi(i, 1, 30) {
        f[i+1] = f[i]*2+1;
        ax[i+1] = ax[i]*3+2;
        xx[i+1] = xx[i]+ax[i]+1;
    }
    int n;
    while (~scanf("%d", &n)) {
        int to[3] = {-1, -1, -1};
        rep(i, 6) {
            char p[3];
            scanf("%s", p);
            if (to[p[0]-'A'] == -1) {
                to[p[0]-'A'] = p[1]-'A';
            }
        }
        if ((to[0] == 1 && to[1] == 0) || (to[0] == 2 && to[2] == 0)) {
            printf("%lld\n", ax[n]);
        } else if (to[1] == 2 && to[2] == 1) {
            printf("%lld\n", xx[n]);
        } else {
            printf("%lld\n", f[n]);
        }
    }
    return 0;
}
