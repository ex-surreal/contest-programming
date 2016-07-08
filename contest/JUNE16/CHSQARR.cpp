#include <iostream>
#include <cassert>
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

int main () {
    std::ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector <vector <int> > A(m, vector <int>(n));
    rep(i, m) {
        rep(j, n) {
            cin >> A[i][j];
        }
    }
    int tst;
    cin >> tst;
    while (tst --) {
        int a, b;
        cin >> a >> b;
        vector <vector <int> > mx(m, vector <int>(n));
        vector <vector <int> > sum(m, vector <int>(n));
        rep(i, m) {
            vector <int> q(n);
            int fr = 0, bk = 0;
            rep(j, b) {
                while (fr < bk && A[i][q[bk-1]] < A[i][j]) {
                    bk --;
                }
                q[bk++] = j;
                sum[i][0] += A[i][j];
            }
            mx[i][0] = A[i][q[fr]];
            for (int j = 1; j+b-1 < n; j ++) {
                if (q[fr] == j-1) {
                    fr ++;
                }
                while (fr < bk && A[i][q[bk-1]] < A[i][j+b-1]) {
                    bk --;
                }
                q[bk++] = j+b-1;
                mx[i][j] = A[i][q[fr]];
                sum[i][j] = sum[i][j-1]-A[i][j-1]+A[i][j+b-1];
            }
        }
        int ans = 1<<28;
        rep(j, n-b+1) {
            vector <int> q(m);
            int fr = 0, bk = 0;
            int s = 0;
            rep(i, a) {
                while (fr < bk && mx[q[bk-1]][j] < mx[i][j]) {
                    bk --;
                }
                q[bk++] = i;
                s += sum[i][j];
            }
            ans = min(ans, a*b*mx[q[fr]][j]-s);
            for (int i = 1; i+a-1 < m; i ++) {
                if (q[fr] == i-1) {
                    fr ++;
                }
                while (fr < bk && mx[q[bk-1]][j] < mx[i+a-1][j]) {
                    bk --;
                }
                q[bk++] = i+a-1;
                s = s-sum[i-1][j]+sum[i+a-1][j];
                ans = min(ans, mx[q[fr]][j]*a*b-s);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
