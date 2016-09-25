#include <vector>
#include <algorithm>

using namespace std;

/* int p = 5, ex = 1<<20, mod = 7340033; //, q=4404020; */
vector <int> mod_inv;

vector <int> fft(vector <int> a, int p, int ex, int mod) {
  int n = a.size(), t = 0;
  int k = 31 - __builtin_clz(n);
  vector <int> order(n);
  for(int i = 1; i < n; i ++) {
    order[i] = order[i^(1<<t)] | (1<<(k-t-1));
    if(((i+1)&i) == 0) {
      t++;
    }
  }
  vector <int> A(n);
  for(int i = 0; i < n; i ++) {
    A[i] = a[order[i]] % mod;
  }
  for(int len = 2; len <= n; len <<= 1) {
    int r = p;
    for (int i = len; i < ex; i <<= 1) {
      r = 1ll*r*r % mod;
    }
    for(int start = 0; start < n; start += len) {
      for(int i = 0, x = start, w = 1;i < (len>>1); i++, x++, w = (1ll*r*w) % mod) {
        int s = A[x];
        int t = 1ll*w*A[x+(len>>1)] % mod;
        A[x] = (s+t) % mod;
        A[x+(len>>1)] = ((s-t)%mod+mod) % mod;
      }
    }
  }
  return A;
}

vector <int> tff(vector <int> A, int p, int ex, int mod) {
  vector <int> a = fft(A, p, ex, mod);
  int n = a.size();
  for (int i = 0; i < n; i ++) {
    a[i] = 1ll*a[i]*mod_inv[n]%mod;
  }
  reverse(a.begin()+1, a.end());
  return a;
}

void cal_mod_inv(int mod) {
  mod_inv.resize(mod);
  mod_inv[1] = 1;
  for (int i = 2; i < mod; i ++) {
    mod_inv[i] = (mod - 1ll*(mod/i)*mod_inv[mod%i] % mod) % mod;
  }
}
