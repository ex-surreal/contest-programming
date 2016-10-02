#include <iostream>
#include <sstream>
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
  string line;
  getline(cin, line);
  n = stoi(line);
  getline(cin, line);
  stringstream sin(line);
  vector <int>  a(n);
  rep(i, n) {
    sin >> a[i];
  }
  string ans = "YES";
  rep(i, n) {
    getline(cin, line);
    repe(c, line) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        a[i] --;
      }
    }
    if (a[i] != 0) {
      ans = "NO";
    }
  }
  cout << ans;
  return 0;
}
