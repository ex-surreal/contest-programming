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

typedef long long ll;

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k >> x;
  x = -x;
  set <pair <ll, int> > pos, neg;
  rep(i, n) {
    int a;
    cin >> a;
    if (a >= 0) {
      pos.insert(mp(a, i));
    } else {
      neg.insert(mp(-a, i));
      x = -x;
    }
  }
  rep(i, k) {
    if (!pos.empty() && !neg.empty()) {
      auto a = *pos.begin();
      auto b = *neg.begin();
      if (a.x <= b.x) {
        a.x += x;
        pos.erase(pos.begin());
        if (a.x < 0) {
          a.x = -a.x;
          neg.insert(a);
          x = -x;
        } else {
          pos.insert(a);
        }
      } else {
        b.x = -(b.x + x);
        neg.erase(neg.begin());
        x = -x;
        if (b.x < 0) {
          b.x = -b.x;
          neg.insert(b);
          x = -x;
        } else {
          pos.insert(b);
        }
      }
    } else if (!pos.empty()) {
      auto a = *pos.begin();
      a.x += x;
      pos.erase(pos.begin());
      if (a.x < 0) {
        a.x = -a.x;
        neg.insert(a);
        x = -x;
      } else {
        pos.insert(a);
      }
    } else {
      auto b = *neg.begin();
      b.x = -(b.x + x);
      neg.erase(neg.begin());
      x = -x;
      if (b.x < 0) {
        b.x = -b.x;
        neg.insert(b);
        x = -x;
      } else {
        pos.insert(b);
      }
    }
  }
  vector <ll> ans(n);
  repe(e, pos) {
    ans[e.y] = e.x;
  }
  repe(e, neg) {
    ans[e.y] = -e.x;
  }
  repe(e, ans) {
    cout << e << " ";
  }
  return 0;
}
