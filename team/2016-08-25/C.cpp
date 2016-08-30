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
    int a[16], cas = 0;
    while (~scanf("%d", a) && *a) {
        repi(i, 1, 16) {
            scanf("%d", a+i);
        }
        vector <vector <int> > v4(10245);
        vector <int> c8(1<<16);
        rep(i, 16) {
            rep(j, 16) {
                if (i == j) {
                    continue;
                }
                rep(k, 16) {
                    if (k == j || k == i) {
                        continue;
                    }
                    rep(l, 16) {
                        if (l == k || l == j || l == i) {
                            continue;
                        }
                        int now = 4*a[i]+3*a[j]+2*a[k]+a[l];
                        int bit = (1<<i)|(1<<j)|(1<<k)|(1<<l);
                        repe(e, v4[now]) {
                            if (e&bit) {
                                continue;
                            }
                            c8[e|bit] ++;
                        }
                        v4[now].push_back(bit);
                    }
                }
            }
        }
        long long ans = 0;
        rep(i, 1<<16) {
            ans += c8[i]*c8[0xffff^i];
        }
        printf("Case %d: %lld\n", ++cas, ans/2);
    }
    return 0;
}
