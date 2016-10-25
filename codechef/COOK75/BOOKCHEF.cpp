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

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> m >> n;
  vt(int) sp(100005), f(n), p(n), ord(n);
  rep(i, n) {
    ord[i] = i;
  }
  rep(i, m) {
    int t;
    cin >> t;
    sp[t] = 1;
  }
  vt(string) post(n);
  rep(i, n) {
    cin >> f[i] >> p[i] >> post[i];
  }
  sort(all(ord), [&](int i, int j) {
      return sp[f[i]] == sp[f[j]] ? p[i] > p[j] : sp[f[i]] > sp[f[j]];
      });
  repe(i, ord) {
    cout << post[i] << "\n";
  }
  return 0;
}
