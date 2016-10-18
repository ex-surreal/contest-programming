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

string p[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int main () {
  std::ios_base::sync_with_stdio(false);
  map <string, int> id;
  vt(int) cnt(6), x, y, w;
  rep(i, 6) {
    id[p[i]] = i;
    cin >> cnt[i];
  }
  int n;
  cin >> n;
  vt(string) ans(n), a(n);
  repe(&e, a) {
    cin >> e;
  }
  try {
    rep(i, n) {
      if (a[i].find(',') > (unsigned long) sz(a[i])) {
        if (!cnt[id[a[i]]]) {
          throw string("NO");
        } else {
          cnt[id[a[i]]] --;
          ans[i] = a[i];
        }
      } else {
        int j = id[a[i].substr(0, a[i].find(','))];
        int k = id[a[i].substr(a[i].find(',')+1)];
        if (j > k) {
          swap(j, k);
        }
        x.push_back(j);
        y.push_back(k);
        w.push_back(i);
      }
    }
    rep(i, 3) {
      int j = 5-i;
      rep(l, sz(x)) {
        if (ans[w[l]] != "") {
          continue;
        }
        if (y[l] == i && cnt[i] > 0) {
          cnt[i] --;
          ans[w[l]] = p[i];
        } else if (x[l] == j && cnt[j] > 0) {
          cnt[j] --;
          ans[w[l]] = p[j];
        }
      }
      rep(l, sz(x)) {
        if (ans[w[l]] != "") {
          continue;
        }
        if (x[l] == i && cnt[i] > 0) {
          cnt[i] --;
          ans[w[l]] = p[i];
        } else if (y[l] == j && cnt[j] > 0) {
          cnt[j] --;
          ans[w[l]] = p[j];
        }
      }
    }
    repe(e, ans) {
      if (e == "") {
        throw string("NO");
      }
    }
    cout << "YES\n";
    repe(e, ans) {
      cout << e << "\n";
    }
  } catch(string p) {
    cout << p;
  }
  return 0;
}
