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

#define in(i, j) ((i) >= 0 && (i) < sz(B) && (j) >= 0 && (j) < sz(B.back()))
#define sum(a, b, c, d) (C[(c)+1][(d)+1] - C[(c)+1][b] - C[a][(d)+1] + C[a][b])

vector <int> cnt;
vector <vector <int> > seen;
vector <string> B;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int c) {
  seen[x][y] = c;
  cnt[c] ++;
  rep(t, 4) {
    int i = x+dx[t];
    int j = y+dy[t];
    if (in(i, j) && B[i][j] == '.' && seen[i][j] == -1) {
      dfs(i, j, c);
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  B.resize(n);
  repe(&e, B) {
    cin >> e;
  }
  vector <vector <int> > C(n+1, vector <int> (n+1));
  rep(i, n) {
    rep(j, n) {
      C[i+1][j+1] = (B[i][j] == '.') + C[i][j+1]+C[i+1][j]-C[i][j];
    }
  }
  seen.resize(n, vector<int>(n, -1));
  rep(i, n) {
    rep(j, n) {
      if (B[i][j] == '.' && seen[i][j] == -1) {
        cnt.push_back(0);
        dfs(i, j, sz(cnt)-1);
      }
    }
  }
  int ans = 0;
  repi(i, k-1, n) {
    rep(l, n-k+1) {
      int t = 0;
      vector <int> d(sz(cnt));
      rep(j, k) {
        if (in(i+1, j+l) && seen[i+1][j+l] != -1) {
          d[seen[i+1][j+l]] ++;
          if (d[seen[i+1][j+l]] == 1) {
            t += cnt[seen[i+1][j+l]];
          }
        }
        if (in(i-k, j+l) && seen[i-k][j+l] != -1) {
          d[seen[i-k][j+l]] ++;
          if (d[seen[i-k][j+l]] == 1) {
            t += cnt[seen[i-k][j+l]];
          }
        }
        if (in(i-j, l-1) && seen[i-j][l-1] != -1) {
          d[seen[i-j][l-1]] ++;
          if (d[seen[i-j][l-1]] == 1) {
            t += cnt[seen[i-j][l-1]];
          }
        }
        if (in(i-j, l+k) && seen[i-j][l+k] != -1) {
          d[seen[i-j][l+k]] ++;
          if (d[seen[i-j][l+k]] == 1) {
            t += cnt[seen[i-j][l+k]];
          }
        }
      }
      ans = max(ans, t+k*k-sum(i-k+1, l, i, l+k-1));
    }
  }
  cout << ans << endl;
  return 0;
}
