#include <iostream>
#include <vector>

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
    int n;
    cin >> n;
    vector <double> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    double sum = 0, isum = 0;
    rep(i, n) {
        sum += a[i];
        isum += 1.0*i*a[i];
    }
    double J = 1.0*n*(n-1)/6*(2*n-1);
    double P = .5*(n-1);
    double Q = sum/n;
    double L = .5*n*(n-1);
    double d = (isum - L*Q)/(J-P*L);
    double b = Q-P*d;
    cout.precision(10);
    cout.setf(ios::fixed);
    cout << b << " " << d << "\n";
    return 0;
}
