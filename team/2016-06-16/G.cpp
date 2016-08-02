#include <iostream>
#include <vector>
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

typedef unsigned long long ull;

map <ull, ull> dp;

ull f(ull x) {
    if (x == 1) {
        return 1;
    }
    if (dp.count(x)) {
        return dp[x];
    }
    if (x&1ull) {
        return dp[x] = f(x/2)*f(x/2+1) + 2;
    }
    ull t = f(x/2);
    return dp[x] = t*t + 1;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    /* repi(i, 1, 1000) { */
    /*     cout << i << ": " << f(i) << endl; */
    /* } */
    int tst;
    cin >> tst;
    repi(cas, 1, tst+1) {
        long long x;
        cin >> x;
        cout << "Case " << cas << ": " << f(x) << "\n";
    }
    return 0;
}
