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
  cin >> p;
  try {
    rep(i, sz(p)-25) {
      vector <int> cnt(26, 0);
      int q = 0;
      rep(j, 26) {
        if (p[i+j] == '?') {
          q ++;
        } else {
          cnt[p[i+j]-'A'] ++;
        }
      }
      if (*max_element(all(cnt)) <= 1) {
        stack <char> S;
        rep(i, 26) {
          if (!cnt[i]) {
            S.push('A'+i);
          }
        }
        rep(j, 26) {
          if (p[i+j] == '?') {
            p[i+j] = S.top();
            S.pop();
          }
        }
        throw p;
      }
    }
    cout << -1;
  } catch (string ans) {
    repe(&e, ans) {
      if (e == '?') {
        e = 'A';
      }
    }
    cout << ans;
  }
  return 0;
}
