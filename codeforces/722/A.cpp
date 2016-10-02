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
  int x, h, m;
  scanf("%d%d:%d", &x, &h, &m);
  if (x == 12) {
    if (h == 0) {
      h = 1;
    } else if (h > 12) {
      if (h%10) {
        h %= 10;
      } else {
        h = 10;
      }
    }
  } else {
    if (h > 23) {
      h %= 10;
    }
  }
  if (m > 59) {
    m %= 10;
  }
  printf("%02d:%02d", h, m);
  return 0;
}
