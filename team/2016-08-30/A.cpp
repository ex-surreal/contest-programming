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

bool bsreach(int n, int l, int j) {
  int p = 0, q = n-1, i = -1;
  while (p <= q) {
    i = (p+q)/2;
    l --;
    if (i == j || l == 0) {
      break;
    }
    if (i > j) {
      q = i-1;
    } else {
      p = i+1;
    }
  }
  return i == j && l == 0;
}

int main () {
  int i, l;
  while (~scanf("%d%d", &i, &l)) {
    vector <int> x, y;
    repi(n, i+1, 10001) {
      if (!bsreach(n, l, i)) {
        continue;
      }
      int j = n+1;
      while (j <= 10000 && bsreach(j, l, i)) {
        j ++;
      }
      x.push_back(n);
      y.push_back(j-1);
      n = j-1;
    }
    printf("%d\n", sz(x));
    rep(i, sz(x)) {
      printf("%d %d\n", x[i], y[i]);
    }
  }
  return 0;
}
