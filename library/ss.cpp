#include <algorithm>
#include <vector>

namespace suffix_sort {
    const int MAX = 5000005;

    class info {
        public:
            int a, b, id;
        info(int a = 0, int b = 0, int id = 0) {
            this->a = a;
            this->b = b;
            this->id = id;
        }
    } A[MAX], tmp[MAX];

    int P[24][MAX];
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
        for (stp = 1;
            (1 << (stp - 1)) <= n; stp++) {
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
