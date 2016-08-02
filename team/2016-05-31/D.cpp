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

const double pi = acos(-1.0);

double vol(double x, double r) {
    return pi*(r*x*x - x*x*x/3);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);
    int n, s;
    while (cin >> n >> s) {
        double V = 1e15;
        vector <double> x(n), y(n), z(n), r(n);
        rep(i, n) {
            cin >> r[i] >> x[i] >> y[i] >> z[i];
            V -= 2*vol(r[i], r[i]);
        }
        double slice = V / s;
        double last = 0, last_vol = 0;
        rep(k, s) {
            double high = 100000, low = last, now_vol = 0;
            rep(j, 40) {
                double mid = (high+low)/2;
                double v = 1e10*mid;
                rep(i, n) {
                    if (z[i]+r[i] <= mid) {
                        v -= 2*vol(r[i], r[i]);
                    } else if (mid >= z[i]) {
                        v -= 2*vol(r[i], r[i]) - vol(z[i]+r[i]-mid, r[i]);
                    } else if (mid >= z[i]-r[i]) {
                        v -= vol(mid-z[i]+r[i], r[i]);
                    }
                }
                if (v - last_vol > slice) {
                    high = mid;
                } else {
                    now_vol = v;
                    low = mid;
                }
            }
            cout << (low-last)/1000 << "\n";
            last = low;
            last_vol = now_vol;
        }
    }
    return 0;
}
