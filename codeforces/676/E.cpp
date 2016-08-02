#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
    int n, k;
    cin >> n >> k;
    vector <int> a(n+1, 100000);
    int num = 0, q = 0;
    rep(i, n+1) {
        string s;
        cin >> s;
        if (s == "?") {
            q ++;
        } else {
            num ++;
            stringstream sin(s);
            sin >> a[i];
        }
    }
    if (k == 0) {
        if (num&1) {
            if (a[0] == 0 || a[0] == 100000) {
                cout << "Yes";
                return 0;
            }
        } else if (a[0] == 0) {
            cout << "Yes";
            return 0;
        }
        cout << "No";
        return 0;
    }
    if (q != 0) {
        int my = q/2, him = (q+1)/2;
        if (num&1) {
            swap(my, him);
            if (my > him) {
                cout << "Yes";
            } else {
                cout << "No";
            }
            return 0;
        } else {
            if (my >= him) {
                cout << "Yes";
            } else {
                cout << "No";
            }
            return 0;
        }
    } else {
        long long sum = 0;
        for (int i = n; i >= 0; i --) {
            sum = sum*k + a[i];
            if (abs(sum) > 1000000000ll) {
                cout << "No";
                return 0;
            }
        }
        if (sum != 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
