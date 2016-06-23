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
    vector <int> gen(2, 1);
    repi(i, 2, 1000000) {
        if (i&1) {
            gen.pb(gen[i/2]*gen[i/2+1] + 2);
        } else {
            gen.pb(gen[i/2]*gen[i/2] + 1);
        }
        if (gen[i] >= 1000000000) {
            break;
        }
    }
    int tst, cas = 0;
    cin >> tst;
    while (tst --) {
        int f;
        cin >> f;
        repi(i, 1, sz(gen)) {
            if (gen[i] == f) {
                cout << "Case " << ++cas << ": " << i << "\n";
                break;
            }
        }
    }
    return 0;
}
