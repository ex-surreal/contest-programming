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

bool comp(pair <int, int> p, pair <int, int> q) {
  int a = p.y - (p.y-p.x)/2-1;
  int b = q.y - (q.y-q.x)/2-1;
  if (a == b) {
    return p.x < q.x;
  }
  return a < b;
}

int main () {
  int n;
  while (~scanf("%d", &n) && n) {
    vector <pair <int, int> > p(n);
    repe(&e, p) {
      scanf("%d%d", &e.x, &e.y);
    }
    sort(all(p), comp);
    int lst = -1;
    string ans = "YES";
    repe(e, p) {
      lst = max(lst, e.x);
      if (lst > e.y - (e.y-e.x)/2-1) {
        ans = "NO";
        break;
      }
      lst += (e.y-e.x)/2+1;
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}
