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
  std::ios_base::sync_with_stdio(false);
  vt(string) str = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
  map <string, int> id;
  rep(i, 7) {
    id[str[i]] = i;
  }
  string p, q;
  cin >> p >> q;
  int r = (id[q]-id[p]+7) % 7;
  if (r == 0 || r == 2 || r == 3) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
