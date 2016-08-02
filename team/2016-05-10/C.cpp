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

vector <long long> cum;

long long solve(int i, int j) {
    if (i >= j) {
        return 0ll;
    }
    int high = j-1, low = i;
    while (low <= high) {
        int mid = (low+high) >> 1;
        if (cum[mid]-cum[i-1] > cum[j]-cum[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (cum[j]-cum[high] - (cum[high]-cum[i-1]) > cum[high+1]-cum[i-1] - (cum[j]-cum[high+1])) {
        high ++;
    }
    return cum[j]-cum[i-1]+solve(i, high)+solve(high+1, j);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int n;
        cin >> n;
        cum.resize(n+1);
        cum[0] = 0;
        repi(i, 1, n+1) {
            cin >> cum[i];
        }
        sort(cum.begin()+1, cum.end());
        repi(i, 1, n+1) {
            cum[i] += cum[i-1];
        }
        cout << solve(1, n) << "\n";
    }
    return 0;
}
