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
  int n;
  cin >> n;
  int x0, x1, x2;
  int a3, a1, a2;
  cout << "? 1 2" << endl;
  cin >> a1;
  cout << "? 1 3" << endl;
  cin >> a2;
  cout << "? 2 3" << endl;
  cin >> a3;
  x2 = (a2-a1+a3)/2;
  x1 = a3-x2;
  x0 = a1-x1;
  vector <int> ans = {x0, x1, x2};
  repi(i, 3, n) {
    cout << "? 1 " << i+1 << endl;
    int x;
    cin >> x;
    ans.push_back(x-x0);
  }
  cout << "!";
  repe(e, ans) {
    cout << " " << e;
  }
  cout << endl;
  return 0;
}
