#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
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

vector <int> v(10000000);

int main () {
    std::ios_base::sync_with_stdio(false);
    rep(i, sz(v)) {
        v[i] = rand();
    }
    int st = clock();
    /* sort(v.rbegin(), v.rend()); */
    sort(all(v));
    reverse(all(v));
    cerr << (clock()-st)*1.0/CLOCKS_PER_SEC << endl;
    return 0;
}
