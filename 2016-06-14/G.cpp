#include <iostream>
#include <vector>
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

int ids[500][1000];
int x[40005], y[40005];

int di[] = {-1, 1, 2, 1, -1, -2};
int dj[] = {1, 1, 0, -1, -1, 0};

int cnt;

void gen(int i, int j) {
    ids[i][j] = ++cnt;
    x[cnt] = i, y [cnt] = j;
    queue <pair <int, int> > q;
    q.push(mp(i, j));
    while (!q.empty()) {
        i = q.front().x;
        j = q.front().y;
        q.pop();
        if (cnt >= 40000) {
            break;
        }
        rep(t, 6) {
            int a = i+di[t];
            int b = j+dj[t];
            if (a >= 0) {
                if (ids[a][b] == 0) {
                    ids[a][b] = ++cnt;
                    x[cnt] = a, y[cnt] = b;
                    q.push(mp(a, b));
                }
            }
        }
    }
}

int D[405][405];

int bfs(int i, int j, int a, int b) {
    queue <pair <int, int> > q;
    mem(D, -1);
    q.push(mp(i, j));
    D[i][j] = 0;
    while (!q.empty()) {
        i = q.front().x;
        j = q.front().y;
        if (i == a && j == b) {
            return D[i][j];
        }
        q.pop();
        rep(t, 6) {
            int a = i+di[t];
            int b = j+dj[t];
            if (a >= 0) {
                if (ids[a][b] && D[a][b] == -1) {
                    D[a][b] = D[i][j] + 1;
                    q.push(mp(a, b));
                }
            }
        }
    }
    return -1;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    gen(0, 400);
    int i, j;
    while (cin >> i >> j && i && j) {
        int a = x[i], b = y[i];
        int p = x[j], q = y[j];
        cout << bfs(a, b, p, q) << "\n";
    }
    return 0;
}
