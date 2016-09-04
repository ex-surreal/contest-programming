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
  vector <vector <int> > a(n, vector <int> (n));
  rep(i, n) {
    rep(j, n) {
      cin >> a[i][j];
    }
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  vector <long long> row(n), col(n);
  int ri, ci;
  rep(i, n) {
    rep(j, n) {
      row[i] += a[i][j];
      col[j] += a[i][j];
      if (a[i][j] == 0) {
        ri = i, ci = j;
      }
    }
  }
  long long rs = row[ri], cs = col[ci];
  if (rs != cs) {
    cout << -1;
    return 0;
  }
  long long s = -1;
  rep(i, n) {
    if (i != ri) {
      if (s != -1 && s != row[i]) {
        cout << -1;
        return 0;
      }
      s = row[i];
    }
    if (i != ci) {
      if (s != -1 && s != col[i]) {
        cout << -1;
        return 0;
      }
      s = col[i];
    }
  }
  if (s <= rs) {
    cout << -1;
    return 0;
  }
  int di = -1, ei = -1;
  long long ds = 0, es = 0;
  rep(i, n) {
    if (a[i][i] == 0) {
      di = i;
    }
    if (a[i][n-1-i] == 0) {
      ei = i;
    }
    ds += a[i][i];
    es += a[i][n-1-i];
  }
  if (di != -1 && ei != -1) {
    if (ds != es || ds != rs) {
      cout << -1;
      return 0;
    }
  } else if (di != -1) {
    if (ds != rs || es != s) {
      cout << -1;
      return 0;
    }
  } else if (ei != -1) {
    if (es != rs || ds != s) {
      cout << -1;
      return 0;
    }
  } else {
    if (ds != s || es != s) {
      cout << -1;
      return 0;
    }
  }
  cout << s-rs;
  return 0;
}
