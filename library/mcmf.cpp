#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int inf = (1<<30);
typedef pair <int, int> fc;
vector <int> L, pre, to;
vector <int> cap, flow, cost;

void init(int n) {
  L = vector <int>(n, -1);
  pre.clear();
  to.clear();
  cap.clear();
  flow.clear();
  cost.clear();
}

void add(int u, int v, int c = 1, int w = 0) {
  to.push_back(v);
  pre.push_back(L[u]);
  cap.push_back(c);
  cost.push_back(w);
  flow.push_back(0);
  L[u] = pre.size()-1;
}

void add_edge(int u, int v, int c = 1, int w = 0) {
  add(u, v, c, w);
  add(v, u, 0, -w);
}

bool augment(int s, int t, fc & ans) {
  int n = L.size();
  vector <int> D(n, inf), Q(n), F(n), parent(n, -1), edge(n);
  vector <bool> inq(n, false);

  int fr = 0, bk = 0;
  F[s] = inf;
  D[s] = 0;
  Q[bk % n] = s;
  bk ++;
  inq[s] = true;

  while (fr < bk) {
    int u = Q[fr % n];
    fr ++;
    inq[u] = false;

    for (int e = L[u]; e != -1; e = pre[e]) {
      if (flow[e] < cap[e]) {
        int v = to[e];
        int w = cost[e];
        if (D[v] > D[u] + w) {
          D[v] = D[u] + w;
          F[v] = min(F[u], cap[e]-flow[e]);
          edge[v] = e;
          parent[v] = u;
          if (!inq[v]) {
            Q[bk % n] = v;
            bk ++;
            inq[v] = true;
          }
        }
      }
    }
  }

  if (parent[t] == -1) {
    return false;
  }

  int g = t;
  while (g != s) {
    flow[edge[g]] += F[t];
    flow[edge[g]^1] -= F[t];
    g = parent[g];
  }
  ans.first += F[t];
  ans.second += D[t];
  return true;
}

fc mcmf(int s, int t) {
  fc ret(0, 0);
  while (augment(s, t, ret)); 
  return ret;
}
