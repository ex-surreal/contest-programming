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
  int n;
  cin >> n;
  vector <long long> a(n+1);
  repi(i, 1, n+1) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  set <pair <int, int> > p;
  multiset <long long> sum;
  p.insert(mp(1, n));
  sum.insert(a.back());
  rep(i, n) {
    int x;
    cin >> x;
    auto it = p.upper_bound(mp(x, n+3));
    pair <int, int> t;
    if (it == p.end()) {
      t = *p.rbegin();
    } else {
      it --;
      t = *it;
    }
    p.erase(t);
    sum.erase(sum.find(a[t.y]-a[t.x-1]));
    p.insert(mp(t.x, x-1));
    sum.insert(a[x-1]-a[t.x-1]);
    p.insert(mp(x+1, t.y));
    sum.insert(a[t.y]-a[x]);
    cout << *sum.rbegin() << "\n";
  }
  return 0;
}
