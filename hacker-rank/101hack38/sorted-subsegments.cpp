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

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, q, k;
    cin >> n >> q >> k;
    vector <int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector <pair <int, int> > p(q);
    rep(i, q) {
        cin >> p[i].x >> p[i].y;
    }
    sort(all(p));
    int l = -1, r = -1;
    priority_queue <int> Q;
    rep(i, q) {
        if (p[i].x > r) {
            while (!Q.empty()) {
                a[l++] = -Q.top();
                Q.pop();
            }
            l = p[i].x, r = p[i].y;
            repi(j, l, r+1) {
                Q.push(-a[j]);
            }
        } else {
            while (l < p[i].x) {
                a[l++] = -Q.top();
                Q.pop();
            }
            while (r < p[i].y) {
                Q.push(-a[++r]);
            }
        }
        int j = i;
        while (j < q && p[j].y <= r) {
            j ++;
        }
        i = j-1;
    }
    while (!Q.empty()) {
        a[l++] = -Q.top();
        Q.pop();
    }
    cout << a[k] << "\n";
    return 0;
}
