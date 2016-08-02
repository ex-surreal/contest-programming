#include <bits/stdc++.h>

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

int K;
int grid[2][2505][2505];
int up[2505][8], up_sum[2505][8];
int down[2505][8], down_sum[2505][8];

long long compute(int x1, int y1, int x2, int y2, int d) {
    if (x1 == x2 && y1 == y2) {
        return grid[d][x1][y1] - grid[d][x1-1][y1] == K;
    }
    if (x2-x1 < y2-y1) {
        swap(x1, y1);
        swap(x2, y2);
        d ^= 1;
    }
    int mid = (x1+x2)>>1;
    long long ret = 0;
    repi(i, y1, y2+1) {
        rep(k, K+1) {
            up_sum[i][k] = 0;
            down_sum[i][k] = 0;
            up[i][k] = x1;
            down[i][k] = x2;
        }
        repi(j, i, y2+1) {
            rep(k, K+1) {
                up_sum[i][k] += grid[d][mid][j] - grid[d][up[i][k]-1][j];
                while (up_sum[i][k] > k) {
                    up_sum[i][k] -= grid[d^1][j][up[i][k]] - grid[d^1][i-1][up[i][k]];
                    up[i][k] ++;
                }
                down_sum[i][k] += grid[d][down[i][k]][j] - grid[d][mid][j];
                while (down_sum[i][k] > k) {
                    down_sum[i][k] -= grid[d^1][j][down[i][k]] - grid[d^1][i-1][down[i][k]];
                    down[i][k] --;
                }
            }
            rep(k, K+1) {
                if (up_sum[i][k] != k || down_sum[i][K-k] != K-k) {
                    continue;
                }
                int l, r;
                if (k == 0) {
                    l = mid - up[i][k] + 1;
                } else {
                    l = up[i][k-1] - up[i][k] ;
                }
                if (k == K) {
                    r = down[i][K-k] - mid;
                } else {
                    r = down[i][K-k] - down[i][K-k-1];
                }
                ret += l*r;
            }
        }
    }
    ret += compute(x1, y1, mid, y2, d);
    ret += compute(mid+1, y1, x2, y2, d);
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n >> K;
    rep(i, m) {
        rep(j, n) {
            char c;
            cin >> c;
            grid[0][i+1][j+1] = c - '0';
            grid[1][j+1][i+1] = c - '0';
        }
    }
    rep(i, m) {
        rep(j, n) {
            grid[0][i+1][j+1] += grid[0][i][j+1];
            grid[1][j+1][i+1] += grid[1][j][i+1];
        }
    }
    cout << compute(1, 1, m, n, 0);
    return 0;
}
