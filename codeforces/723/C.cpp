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

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, r = 0;
  cin >> n >> m;
  vector <int> a(n), cnt(m+1);
  rep(i, n) {
    cin >> a[i];
    if (a[i] <= m) {
      cnt[a[i]] ++;
    } else {
      r ++;
    }
  }
  r -= n%m;
  set <pair <int, int> > st;
  rep(i, m) {
    st.insert(mp(cnt[i+1], i+1));
  }
  int ans = 0;
  rep(i, n) {
    if (r <= 0) {
      break;
    }
    if (a[i] > m) {
      int id = st.begin()->y;
      st.erase(mp(cnt[id], id));
      cnt[id] ++;
      a[i] = id;
      ans ++;
      r --;
      st.insert(mp(cnt[id], id));
    }
  }
  rep(i, n) {
    if (a[i] > m) {
      continue;
    }
    if (cnt[a[i]] > (n+m-1)/m) {
      int id = st.begin()->y;
      st.erase(mp(cnt[id], id));
      st.erase(mp(cnt[a[i]], a[i]));
      cnt[a[i]] --;
      cnt[id] ++;
      ans ++;
      st.insert(mp(cnt[id], id));
      st.insert(mp(cnt[a[i]], a[i]));
      a[i] = id;
    }
  }
  cout << n/m << " " << ans << "\n";
  repe(e, a) {
    cout << e << " ";
  }
  return 0;
}
