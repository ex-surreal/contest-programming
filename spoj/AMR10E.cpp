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

#include <vector>
#include <iostream>

using namespace std;

typedef int elem;
typedef vector <vector <elem> > matrix;
int mod = 1e9+7;

/**
 * @param int n
 * @return a nxn identity matrix
 * */
matrix get_identity(int n) {
    matrix I(n);
    for (int i = 0; i < n; i ++) {
        I[i].resize(n);
        fill(I[i].begin(), I[i].end(), 0);
        I[i][i] = 1;
    }
    return I;
}

/**
 * @param matrix &a
 * @param matrix &b
 * @return matrix a x b
 * Assumes the multiplication is valid i.e. a[0].size() == b.size() 
 * */
matrix cross(matrix &a, matrix &b) {
    int m = a.size(), n = b.back().size(), t = b.size();
    matrix c(m);
    for (int i = 0; i < m; i ++) {
        c[i].resize(n);
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            c[i][j] = 0;
            for (int k = 0; k < t; k ++) {
                c[i][j] = (c[i][j] + 1ll*a[i][k]*b[k][j]) % mod;
            }
        }
    }
    return c;
}

/**
 * @param matrix a
 * @param integral ex
 * @return matrix pow(a, ex)
 * Assumes a is a nxn matrx
 * */
template <class integral> matrix pwr(matrix a, integral ex) {
    int n = a.size();
    matrix r = get_identity(n);
    while (ex > 0) {
        if (ex&1) {
            r = cross(r, a);
        }
        a = cross(a, a);
        ex >>= 1;
    }
    return r;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst;
  cin >> tst;
  while (tst --) {
    int n, r, k;
    cin >> n >> r >> k;
    vector <int> s(r), a(r);
    rep(i, r) {
      cin >> s[i];
    }
    rep(i, r) {
      cin >> a[i];
    }
    repi(i, r, k) {
      s.push_back(0);
      rep(j, r) {
        s.back() = (s.back() + 1ll*a[j]*s[i-j-1]) % mod;
      }
    }
    matrix b(k+sz(s), vector <elem>(k+sz(s)));
    rep(i, r) {
      b[0][i] = a[i];
    }
    rep(i, sz(s)-1) {
      b[i+1][i] = 1;
    }
    b[sz(s)][sz(s)-k] = b[sz(s)].back() = 1;
    rep(i, k-1) {
      b[sz(s)+1+i][sz(s)+i] = 1;
    }
    auto c = pwr(b, 1ll*k*(n-1)+1);
    int ans = 0;
    rep(i, sz(s)) {
      ans = (ans+1ll*c[sz(s)][i]*s[sz(s)-i-1]) % mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
