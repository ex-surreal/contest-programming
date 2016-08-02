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

#define sum(a, b) (cum[b] - cum[(a)-1])

vector <int> cum;
int n, a, b;

int _bsearch(int low, int high, int T) {
    while (low <= high) {
        int mid = (low+high) / 2;
        int t = sum(mid, n) + (n-mid+1)*(a+1);
        if (t > T) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return n-low+1;
}

int bsearch(int low, int high, int T) {
    while (low <= high) {
        int mid = (low+high) / 2;
        int t = sum(2, mid) + (mid-1)*(a+1);
        if (t > T) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high - 1;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> n >> a >> b >> T;
    string str;
    cin >> str;
    cum = vector <int> (n+1, 0);
    rep(i, n) {
        cum[i+1] = (str[i] == 'w' ? b : 0) + cum[i];
    }
    int ans = 0;
    repi(i, 1, n+1) {
        int t = i + (i-1)*a*2 + sum(1, i);
        if (t > T) {
            break;
        }
        int r = _bsearch(i+1, n, T-t);
        ans = max(i+r, ans);
    }
    repi(i, 1, n+1) {
        int t = sum(1, i) + i + (i-1)*a;
        if (t <= T) {
            ans = max(ans, i);
        } else {
            break;
        }
    }
    for (int i = n; i > 1; i --) {
        int t = (n-i+2) + 2*(n-i+1)*a + sum(i, n) + sum(1, 1);
        if (t > T) {
            break;
        }
        int r = bsearch(2, i-1, T-t);
        ans = max((n-i+2)+r, ans);
    }
    cout << ans;
    return 0;
}
