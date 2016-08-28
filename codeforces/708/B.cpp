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

int get(int a) {
    for (int i = 1; 1ll*i*(i-1)/2 <= a; i ++) {
        if (1ll*i*(i-1)/2 == a) {
            return i;
        }
    }
    return -1;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00+a01+a10+a11 == 0) {
        cout << "0";
        return 0;
    }
    if (a00+a11 == 0) {
        if (a10+a01 == 1) {
            cout << (a10 ? "10" : "01");
        } else {
            cout << "Impossible";
        }
        return 0;
    }
    if (a01+a10 == 0) {
        if ((a11 > 0 && a00 > 0) || get(a00+a11) == -1) {
            cout << "Impossible";
        } else {
            cout << string(get(a00+a11), a00 ? '0' : '1');
        }
        return 0;
    }
    int n0 = get(a00);
    int n1 = get(a11);
    if (n0 == -1 || n1 == -1) {
        cout << "Impossible";
        return 0;
    }
    if (n0+n1 > 1000000 || 1ll*n0*n1 != a01+a10) {
        cout << "Impossible";
        return 0;
    }
    string ans = "";
    while (a01 >= n1) {
        ans.push_back('0');
        a01 -= n1;
        n0 --;
    }
    ans = ans + string(n1-a01, '1');
    n1 = a01;
    if (a01 > 0) {
        ans.push_back('0');
        a01 = 0;
        n0 --;
    }
    ans = ans + string(n1, '1');
    ans = ans + string(n0, '0');
    cout << ans;
    return 0;
}
