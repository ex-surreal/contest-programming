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
  rep(i, n-k+1) {
    vector <int> d(sz(cnt));
    int sum = 0;
    rep(j, k) {
      rep(l, k) {
        if (seen[i+l][j] == -1) {
          sum ++;
          continue;
        }
        if (d[seen[i+l][j]] == 0) {
          sum += cnt[seen[i+l][j]];
        }
        d[seen[i+l][j]] ++;
      }
    }
    cout << i << " " << 0 << " " << sum << endl;
    ans = max(ans, sum);
    repi(j, 1, n-k+1) {
      rep(l, k) {
        if (seen[i+l][j+k-1] == -1) {
          sum ++;
          continue;
        }
        if (seen[i+l][j-1] == -1) {
          sum --;
          continue;
        }
        if (d[seen[i+l][j+k-1]] == 0) {
          sum += cnt[seen[i+l][j+k-1]];
        }
        d[seen[i+l][j+k-1]] ++;
        d[seen[i+l][j-1]] --;
        if (d[seen[i+l][j-1]] == 0) {
          sum -= cnt[seen[i+l][j-1]];
        }
      }
      cout << i << " " << j << " " << sum << endl;
      ans = max(ans, sum);
    }
  }
  cout << ans;
  return 0;
}
