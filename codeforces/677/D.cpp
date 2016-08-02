#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

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

void update_y (vector <vector <int> > &t, int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = min(t[vx*2][vy], t[vx*2+1][vy]);
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y (t, vx, lx, rx, vy*2, ly, my, x, y, new_val);
		else
			update_y (t, vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
		t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
	}
}
 
void update_x (vector <vector <int> > &t, int vx, int lx, int rx, int x, int y, int new_val, int n) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x (t, vx*2, lx, mx, x, y, new_val, n);
		else
			update_x (t, vx*2+1, mx+1, rx, x, y, new_val, n);
	}
	update_y (t, vx, lx, rx, 1, 0, n, x, y, new_val);
}

int sum_y (vector <vector <int> > &t, int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 1<<29;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return min(
        sum_y (t, vx, vy*2, tly, tmy, ly, min(ry,tmy)),
		sum_y (t, vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry)
    );
}
 
int sum_x (vector <vector <int> > &t, int vx, int tlx, int trx, int lx, int rx, int ly, int ry, int n) {
	if (lx > rx)
		return 1<<29;
	if (lx == tlx && trx == rx)
		return sum_y (t, vx, 1, 0, n, ly, ry);
	int tmx = (tlx + trx) / 2;
	return min(
        sum_x (t, vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry, n),
		sum_x (t, vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry, n)
    );
}

vector <vector <int> > seg[4];

int read(int id, int node, int x1, int y1, int x2, int y2, int a, int b, int c, int d) {
    return sum_x(seg[id], 1, x1, x2, a, c, b, d, y2);
}

void update(int id, int node, int x1, int y1, int x2, int y2, int a, int b, int val) {
    update_x(seg[id], 1, x1, x2, a, b, val, y2);
}

bool check_seg() {
    srand(clock());
    int m = 30;
    int n = 25;
    vector <vector <int> > B(m, vector <int> (n));
    rep(k, 4) {
        seg[k] = vector <vector <int> > (m*4+5, vector <int> (n*4+5));
    }
    rep(i, m) {
        rep(j, n) {
            B[i][j] = rand()%100000;
            update(0, 0, 0, 0, m-1, n-1, i, j, B[i][j]);
        }
    }
    rep(i, m) {
        rep(j, n) {
            repi(x, i, m) {
                repi(y, j, n) {
                    int t = read(0, 0, 0, 0, m-1, n-1, i, j, x, y);
                    int ans = 1<<29;
                    repi(p, i, x+1) {
                        repi(q, j, y+1) {
                            ans = min(ans, B[p][q]);
                        }
                    }
                    if (t != ans) {
                        return false;
                    }
                }
            }
        }
    }
    return true;    
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int m, n, p;
    cin >> m >> n >> p;
    vector <vector <int> > x(p+1), y(p+1);
    x[0].pb(0), y[0].pb(0);
    rep(i, m) {
        rep(j, n) {
            int a;
            cin >> a;
            x[a].pb(i);
            y[a].pb(j);
        }
    }
    rep(k, 4) {
        seg[k] = vector <vector <int> >(4*m+5, vector <int>(4*n+5));
    }
    rep(i, m) {
        rep(j, n) {
            rep(k, 4) {
                update(k, 0, 0, 0, m-1, n-1, i, j, 1<<29);
            }
        }
    }
    vector <int> dp[2];
    int now = 0, pre = 1;
    dp[now].pb(0);
    for (int t = p-1; t >= 0; t --) {
        swap(now, pre);
        rep(i, sz(dp[pre])) {
            int a = x[t+1][i];
            int b = y[t+1][i]; 
            update(0, 0, 0, 0, m-1, n-1, a, b, dp[pre][i]+a+b);
            update(1, 0, 0, 0, m-1, n-1, a, b, dp[pre][i]-a+b);
            update(2, 0, 0, 0, m-1, n-1, a, b, dp[pre][i]+a-b);
            update(3, 0, 0, 0, m-1, n-1, a, b, dp[pre][i]-a-b);
        }
        dp[now].resize(sz(x[t]));
        rep(k, sz(x[t])) {
            int i = x[t][k];
            int j = y[t][k];
            int a = read(0, 0, 0, 0, m-1, n-1, i, j, m-1, n-1);
            int b = read(1, 0, 0, 0, m-1, n-1, 0, j, i, n-1);
            int c = read(2, 0, 0, 0, m-1, n-1, i, 0, m-1, j);
            int d = read(3, 0, 0, 0, m-1, n-1, 0, 0, i, j);
            dp[now][k] = min(min(a-i-j, b+i-j), min(c-i+j, d+i+j));
        }
        rep(i, sz(dp[pre])) {
            int a = x[t+1][i];
            int b = y[t+1][i]; 
            update(0, 0, 0, 0, m-1, n-1, a, b, 1<<29);
            update(1, 0, 0, 0, m-1, n-1, a, b, 1<<29);
            update(2, 0, 0, 0, m-1, n-1, a, b, 1<<29);
            update(3, 0, 0, 0, m-1, n-1, a, b, 1<<29);
        }
    }
    cout << dp[now][0];
    return 0;
}
