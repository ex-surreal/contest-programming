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

int num(char x) {
    if ('0' <= x && x <= '9') {
        return x - '0';
    } else if ('A' <= x && x <= 'Z') {
        return 10+x-'A';
    } else if ('a' <= x && x <= 'z') {
        return 36+x-'a';
    } else if (x == '-') {
        return 62;
    } else {
        return 63;
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    int e = 0, mod = 1e9+7;
    repe(c, p) {
        e += 6-__builtin_popcount(num(c));
    }
    int ans = 1;
    rep(i, e) {
        ans = 3ll*ans%mod;
    }
    cout << ans;
    return 0;
}
