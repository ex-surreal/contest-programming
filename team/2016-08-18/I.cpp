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

int C[1000006];

int main () {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        rep(i, n) {
            scanf("%d", C+i);
        }
        sort(C, C+n);
        rep(i, n) {
            int j = i;
            while (j < n && C[j] == C[i]) {
                j ++;
            }
            if ((j-i)%k != 0) {
                printf("%d\n", C[i]);
                break;
            }
            i = j-1;
        }
    }
    return 0;
}
