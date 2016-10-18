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

#define in(x) ((x) >= 'a' && (x) <= 'z')

typedef long long ll;

ll extract(string p) {
  ll ret = 0, f = 0;
  if (sz(p) >= 4 && p[sz(p) - 3] == '.') {
    f += (p.back()-'0');
    p.pop_back();
    f += (p.back()-'0') * 10;
    p.pop_back();
    p.pop_back();
  }
  repe(e, p) {
    if (e != '.') {
      ret = ret*10 + (e-'0');
    }
  }
  return ret*100 + f;
}

string print(ll a) {
  ll f = a%100;
  a /= 100;
  string ret = "";
  int c = 0;
  while (a > 0) {
    c ++;
    ret.push_back(a%10 + '0');
    a /= 10;
    if (c == 3 && a > 0) {
      ret.push_back('.');
      c = 0;
    }
  }
  if (ret == "") {
    ret = "0";
  }
  reverse(all(ret));
  if (f) {
    string t = "00";
    t[0] = f/10+'0';
    t[1] = f%10+'0';
    ret += "." + t;
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  string p;
  cin >> p;
  ll ans = 0;
  rep(i, sz(p)) {
    if (in(p[i])) {
      continue;
    }
    int j = i;
    string t;
    while (j < sz(p) && !in(p[j])) {
      t.push_back(p[j]);
      j ++;
    }
    ans += extract(t);
    i = j - 1;
  }
  cout << print(ans);
  return 0;
}
