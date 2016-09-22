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
  int tst;
  cin >> tst;
  string nl = "";
  while (tst --) {
    int n;
    cin >> n;
    vector <vector <int> > man(n, vector <int> (n));
    vector <vector <int> > woman(n, vector <int> (n));
    vector <vector <int> > proposed(n, vector <int> (n));
    rep(i, n) {
      rep(j, n) {
        cin >> man[i][j];
        man[i][j] --;
      }
    }
    rep(i, n) {
      rep(j, n) {
        int t;
        cin >> t;
        woman[i][t-1] = j;
      }
    }
    vector <int> gf(n, -1), bf(n, -1), id(n);
    int finished = n;
    while (finished) {
      rep(j, n) {
        if (gf[j] != -1) {
          continue;
        }
        int w = man[j][id[j] ++];
        if (bf[w] == -1) {
          gf[j] = w;
          bf[w] = j;
          finished --;
        } else if (woman[w][bf[w]] > woman[w][j]) {
          gf[bf[w]] = -1;
          gf[j] = w;
          bf[w] = j;
        }
      }
    }
    cout << nl;
    nl = "\n";
    rep(i, n) {
      cout << gf[i]+1 << "\n";
    }
  }
  return 0;
}
