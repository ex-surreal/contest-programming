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

bool dp[2][105][1024];

int main () {
  int n, q;
  scanf("%d%d", &n, &q);
  vt(int) a(n);
  rep(i, n) {
    scanf("%d", &a[i]);
  }
  int now = 0, pre = 1;
  dp[now][0][0] = 1;
  rep(i, n) {
    swap(now, pre);
    rep(j, n+1) {
      rep(k, 1024) {
        dp[now][j][k] = dp[pre][j][k];
        if (j > 0 && dp[pre][j-1][k^a[i]]) {
          dp[now][j][k] = true;
        }
      }
    }
  }
  rep(i, q) {
    int k;
    scanf("%d", &k);
    rep(j, 1024) {
      if (dp[now][k][j]) {
        printf("%d\n", j);
        break;
      }
    }
  }
  return 0;
}
