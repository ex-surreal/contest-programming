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

int mod = 1e9+7;

int pwr(int b, long long ex) {
    int ret = 1;
    while (ex > 0) {
        if (ex&1) {
            ret = 1ll*ret*b % mod;
        }
        b = 1ll*b*b % mod;
        ex >>= 1;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    vector <long long> a(k);
    bool odd = true;
    repe(&x, a) {
        cin >> x;
        odd = odd && x%2 != 0;
    }
    sort(all(a));
    if (a[0] == 1 && a.back() == 1) {
        cout << "0/1";
        return 0;
    }
    int tn = 2;
    repe(x, a) {
        tn = pwr(tn, x) % mod;
    }
    int v = 1ll*tn*pwr(2, mod-2) % mod, u;
    if (odd) {
        u = 1ll*(tn-2+mod)%mod*pwr(6, mod-2) % mod;
    } else {
        u = 1ll*(tn+2)%mod*pwr(6, mod-2) % mod;
    }
    cout << u << "/" << v;
    return 0;
}
