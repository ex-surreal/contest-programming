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

using namespace std;

const int inf = (1 << 30);
vector <int> L, pre, to, ptr, cap, flow;

void init(int n) {
  L = vector <int> (n, -1);
  pre.clear();
  to.clear();
  ptr.clear();
  cap.clear();
  flow.clear();
}

void add(int u, int v, int c = 1) {
  to.push_back(v);
  pre.push_back(L[u]);
  cap.push_back(c);
  flow.push_back(0);
  L[u] = to.size()-1;
}

void add_edge(int u, int v, int c = 1) {
  add(u, v, c);
  add(v, u, 0);
}

bool bfs(int s, int t) {
  int fr = 0, bk = 0;
  vector <int> parent(L.size(), -1);
  vector <int> Q(L.size());
  Q[bk++] = s;
  while (fr < bk) {
    int u = Q[fr++];
    for (int e = L[u]; e != -1; e = pre[e]) {
      if (flow[e] < cap[e]) {
        int v = to[e];
        if (parent[v] == -1) {
          parent[v] = e;
          Q[bk++] = v;
        }
      }
    }
  }
  if (parent[t] == -1) {
    return false;
  }
  while (t != s) {
    flow[parent[t]] ++;
    flow[parent[t]^1] --;
    t = to[parent[t]^1];
  }
  return true;;
}

void augment(int s, int t, int &rem) {
  while (bfs(s, t) && rem) {
    rem --;
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m, k, s, t;
  vector <vector <vector <int> > > X, Y;
  freopen("ans.out", "r", stdin);
  {
    int n;
    while (cin >> n) {
      X.resize(sz(X)+1);
      Y.resize(sz(Y)+1);
      X.back().resize(n);
      Y.back().resize(n);
      rep(i, n) {
        int k;
        cin >> k;
        X.back()[i].resize(k);
        Y.back()[i].resize(k);
        rep(j, k) {
          cin >> X.back()[i][j] >> Y.back()[i][j];
        }
      }
    }
  }
  reverse(all(X));
  reverse(all(Y));
  fclose(stdin);
  while (cin >> n >> m >> k >> s >> t) {
    s --, t --;
    vector <int> u(m), v(m);
    rep(i, m) {
      cin >> u[i] >> v[i];
      u[i] --, v[i] --;
    }
    vector <int> id(10000), jd(10000);
    init(10000);
    int day = 0, rem = k;
    while (rem > 0) {
      rep(i, n) {
        add_edge(n*day+i, n*(day+1)+i, inf);
        id[n*day+i] = id[n*(day+1)+i] = i;
        jd[n*day+i] = day;
        jd[n*(day+1)+i] = day+1;
      }
      rep(i, m) {
        add_edge(n*day+u[i], n*(day+1)+v[i]);
        add_edge(n*day+v[i], n*(day+1)+u[i]);
      }
      augment(s, n*(day+1)+t, rem);
      day ++;
    }
    vector <vector <int> > ship(day), where(day);
    vector <int> gone(sz(flow));
    rep(i, k) {
      int g = s;
      while (id[g] != t) {
        for (int e = L[g]; ~e; e = pre[e]) {
          if (flow[e] > gone[e]) {
            if (id[g] != id[to[e]]) {
              ship[jd[g]].push_back(i+1);
              where[jd[g]].push_back(id[to[e]]+1);
            }
            gone[e] ++;
            g = to[e];
            break;
          }
        }
      }
    }
    auto A = X.back(), B = Y.back();
    X.pop_back();
    Y.pop_back();
    bool ok = sz(A) == sz(ship);
    cout << sz(ship) << "\n";
    rep(i, sz(ship)) {
      cout << sz(ship[i]);
      if (sz(ship[i]) != sz(A[i])) {
        ok = false;
      }
      rep(j, sz(ship[i])) {
        if (A[i][j] != ship[i][j] || B[i][j] != where[i][j]) {
          ok = false;
        }
        cout << " " << ship[i][j] << " " << where[i][j];
      } cout << "\n";
    }
    if (!ok) {
      cerr << n << " " << m << " " << k << " " << s+1 << " " << t+1 << endl;
      rep(i, m) {
        cerr << u[i]+1 << " " << v[i] << endl;
      }
      return 0;
    }
  }
  return 0;
}
