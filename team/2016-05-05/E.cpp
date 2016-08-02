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

tuple <int, int> solve(int a, int b) {
    if (a == 1 && b == 1) {
        return make_tuple(0, 0);
    }
    if (a > b) {
        int x, y;
        tie(x, y) = solve(a-b, b);
        return make_tuple(((x+1)<<1)-1, (y<<1)|1);
    } else {
        int x, y;
        tie(x, y) = solve(a, b-a);
        return make_tuple(((x+1)<<1)-1, y<<1);
    }
}

int main () {
    int tst;
    scanf("%d", &tst);
    while (tst --) {
        int cas, a, b;
        scanf("%d %d/%d", &cas, &a, &b);
        int x, y;
        tie(x, y) = solve(a, b);
        printf("%d %d\n", cas, x+y+1);
    }
    return 0;
}
