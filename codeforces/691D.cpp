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

vector <vector <int> > adj;
vector <int> com;

void dfs(int u, int c) {
  com[u] = c;
  repe(v, adj[u]) {
    if (com[v] == -1) {
      dfs(v, c);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  com.resize(n, -1);
  vector <int> id(n);
  rep(i, n) {
    int x;
    cin >> x;
    id[x-1] = i;
  }
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  rep(i, n) {
    if (com[i] == -1) {
      dfs(i, i);
    }
  }
  vector <vector <int> > Q(n);
  rep(i, n) {
    Q[com[id[i]]].push_back(i);
  }
  rep(i, n) {
    cout << Q[com[i]].back()+1 << " ";
    Q[com[i]].pop_back();
  }
  return 0;
}
