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

long long dp[55];

long long solve(int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return 0;
  }
  long long &ret = dp[n];
  if (ret == -1) {
    ret = 0;
    repi(i, 2, n+1) {
      ret += solve(i-2)*solve(n-i);
    }
  }
  return ret;
}

string back(int n, long long m) {
  if (n == 0) {
    return "";
  }
  for (int i = 2; i <= n; i += 2) {
    if (m <= solve(i-2)) {
      return "E"+back(i-2, m)+back(n-i, 1)+"S";
    }
    m -= solve(i-2)*solve(n-i);
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  return 0;
}
