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
  vector <int> primes;
  repi(i, 2, 100) {
    bool ok = true;
    repi(j, 2, i) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      primes.push_back(i);
    }
  }
  string ans = "prime";
  rep(i, 4) {
    cout << primes[i] << endl;
    string p;
    cin >> p;
    if (p == "yes") {
      repe(e, primes) {
        if (e*primes[i] <= 100) {
          cout << e*primes[i] << endl;
          cin >> p;
          if (p == "yes") {
            ans = "composite";
            break;
          }
        }
      }
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
