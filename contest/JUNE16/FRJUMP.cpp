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

int mod = 1e9+7;

int pwr(int b, int e) {
    int ret = 1;
    while (e > 0) {
        if (e&1) {
            ret = 1ll*ret*b%mod;
        }
        b = 1ll*b*b%mod;
        e >>= 1;
    }
    return ret;
}

int ten(int n) {
    int ret = 1;
    n /= 10;
    while (n > 0) {
        ret *= 10;
        n /= 10;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> F(n), I(n), R(n+1), W(n);
    vector <double> D(n+1);
    rep(i, n) {
        cin >> F[i];
        W[i] = ten(F[i]);
        I[i] = pwr(F[i], mod-2);
    }
    vector <vector <int> > div(n);
    repi(i, 1, n+1) {
        R[i] = 1;
        D[i] = 1.0;
        for (int j = i; j < n; j += i) {
            div[j].pb(i);
            R[i] = 1ll*R[i]*F[j]%mod;
            D[i] = D[i]*F[j]/W[j];
            if (D[i] >= 10) {
                D[i] /= 10;
            }
        }
    }
    int q;
    cin >> q;
    rep(i, q) {
        int o, id;
        cin >> o >> id;
        if (o == 2) {
            int a = 1ll*R[id]*F[0]%mod;
            int d = int(D[id]*F[0]/W[0]*10000+1e-9);
            while (d >= 10) {
                d /= 10;
            }
            cout << d << " " << a << "\n";
        } else {
            id --;
            int v;
            cin >> v;
            int t = ten(v);
            repe(d, div[id]) {
                R[d] = 1ll*R[d]*I[id]%mod*v%mod;
                D[d] = D[d]/F[id]*W[id];
                if (D[d] < 1) {
                    D[d] *= 10;
                }
                D[d] = D[d]*v/t;
                if (!(D[d]/10 < 1)) {
                    D[d] /= 10;
                }
            }
            F[id] = v;
            I[id] = pwr(v, mod-2);
            W[id] = t;
        }
    }
    return 0;
}
