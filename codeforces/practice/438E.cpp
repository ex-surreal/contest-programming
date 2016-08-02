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

#include <vector>
#include <algorithm>

int p = 646, ex = 1<<20, mod = 998244353;

template <class type> std::vector <type> fft(std::vector <type> a, type p, type ex, type mod) {
    int n = a.size(), t = 0;
    int k = 31 - __builtin_clz(n);
    std::vector <int> order(n);
    for(int i = 1; i < n; i ++) {
        order[i] = order[i^(1<<t)] | (1<<(k-t-1));
        if(((i+1)&i) == 0) {
            t++;
        }
    }
    std::vector <type> A(n);
    for(int i = 0; i < n; i ++) {
        A[i] = a[order[i]] % mod;
    }
    for(int len = 2; len <= n; len <<= 1) {
        type r = p;
        for (int i = len; i < ex; i <<= 1) {
            r = 1ll*r*r % mod;
        }
        for(int start = 0; start < n; start += len) {
            for(int i = 0, x = start, w = 1;i < (len>>1); i++, x++, w = (1ll*r*w) % mod) {
                type s = A[x];
                type t = 1ll*w*A[x+(len>>1)] % mod;
                A[x] = (s+t) % mod;
                A[x+(len>>1)] = ((s-t)%mod+mod) % mod;
            }
        }
    }
    return A;
}

int pwr(int b, int e) {
    int ret = 1;
    while (e > 0) {
        if (e&1) {
            ret = 1ll*ret*b % mod;
        }
        b = 1ll*b*b %mod;
        e >>= 1;
    }
    return ret;
}

template <class type> std::vector <type> tff(std::vector <type> A, type p, type ex, type mod) {
    std::vector <type> a = fft(A, p, ex, mod);
    int n = a.size();
    int ninv = pwr(n, mod-2);
    for (int i = 0; i < n; i ++) {
        a[i] = 1ll*a[i]*ninv%mod;
    }
    reverse(a.begin()+1, a.end());
    return a;
}

vector <int> operator * (vector <int> a, vector <int> b) {
    a.resize(2*sz(a));
    b.resize(2*sz(b));
    vector <int> A = fft(a, p, ex, mod);
    vector <int> B = fft(b, p, ex, mod);
    rep(i, sz(A)) {
        A[i] = 1ll*A[i]*B[i]%mod;
    }
    a = tff(A, p, ex, mod);
    a.resize(sz(a)>>1);
    return a;
}

vector <int> inv(vector <int> a) {
    vector <int> ia(1, 1);
    for (int s = 2; s <= sz(a); s <<= 1) {
        ia.resize(s);
        auto g = fft(ia, p, ex, mod);
        auto f = fft(vector <int>(a.begin(), a.begin()+s), p, ex, mod);
        rep(i, s) {
            g[i] = 1ll*g[i]*(2+mod-1ll*g[i]*f[i]%mod)%mod;
        }
        ia = tff(g, p, ex, mod);
    }
    return ia;
}

vector <int> sqrt(vector <int> a) {
    vector <int> sa(1, 1);
    int inv2 = pwr(2, mod-2);
    for (int s = 2; s <= sz(a); s <<= 1) {
        auto f = sa*sa;
        f.resize(s);
        sa.resize(s);
        auto g = fft(inv(sa), p, ex, mod);
        rep(i, s) {
            f[i] = (f[i] + a[i])*1ll*inv2%mod;
        }
        f = fft(f, p, ex, mod);
        rep(i, s) {
            sa[i] = 1ll*f[i]*g[i]%mod;
        }
        tff(sa, p, ex, mod);
    }
    return sa;
}

void check() {
    vector <int> a(2, 1);
    /* a[1] = mod-1; */
    a.resize(1<<3);
    auto k = sqrt(a);
    auto ia = inv(a);
    repe(e, ia) {
        cout << e << " " ;
    } cout << endl;
    vector <int> u({1, 1, 3, 5, 35});
    vector <int> v({1, 2, 8, 16, 128});
    rep(i, sz(u)) {
        int d = 1ll*u[i]*pwr(v[i], mod-2)%mod;
        cout << k[i] << " " << d << endl;
    }
    /* srand(clock()); */
    /* vector <int> c(1<<15); */
    /* rep(i, sz(c)) { */
    /*     c[i] = rand()%mod; */
    /* } */
    /* auto ic = inv(inv(c)); */
    /* auto sc = sqrt(c); */
    /* rep(i, sz(c)) { */
    /*     assert(c[i] == ic[i]); */
    /* } */
    /* auto s = sc*sc; */
    /* rep(i, sz(s)) { */
    /*     assert(s[i] == c[i]); */
    /* } */
}

int main () {
    std::ios_base::sync_with_stdio(false);
    check(); return 0;
    int n, m;
    cin >> n >> m;
    int k = 1;
    while (k < m+1) {
        k <<= 1;
    }
    vector <int> c(k);
    rep(i, n ) {
        int x;
        cin >> x;
        if (x <= m) {
            c[x] = mod-4;
        }
    }
    c[0] = 1;
    c = sqrt(c);
    c[0] = (c[0]+1)%mod;
    c = inv(c);
    rep(i, sz(c)) {
        c[i] = 2*c[i]%mod;
    }
    repi(i, 1, m+1) {
        cout << c[i] << "\n";
    }
    return 0;
}
