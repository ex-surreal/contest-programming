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

#include <algorithm>
#include <vector>

namespace suffix_sort {
    const int MAX = 90004;

    class info {
        public:
            int a, b, id;
        info(int a = 0, int b = 0, int id = 0) {
            this->a = a;
            this->b = b;
            this->id = id;
        }
    } A[MAX], tmp[MAX];

    int P[17][MAX];
    int C[MAX], stp;
    std::vector <int> sa;

    void sort_radix(int n, int lim) {
        std::fill(C, C + lim + 2, 0);
        for (int i = 0; i < n; i++) {
            C[A[i].b + 1]++;
        }
        for (int i = 0; i <= lim + 1; i++) {
            C[i + 1] += C[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            tmp[--C[A[i].b + 1]] = A[i];
        }
        std::fill(C, C + lim + 1, 0);
        for (int i = 0; i < n; i++) {
            C[tmp[i].a]++;
        }
        for (int i = 0; i <= lim; i++) {
            C[i + 1] += C[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            A[--C[tmp[i].a]] = tmp[i];
        }
    }

    template <class type> void sort_suffixes(type p) {
        int lim = * max_element(p.begin(), p.end()), n = p.size();
        for (int i = 0; i < n; i++) {
            P[0][i] = p[i];
        }
        for (stp = 1; (1 << (stp - 1)) <= n; stp++) {
            int gap = 1 << (stp - 1);
            for (int i = 0; i < n; i++) {
                if (gap + i < n) A[i] = info(P[stp - 1][i], P[stp - 1][i + gap], i);
                else A[i] = info(P[stp - 1][i], -1, i);
            }
            sort_radix(n, lim);
            P[stp][A[0].id] = lim = 0;
            for (int i = 1; i < n; i++) {
                if (A[i].a == A[i - 1].a && A[i].b == A[i - 1].b) {
                    P[stp][A[i].id] = lim;
                } else {
                    P[stp][A[i].id] = ++lim;
                }
            }
        }
        sa = std::vector <int> (n, -1);
        for (int i = 0; i < n; i++) {
            sa[P[stp - 1][i]] = i;
        }
    }

    int lcp(int x, int y) {
        int ret = 0, n = sa.size();
        for (int k = stp - 1; k >= 0 && x < n && y < n; k--) {
            if (P[k][x] == P[k][y]) {
                ret += (1 << k);
                x += (1 << k);
                y += (1 << k);
            }
        }
        return ret;
    }
}

using namespace suffix_sort;

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    int q;
    cin >> q;
    sort_suffixes(p);
    vector <unsigned> dp(sz(p), 0);
    dp[0] = sz(p) - sa[0];
    repi(i, 1, sz(p)) {
        dp[i] = dp[i-1] + (sz(p)-sa[i]-lcp(sa[i-1], sa[i]));
    }
    rep(i, q) {
        unsigned k;
        cin >> k;
        int high = sz(p)-1, low = 0;
        while (low <= high) {
            int mid = (low+high)>>1;
            if (dp[mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << p.substr(sa[low], sz(p)-sa[low] - (dp[low]-k)) << "\n";
    }
    return 0;
}
