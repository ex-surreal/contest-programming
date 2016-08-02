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
    int n, m;
    cin >> n >> m;
    vector <int> a(5), b(5);
    rep(i, n) {
        a[(i+1)%5] ++;
    }
    rep(i, m) {
        b[(i+1)%5] ++;
    }
    long long ans = 0;;
    rep(i, 5) {
        rep(j, 5) {
            if ((i+j)%5 == 0) {
                ans += 1ll*a[i]*b[j];
            }
        }
    }
    cout << ans;
    return 0;
}
