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
    int n, m, p;
    cin >> n >> m >> p;
    string s;
    cin >> s;
    stack <int> S;
    vector <int> oposit(n+1, -1);
    rep(i, n) {
        if (s[i] == '(') {
            S.push(i+1);
        } else {
            oposit[S.top()] = i+1;
            oposit[i+1] = S.top();
            S.pop();
        }
    }
    set <int> st;
    repi(i, 1, n+1) {
        st.insert(i);
    }
    auto it = st.find(p);
    string o;
    cin >> o;
    repe(c, o) {
        if (c == 'R') {
            it ++;
        } else if (c == 'L') {
            it --;
        } else {
            int x, y;
            tie(x, y) = make_tuple(min(oposit[*it], *it), max(oposit[*it], *it));
            auto t = st.find(y);
            t ++;
            int k;
            if (t != st.end()) {
                k = *t;
            } else {
                t = st.find(x);
                t --;
                k = *t;
            }
            for (auto t = st.find(x); t != st.end() && *t <= y;) {
                auto cur = t++;
                st.erase(cur);
            }
            it = st.find(k);            
        }
    }
    repe(i, st) {
        cout << s[i-1];
    }
    return 0;
}
