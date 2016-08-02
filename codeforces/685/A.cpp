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

int n, m;
int x, y;

int back(int i, int bit, long long num) {
    if (i == x) {
        if (num > n) {
            return 0;
        }
        num = 0;
    }
    if (i == x+y) {
        return num <= m;
    }
    int ret = 0;
    rep(j, 7) {
        if (!((bit>>j)&1)) {
            ret += back(i+1, bit|(1<<j), num*7 + j);
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    n --, m --;
    int p = n, q = m;
    while (p > 0) {
        x ++;
        p /= 7;
    }
    while (q > 0) {
        y ++;
        q /= 7;
    }
    if (x+y > 7) {
        cout << "0";
        return 0;
    }
    x = max(x, 1);
    y = max(y, 1);
    cout << back(0, 0, 0);
    return 0;
}
