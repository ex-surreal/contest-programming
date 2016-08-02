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

long long min_t(vector <int> &a) {
    long long high = 300000000000000ll, low = 0;
    while (low <= high) {
        long long mid = (low+high) >> 1;
        long long s = mid;
        bool f = true;
        repe(x, a) {
            s += x;
            if (s < 0) {
                f = false;
                break;
            }
        }
        if (!f) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    repi(cas, 1, tst+1) {
        int n;
        long long g, p, s = 0;
        cin >> n >> g >> p;
        vector <int> a(n);
        repe(&x, a) {
            cin >> x;
        }
        long long t = min_t(a);
        s = t;
        repe(x, a) {
            s += x;
        }
        long long q = p/n;
        if (q*1.0*s > 6*1e18) {
            cout << "Case #" << cas << ": 0\n";
            continue;
        }
        long long low = 0, high = g;
        while (low <= high) {
            long long mid = (low+high) >> 1;
            long long sq, sq1;
            if (mid <= t) {
                if (s == 0) {
                    sq = sq1 = 0;
                } else {
                    long long x = (t+s-1)/s;
                    if (x > q) {
                        sq = s*q;
                    } else {
                        sq = s*x + (q-x)*s - (q-x)*t;
                    }
                    if (x > q-1) {
                        sq1 = s*(q-1);
                    } else {
                        sq1 = s*x + (q-x-1)*s - (q-x-1)*t;
                    }
                }
            } else {
                sq = mid + q*s - q*t;
                sq1 = mid + (q-1)*s - (q-1)*t;
            }
            long long x = 0;
            bool f = mid >= g || sq >= g;
            rep(i, n) {
                x += a[i];
                if (i < p%n) {
                    if (x + sq >= g) {
                        f = true;
                    }
                } else {
                    if (x + sq1 >= g) {
                        f = true;
                    }
                }
            }
            if (!f) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << "Case #" << cas << ": " << low << "\n";
    }
    return 0;
}
