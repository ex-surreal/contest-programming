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
  int m;
  cin >> m;
  string p;
  cin >> p;
  vt(vt(int)) pre(26, vt(int)(sz(p), -1));
  vt(int) c(26);
  rep(i, sz(p)) {
    rep(j, 26) {
      pre[j][i] = (i > 0 ? pre[j][i-1] : -1);
    }
    pre[p[i]-'a'][i] = i;
    c[p[i]-'a'] ++;
  }
  int lst = -1, cnt = 0;
  int now = 0, f = 1;
  vt(int) v[2];
  rep(i, sz(p)-m+1) {
    v[now].push_back(i);
  }
  while (sz(v[now])) {
    swap(now, f);
    v[now].clear();
    lst ++;
    cnt = 0;
    rep(i, sz(v[f])) {
      int x = v[f][i];
      if (pre[lst][x+m-1] < x) {
        v[now].push_back(x);
      } else {
        cnt ++;
        while (i < sz(v[f]) && v[f][i] <= pre[lst][x+m-1]) {
          i ++;
        }
        i --;
      }
    }
  }
  rep(i, lst) {
    cout << string(c[i], 'a'+i);
  }
  cout << string(cnt, 'a'+lst);
  return 0;
}
