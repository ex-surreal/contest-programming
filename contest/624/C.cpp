#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int deg[505];

int main () {
	std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        if (n > 2) {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        if (n == 1) {
            cout << "a";
        } else {
            cout << "ac";
        }
    }
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        deg[x-1] ++;
        deg[y-1] ++;
    }
    int nb = count(deg, deg+n, n-1), db = n-1;
    set <int> st;
    for (int i = 0; i < n; i ++) {
        if (deg[i] == db) {
            continue;
        }
        st.insert(deg[i]);
    }
    if (st.size() > 2u) {
        cout << "No\n";
        return 0;
    }
    int dc = -1, nc = 0;;
    if (st.begin() != st.end()) {
        dc = *st.begin();
        st.erase(st.begin());
        if (count(deg, deg+n, dc) <= nb-1) {
            cout << "No\n";
            return 0;
        }
        nc = dc-nb+1;
        if (nc != count(deg, deg+n, dc)) {
            cout << "No\n";
            return 0;
        }
    }
    int na = 0, da = -1;
    if (st.begin() != st.end()) {
        da = *st.begin();
        if (count(deg, deg+n, da) <= nb-1) {
            cout << "No\n";
            return 0;
        }
        na = da - nb+1;
        if (count(deg, deg+n, da) != na) {
            cout << "No\n";
            return 0;
        }
    }
    if (na+nb+nc != n) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i ++) {
        if (deg[i] == da) {
            cout << 'a';
        } else if (deg[i] == db) {
            cout << 'b';
        } else {
            cout << 'c';
        }
    }
    cout << "\n";
	return 0;
}
