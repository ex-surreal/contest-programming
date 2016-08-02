#include <iostream>
#include <cstdio>
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

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int timestamp(string s) {
    int y, m, d, h, i;
    sscanf(s.c_str(), "%d-%d-%d %d:%d", &y, &m, &d, &h, &i);
    y -= 2013;
    m --;
    if (y != 3 || m <= 1) {
        d --;
    }
    return i+h*60+d*24*60+months[m]*24*60+y*365*24*60;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    repi(i, 1, 13) {
        months[i] += months[i-1];
    }
    int tst;
    cin >> tst;
    while (tst --) {
        int n, c;
        cin >> n >> c;
        vector <pair <int, int> > sweep;
        rep(i, n) {
            string p, q;
            cin >> p >> p >> q;
            sweep.pb(mp(timestamp(p+" "+q), +1));
            cin >> p >> q;
            sweep.pb(mp(timestamp(p+" "+q)+c, -1));
        }
        sort(all(sweep));
        int ans = 0, cnt = 0;
        repe(e, sweep) {
            cnt += e.y;
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}
