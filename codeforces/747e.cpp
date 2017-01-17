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

vt(string) p;
vt(vt(string)) ans;

vt(string) split(string p) {
  vt(string) ret;
  rep(i, sz(p)) {
    int j = i;
    ret.push_back("");
    while (j < sz(p) && p[j] != ',') {
      ret.back().push_back(p[j ++]);
    }
    i = j;
  }
  return ret;
}

int go(int i, int d = 0) {
  int t = stoi(p[i+1]);
  if (d == sz(ans)) {
    ans.push_back({});
  }
  ans[d].push_back(p[i]);
  int ret = i+1;
  while (t --) {
    ret = go(ret+1, d+1);
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  p = split(s);
  for (int i = -1; i+1 < sz(p); i = go(i+1));
  cout << sz(ans) << "\n";
  repe(e, ans) {
    repe(c, e) {
      cout << c << " ";
    } cout << "\n";
  }
  return 0;
}
