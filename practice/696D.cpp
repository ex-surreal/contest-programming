#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
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

#include <vector>
#include <iostream>

using namespace std;

typedef long long elem;
typedef vector <vector <elem> > matrix;

#define one 0
#define zero -1
#define mult(a, b) ((~(a) && ~(b)) ? ((a)+(b)) : zero)
#define add(a, b) max(a, b)

/**
 * @param int n
 * @return aa nxn identity matrix
 * */
matrix get_identity(int n) {
    matrix I(n);
    for (int i = 0; i < n; i ++) {
        I[i].resize(n);
        fill(I[i].begin(), I[i].end(), zero);
        I[i][i] = one;
    }
    return I;
}

/**
 * @param matrix &a
 * @param matrix &b
 * @return matrix a x b
 * This function assumes the multiplication is valid i.e. a[0].size() == b.size() 
 * */
matrix cross(matrix &a, matrix &b) {
    int m = a.size(), n = b.back().size(), t = b.size();
    matrix c(m);
    for (int i = 0; i < m; i ++) {
        c[i].resize(n);
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            c[i][j] = zero;
            for (int k = 0; k < t; k ++) {
                c[i][j] = add(c[i][j], mult(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

/**
 * @param matrix &a
 * @param integral ex
 * @param matrix &p = pow(a, ex)
 * Assumes a is a nxn matrx
 * */
template <class integral> matrix pwr(matrix a, integral ex) {
    int n = a.size();
    matrix r = get_identity(n);
    while (ex > 0) {
        if (ex&1) {
            r = cross(r, a);
        }
        a = cross(a, a);
        ex >>= 1;
    }
    return r;
}

ostream & operator << (ostream &o, matrix a) {
    for (int i = 0; i < int(a.size()); i ++) {
        string sp = "";
        for (int j = 0; j < int(a[i].size()); j ++) {
            cout << sp << a[i][j];
            sp = " ";
        }
        cout << "\n";
    }
    return o;
}

vector <elem> term;
vector <map <char, int> > to;
vector <int> link;

void init() {
    term.clear();
    to.clear();
    link.clear();
    term.push_back(0);
    to.push_back(map <char, int>());
    link.push_back(-1);
}

void add_str(string p, int c) {
    int u = 0;
    for (int i = 0; i < int(p.size()); i ++) {
        if (!to[u].count(p[i])) {
            to[u][p[i]] = link.size();
            term.push_back(0);
            to.push_back(map <char, int>());
            link.push_back(-1);
        }
        u = to[u][p[i]];
    }
    term[u] += c;
}

void push_link() {
    vector <int> Q(link.size());
    int fr = 0, bk = 0;
    Q[bk ++] = 0;
    while (fr < bk) {
        int u = Q[fr ++];
        if (link[u] != -1) {
            term[u] += term[link[u]];
        }
        for (auto x: to[u]) {
            int v = x.second;
            char c = x.first;
            int j = link[u];
            while (j != -1 && !to[j].count(c)) {
                j = link[j];
            }
            link[v] = 0;
            if (j != -1) {
                link[v] = to[j][c];
            }
            Q[bk ++] = v;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    long long l;
    cin >> n >> l;
    vector <int> a(n);
    repe(&e, a) {
        cin >> e;
    }
    init();
    rep(i, n) {
        string p;
        cin >> p;
        add_str(p, a[i]);
    }
    push_link();
    matrix f(sz(link));
    rep(i, sz(link)) {
        f[i].resize(sz(link));
        fill(all(f[i]), zero);
    }
    rep(i, sz(link)) {
        repi(c, 'a', 'z'+1) {
            if (to[i].count(c)) {
                f[to[i][c]][i] = max(f[to[i][c]][i], term[to[i][c]]);
            } else {
                int u = i;
                while (u != -1 && !to[u].count(c)) {
                    u = link[u];
                }
                if (u == -1) {
                    f[0][i] = max(f[0][i], 0ll);
                } else {
                    f[to[u][c]][i] = max(f[to[u][c]][i], term[to[u][c]]);
                }
            }
        }
    }
    f = pwr(f, l);
    matrix k(sz(link), vector <elem>(1, zero));
    k[0][0] = one;
    k = cross(f, k);
    elem ans = 0;
    repe(e, k) {
        ans = max(ans, *e.begin());
    }
    cout << ans;
    return 0;
}
