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
  string p;
  int n;
  cin >> n >> p;
  int x = 0, y = 0, inside = 0;
  rep(i, n) {
    if (p[i] == '(') {
      inside ++;
    } else if (p[i] == ')') {
      inside --;
    } else if (p[i] != '_') {
      int j = i;
      while (j < n && p[j] != ')' && p[j] != '(' && p[j] != '_') {
        j ++;
      }
      if (!inside) {
        x = max(x, j-i);
      } else {
        y ++;
      }
      i = j-1;
    }
  }
  cout << x << " " << y;
  return 0;
}
