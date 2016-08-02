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

int main () {
    std::ios_base::sync_with_stdio(false);
    int m, n, l, r;
    while (cin >> m >> n >> l >> r && n) {
        vector <vector <int> > a(m, vector <int>(n));
        rep(i, m) {
            rep(j, n) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        rep(i, n) {
            vector <int> c(m);
            repi(j,i, n) {
                rep(k, m) {
                    c[k] += !a[k][j];
                }
                if (r == 0) {
                    int q = 0, s = 0;
                    rep(p, m) {
                        while (q < m && c[q]+s <= r) {
                            s += c[q];
                            q ++;
                        }
                        ans = max(ans, (j-i+1)*(q-p));
                        if (q == p) {
                            q ++;
                        } else {
                            s -= c[p];
                        }
                    }
                    continue;
                }
                set <pair <int, int> > st;
                rep(k, l) {
                    st.insert(mp(-c[k], k));
                }
                ans = max(ans, (j-i+1)*l);
                int b = st.rbegin()->y;
                int q = l, s = 0, p = 0;
                while (p < m) {
                    int t = (sz(st) < l ? 0 : c[q]);
                    if (mp(-c[q], q) < mp(-c[b], b)) {
                        t = c[b];
                    } 
                    if (s+t <= r) {
                        ans = max(ans, (j-i+1)*(q-p+1));
                        st.insert(mp(-c[q], q));
                        if (mp(-c[q], q) < mp(-c[b], b) && sz(st) > l) {
                            auto it = st.find(mp(-c[b], b));
                            assert(it != st.end() && it != st.begin());
                            it --;
                            b = it->y;
                        } else if (sz(st) <= l) {
                            b = st.rbegin()->y;
                        }
                        q ++;
                    } else {
                        t = (sz(st) == l ? 0 : c[p]);
                        if (mp(-c[p], p) < mp(-c[b], b)) {
                            t = c[b];
                            st.erase(mp(-c[p], p));
                            if (sz(st) > l) {
                                auto it = st.find(mp(-c[b], b));
                                assert(it != st.end());
                                it ++;
                                assert(it != st.end());
                                b = it->y;
                            } else if (sz(st)) {
                                b = st.rbegin()->y;
                            }
                        } else if (sz(st)) {
                            b = st.rbegin()->y;
                        }
                        s -= t;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
