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
  vector <int> a(n), b(n);
  rep(i, n) {
    cin >> a[i];
    a[i] = b[i] = a[i]-i;
  }
  sort(all(b));
  vector <vector <long long> > dp(2, vector <long long> (n));
  int now = 0, pre = 1;
  rep(i, n) {
    swap(now, pre);
    dp[now][0] = dp[pre][0] + abs(a[i]-b[0]);
    repi(j, 1, n) {
      dp[now][j] = min(dp[pre][j] + abs(a[i]-b[j]), dp[now][j-1]);
    }
  }
  cout << dp[now][n-1];
  return 0;
}
