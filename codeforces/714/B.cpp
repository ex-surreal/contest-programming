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
  set <int> st;
  rep(i, n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  if (sz(st) > 3) {
    cout << "NO";
    return 0;
  }
  if (sz(st) < 3) {
    cout << "YES";
    return 0;
  }
  int a = *st.begin(); st.erase(st.begin());
  int b = *st.begin(); st.erase(st.begin());
  int c = *st.begin(); st.erase(st.begin());
  if (b-a == c-b) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
