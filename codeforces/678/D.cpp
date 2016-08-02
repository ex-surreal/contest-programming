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

int mod = 1e9+7;

long long pwr(long long b, long long e) {
    long long ret = 1;
    while (e > 0) {
        if (e&1) {
            ret = ret*b % mod;
        }
        b = b*b %mod;
        e >>= 1;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    long long A, B, n, x;
    cin >> A >> B >> n >> x;
    long long s = (A != 1 ? B*(pwr(A, n)+mod-1)%mod*pwr(A-1, mod-2)%mod : n%mod*B%mod);
    long long ans = pwr(A, n)*x%mod+s;
    cout << ans%mod;
    return 0;
}
