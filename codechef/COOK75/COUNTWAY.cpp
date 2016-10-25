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
#define mt make_tuple
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))
#define vt(x) vector < x >
#define px(x) pair < x, x >
#define pxy(x, y) pair < x, y >

typedef long long ll;

int p = 7, ex = 1<<20, mod = 13313; //7340033; //, q=4404020;
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
      r = r*r % mod;
    }
    for(int start = 0; start < n; start += len) {
      for(int i = 0, x = start, w = 1;i < (len>>1); i++, x++, w = r*w % mod) {
        int s = A[x];
        int t = w*A[x+(len>>1)] % mod;
        A[x] = s+t;
        if (A[x] >= mod) {
          A[x] -= mod;
        }
        A[x+(len>>1)] = s-t;
        if (A[x+(len>>1)] < 0) {
          A[x+(len>>1)] += mod;
        }
      }
    }
  }
  return A;
}

vector <int> tff(vector <int> A, int p, int ex, int mod) {
  vector <int> a = fft(A, p, ex, mod);
  int n = a.size();
  for (int i = 0; i < n; i ++) {
    a[i] = a[i]*mod_inv[n]%mod;
  }
  return a;
}

void cal_mod_inv(int mod) {
  mod_inv.resize(mod);
  mod_inv[1] = 1;
  for (int i = 2; i < mod; i ++) {
    mod_inv[i] = (mod - (mod/i)*mod_inv[mod%i] % mod) % mod;
  }
}

vector <int>  multiply (vector<int> a, vector<int> b) {
	int n = 1;
	while (n < max(sz(a), sz(b))) {
    n <<= 1;
  }
	n <<= 1;
	a.resize (n),  b.resize (n);
  auto A = fft(a, p, ex, mod);
  auto B = fft(b, p, ex, mod);
  rep(i, n) {
    A[i] = A[i]*B[i] % mod;
  }
  return tff(A, p, ex, mod);
}

int k;

vector <int> pwr(vector <int> a, int ex) {
  vt(int) res = a;
  ex --;
  while (ex > 0) {
    a = multiply(a, a);
    if (ex&1) {
      res = multiply(res, a);
      res.resize(k);
    }
    a.resize(k);
    ex >>= 1;
  }
  return res;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  cal_mod_inv(mod);
  int n, o;
  {
    vt(int) a = {0, 1, 1, 0};
    k = 4;
    a = multiply(a, a);
    repe(e, a) {
      cout << e << " ";
    } cout << endl;
    return 0;
  }
  cin >> o >> n;
  for (k = 1; k < o; k *= 2);
  vt(int) cnt(200005);
  rep(i, n) {
    int c;
    cin >> c;
    cnt[c] ++;
  }
  vt(int) a;
  repe(c, cnt) {
    if (c) {
      a.push_back(min(c, k));
    }
  }
  sort(all(a));
  vt(int) ans(k);
  rep(i, sz(a)) {
    int j = i;
    while (j < sz(a) && a[i] == a[j]) {
      j ++;
    }
    auto t = vt(int)(a[i]+1, 1);
    t.resize(k);
    ans = multiply(ans, pwr(t, j-i));
    ans.resize(k);
    repe(e, ans) {
      cout << e << " ";
    } cout << endl;
  }
  cout << ans[o] << "\n";
  return 0;
}
