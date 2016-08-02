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

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ansX = n/7*2;
    int ansY = n/7*2;
    int r = (n-1)%7+1;
    if (r < 7) {
        ansX += (r > 1 ? 2 : 1);
        ansY += (r == 6);
    } 
    cout << ansY << " " << ansX;
    return 0;
}
