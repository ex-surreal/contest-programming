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

string bfs(int m, string p) {
  vector <int> digit(m), parent(m, -1), Q(m);
  int fr = 0, bk = 0;
  repe(e, p) {
    if (!e) {
      continue;
    }
    Q[bk ++] = e%m;
    parent[e%m] = 0;
    digit[e%m] = e;
  }
  while (fr < bk) {
    int u = Q[fr ++];
    if (u == 0) {
      break;
    }
    repe(e, p) {
      int v = (u*10+e) % m;
      if (parent[v] == -1) {
        parent[v] = u;
        digit[v] = e;
        Q[bk ++] = v;
      }
    }
  }
  if (parent[0] == -1) {
    return "";
  }
  string ret = "";
  int u = 0;
  do {
    ret.push_back('0'+digit[u]);
    u = parent[u];
  } while (u);
  reverse(all(ret));
  return ret;
}

vector <string> go[5];

void gen() {
  rep(i, 1<<10) {
    int t = __builtin_popcount(i);
    if (t > 4) {
      continue;
    }
    go[t].push_back("");
    rep(j, 10) {
      if ((i>>j)&1) {
        go[t].back().push_back(j);
      }
    }
  }
}

int diff_digit(int n) {
  vector <int> f(10);
  while (n > 0) {
    f[n%10] = 1;
    n /= 10;
  }
  return accumulate(all(f), 0);
}

string solve(int m) {
  int t = diff_digit(m);
  repi(i, 1, t) {
    string ret = "";
    repe(p, go[i]) {
      string g = bfs(m, p);
      if (g != "" && (ret == "" || (sz(ret) > sz(g) || (sz(ret) == sz(g) && g < ret)))) {
        ret = g;
      }
    }
    if (ret != "") {
      return ret;
    }
  }
  return to_string(m);
}

int main () {
  gen();
  int n;
  while (~scanf("%d", &n) && n) {
    printf("%s\n", solve(n).c_str());
  }
  return 0;
}
