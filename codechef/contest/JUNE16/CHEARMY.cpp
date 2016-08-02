#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

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

long long five[25] = {1};
long long ten[25] = {1};

long long fun(int l, long long k) {
    if (l == 0) {
        return 0;
    }
    for (int i = 4; i >= 0; i --) {
        if (i*five[l-1] < k) {
            return i*2*ten[l-1] + fun(l-1, k - i*five[l-1]);
        }
    }
    return fun(l-1, k);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    repi(i, 1, 25) {
        five[i] = five[i-1]*5;
        ten[i] = ten[i-1]*10;
    }
    int tst;
    cin >> tst;
    while (tst --) {
        long long k;
        cin >> k;
        cout << fun(19, k) << "\n";
    }
    return 0;
}
