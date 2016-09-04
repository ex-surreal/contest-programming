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

vector <int> a;
int cnt[1000006];
vector <int> s, ans;

void dfs() {
  bool f = true;
  repe(e, a) {
    if (!cnt[e]) {
      f = false;
      break;
    }
  }
  if (f) {
    if (sz(ans) > sz(s) || (sz(ans) == sz(s) && ans.back() > s.back())) {
      ans = s;
    }
    return;
  }
  if (sz(s) == 7) {
    return;
  }
  repe(r, a) {
    if (cnt[r] > 0) {
      continue;
    }
    repe(d, s) {
      int c = d+r;
      if (c <= s.back()) {
        continue;
      }
      repe(f, s) {
        if (c-f <= a.back() &&  cnt[c-f] != -1) {
          cnt[c-f] ++;
        }
      }
      s.push_back(c);
      dfs();
      s.pop_back();
      repe(f, s) {
        if (c-f <= a.back() &&  cnt[c-f] != -1) {
          cnt[c-f] --;
        }
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, cas = 0;
  mem(cnt, -1);
  while (cin >> n && n) {
    set <int> st;
    rep(i, n) {
      int x;
      cin >> x;
      st.insert(x);
    }
    a.clear();
    s.clear();
    repe(e, st) {
      a.push_back(e);
      cnt[e] = 0;
    }
    s.push_back(0);
    ans.resize(10);
    dfs();
    cout << "Case " << ++cas << ":\n" << sz(ans) << endl;
    string sp = "";
    repe(e, ans) {
      cout << sp << e;
      sp = " ";
    }
    cout << "\n";
    repe(e, a) {
      cnt[e] = -1;
    }
  }
  return 0;
}
