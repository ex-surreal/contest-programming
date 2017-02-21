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

int unit;
vt(vt(int)) adj;
vt(int) sum;

int dfs(int u) {
  repe(v, adj[u]) {
    sum[u] += dfs(v);
  }
  return sum[u];
}

int see(int u) {
  int ret = -1;
  repe(v, adj[u]) {
    int t = see(v);
    if (t == -1) {
      continue;
    }
    if (sum[u] == unit*2) {
      throw mp(u+1, t+1);
    }
    if (ret != -1) {
      throw mp(ret+1, t+1);
    }
    ret = t;
  }
  ret = ret == -1 && sum[u] == unit ? u : ret;
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, r;
  cin >> n;
  adj.resize(n);
  sum.resize(n);
  rep(i, n) {
    int p;
    cin >> p >> sum[i];
    if (!p) {
      r = i;
      continue;
    }
    adj[p-1].push_back(i);
  }
  unit = dfs(r);
  if (unit % 3) {
    cout << -1;
    return 0;
  }
  unit /= 3;
  try {
    sum[r] = INT_MIN/3;
    see(r);
    cout << -1;
  } catch (px(int) ans) {
    cout << ans.x << " " << ans.y << endl;
  }
  return 0;
}
