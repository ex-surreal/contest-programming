#include <vector>
#include <algorithm>

int p = 5, ex = 1<<20, mod = 7340033; //, q=4404020;

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

int mod_inv[7340033];

template <class type> std::vector <type> tff(std::vector <type> A, type p, type ex, type mod) {
    std::vector <type> a = fft(A, p, ex, mod);
    int n = a.size();
    for (int i = 0; i < n; i ++) {
        a[i] = 1ll*a[i]*mod_inv[n]%mod;
    }
    reverse(a.begin()+1, a.end());
    return a;
}

void cal_mod_inv() {
    mod_inv[1] = 1;
    for (int i = 2; i < mod; i ++) {
        mod_inv[i] = (mod - 1ll*(mod/i)*mod_inv[mod%i] % mod) % mod;
    }
}
