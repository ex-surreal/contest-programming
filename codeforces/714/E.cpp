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
  vector <int> a(n);
  repe(&e, a) {
    cin >> e;
  }
  long long ans = 1ll<<60;
  rep(i, n) {
    long long t = 0;
    for (int j = n-1, lst = 1<<30; j >= 0; j --) {
      int need = a[i]+j-i;
      if (a[j] >= lst) {
        t += a[j]-lst+1;
        lst = lst-1;
      } else {
        if (need > a[j]) {
          lst = need;
          t += need-a[j];
        } else {
          lst = a[j];
        }
      }
      cout << need << " " << lst << " " << t << endl;
    }
    ans = min(t, ans);
  }
  cout << ans;
  return 0;
}
