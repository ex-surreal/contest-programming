#include <iostream>

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
    if (n > 0) {
        cout << 1ll*n*(n+1)/2 << "\n";
    } else if (n < 0) {
        n = -n;
        cout << -1ll*n*(n+1)/2+1 << "\n";
    } else {
        cout << "1\n";
    }
    return 0;
}
