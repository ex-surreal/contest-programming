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
  string path;
  cin >> path;
  vt(int) last(26, -1);
  try {
    int st = -1, len = -1;
    rep(i, sz(path)) {
      if (~last[path[i]-'A']) {
        if (last[path[i]-'A'] == i-1) {
          throw string("Impossible");
        }
        st = last[path[i]-'A'];
        len = i-st;
        break;
      }
      last[path[i]-'A'] = i;
    }
    int r = 0, c = 13-((len+1)>>1);
    vt(string) ans(2, string(13, '#'));
    repi(i, st, sz(path)) {
      if (path[st] == path[i] && i != st) {
        continue;
      }
      ans[r][c] = path[i];
      c += !r ? 1 : -1;
      if (c >= 13) {
        r ^= 1;
        c = 12;
      } else if (c < 0) {
        r ^= 1;
        c = 0;
      }
    }
    rep(i, st) {
      ans[r][c] = path[i];
      c += !r ? 1 : -1;
      if (c >= 13) {
        r ^= 1;
        c = 12;
      } else if (c < 0) {
        r ^= 1;
        c = 0;
      }
    }
    repe(e, ans) {
      cout << e << endl;
    }
  } catch (string p) {
    cout << p;
  }
  return 0;
}
