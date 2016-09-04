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

typedef pair <int, pair <int, int> > segment;

class event {
  public:
  int x, t, y1, y2;
  event(int x, int t, int y1 = 0, int y2 = 0) {
    this->x = x;
    this->t = t;
    this->y1 = y1;
    this->y2 = y2;
  }
};

bool operator < (event a, event b) {
  return (a.x == b.x ? a.t < b.t : a.x < b.x);
}

bool is_intersect(vector <segment> &h, vector <segment> &v) {
  vector <event> sweep;
  repe(e, h) {
    sweep.push_back(event(e.y.x, 0, e.x));
    sweep.push_back(event(e.y.y, 2, e.x));
  }
  repe(e, v) {
    sweep.push_back(event(e.x, 1, e.y.x, e.y.y));
  }
  sort(all(sweep));
  set <int> st;
  repe(e, sweep) {
    if (e.t == 0) {
      st.insert(e.y1);
    } else if (e.t == 1) {
      auto it = st.upper_bound(e.y1);
      if (it != st.end() && *it < e.y2) {
        return true;
      }
    } else {
      st.erase(e.y1);
    }
  }
  return false;
}

vector <vector <int> > adj;
vector <bool> seen;

int dfs(int u) {
  int ret = 1;
  seen[u]= true;
  repe(v, adj[u]) {
    if (!seen[v]) {
      ret += dfs(v);
    }
  }
  return ret;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int tst;
  cin >> tst;
  while (tst --) {
    int n;
    cin >> n;
    map <int, vector <int> > h, v;
    map <pair <int, int>, int> id;
    rep(i, n) {
      int x, y;
      cin >> x >> y;
      h[y].push_back(x);
      v[x].push_back(y);
      id[mp(x, y)] = i;
    }
    adj.clear(), adj.resize(n);
    seen.clear(), seen.resize(n);
    vector <segment> a, b;
    bool ok = true;
    long long ans = 0;
    repe(e, h) {
      if (sz(e.y)&1) {
        ok = false;
        break;
      }
      sort(all(e.y));
      for (int i = 0; i < sz(e.y); i += 2) {
        ans += e.y[i+1]-e.y[i];
        a.push_back(mp(e.x, mp(e.y[i], e.y[i+1])));
        adj[id[mp(e.y[i], e.x)]].push_back(id[mp(e.y[i+1], e.x)]);
        adj[id[mp(e.y[i+1], e.x)]].push_back(id[mp(e.y[i], e.x)]);
      }
    }
    repe(e, v) {
      if (!ok || (sz(e.y)&1)) {
        ok = false;
        break;
      }
      sort(all(e.y));
      for (int i = 0; i < sz(e.y); i += 2) {
        ans += e.y[i+1]-e.y[i];
        b.push_back(mp(e.x, mp(e.y[i], e.y[i+1])));
        adj[id[mp(e.x, e.y[i])]].push_back(id[mp(e.x, e.y[i+1])]);
        adj[id[mp(e.x, e.y[i+1])]].push_back(id[mp(e.x, e.y[i])]);
      }
    }
    if (!ok || is_intersect(a, b) || dfs(0) != n) {
      ans = -1;
    }
    cout << ans << "\n";
  }
  return 0;
}
