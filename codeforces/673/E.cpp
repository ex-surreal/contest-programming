#include <bits/stdc++.h>

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

double dp[55][200005];
int O[55][200005];

void compute(int d, int l, int r, int x, int y) {
    if (l == r) {
        O[d][l] = l-1;
        dp[d][l] = 1.0;
        return dp[l];
    }
    
}

int main () {
    std::ios_base::sync_with_stdio(false);
    return 0;
}
