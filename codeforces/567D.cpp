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

#define cnt(d) (((d)+1)/(a+1))

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, k, a, m;
  cin >> n >> k >> a >> m;
  set <int> st({0, n+1});
  int cur = cnt(n), ans = -1;
  rep(i, m) {
    int x;
    cin >> x;
    st.insert(x);
    auto it = st.find(x);
    it --;
    int p = *it;
    it ++, it ++;
    int q = *it;
    cur -= cnt(q-p-1);
    cur += cnt(x-p-1);
    cur += cnt(q-x-1);
    if (cur < k && ans == -1) {
      ans = i+1;
    }
  }
  cout << ans;
  return 0;
}
