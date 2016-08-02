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

int h[1000006];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, s = 0;
    vector <string> op;
    vector <int> a;
    cin >> n;
    rep(i, n) {
        string o;
        int t;
        cin >> o;
        if (o != "removeMin") {
            cin >> t;
            if (o == "insert") {
                op.pb("insert");
                a.pb(t);
                h[s++] = -t;
                push_heap(h, h+s);
            } else {
                while (s > 0 && -h[0] < t) {
                    pop_heap(h, h+s);
                    s --;
                    op.pb("removeMin");
                    a.pb(0);
                }
                if (s == 0 || -h[0] != t) {
                    h[s++] = -t;
                    push_heap(h, h+s);
                    op.pb("insert");
                    a.pb(t);
                }
                op.pb("getMin");
                a.pb(t);
            }
        } else {
            if (s == 0) {
                op.pb("insert");
                a.pb(1);
                h[s++] = -1;
                push_heap(h, h+s);
            } 
            pop_heap(h, h+s);
            s --;
            op.pb("removeMin");
            a.pb(0);
        }
    }
    cout << sz(op) << "\n";
    rep(i, sz(op)) {
        cout << op[i];
        if (op[i] != "removeMin") {
            cout << " " << a[i];
        }
        cout << "\n";
    }
    return 0;
}
