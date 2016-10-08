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

int main () {
  int n;
  scanf("%d", &n);
  vt(vt(int)) adj(n);
  rep(i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  vt(int) D(n, -1), Q(n);
  int fr = 0, bk = 0;
  rep(i, n) {
    if (sz(adj[i]) == 1) {
      D[i] = 0;
      Q[bk ++] = i;
    }
  }
  while (fr < bk) {
    int u = Q[fr ++];
    repe(v, adj[u]) {
      if (D[v] == -1) {
        D[v] = D[u] + 1;
        Q[bk ++] = v;
      }
    }
  }
  sort(all(D));
  ll sum[2] = {0, 0};
  rep(i, n) {
    sum[i&1] += D[i];
  }
  if (sum[0] == sum[1]) {
    printf("Draw\n");
  } else if (sum[0] < sum[1]) {
    printf("3PO\n");
  } else {
    printf("Darth Vader\n");
  }
  return 0;
}
