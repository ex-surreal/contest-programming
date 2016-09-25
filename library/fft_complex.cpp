#include <complex>
#include <vector>
using namespace std;
// tested OK
typedef complex<double> type;
const double pi = acos(-1.0);

vector <type> fft(vector <type> a) {
  int n = a.size(), t = 0;
  int k = 31 - __builtin_clz(n);
  vector < int > order(n);
  for (int i = 1; i < n; i++) {
    order[i] = order[i ^ (1 << t)] | (1 << (k - t - 1));
    if (((i + 1) & i) == 0) {
      t++;
    }
  }
  vector <type> roots(n), A(n);
  for (int i = 0; i < n; i ++) {
    double theta = 2*pi*i/n;
    roots[i] = type(cos(theta), sin(theta));
  }
  for (int i = 0; i < n; i ++) {
    A[i] = a[order[i]];
  }
  for (int len = 2, r = n>>1; len <= n; len <<= 1, r >>= 1) {
    for (int start = 0; start < n; start += len) {
      for (int i = 0, x = start; i < (len>>1); i ++, x ++) {
        type s = A[x];
        type t = roots[i*r] * A[x + (len>>1)];
        A[x] = s + t;
        A[x + (len>>1)] = s - t;
      }
    }
  }
  return A;
}

vector <type> tff(vector <type> A) {
  vector <type> a = fft(A);
  int n = a.size();
  for (int i = 0; i < n; i ++) {
    a[i] /= n;
  }
  reverse(a.begin()+1, a.end());
  return a;
}
