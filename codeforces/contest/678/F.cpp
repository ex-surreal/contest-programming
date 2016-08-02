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

class number {
    public:
    long long a, b;
    number(long long a = 0, long long b = 1) {
        this->a = a;
        this->b = b;
    }

    void operator = (long long a) {
        this->a = a;
        this->b = 1;
    }

    number operator + (number n) {
        return number(a*n.b+n.a*b, b*n.b);
    }

    number operator - (number n) {
        return number(a*n.b-n.a*b, b*n.b);
    }

    number operator * (number n) {
        return number(a*n.a, b*n.b);
    }

    number operator / (number n) {
        return number(a*n.b, n.a*b);
    }
};

bool operator < (number a, number b) {
    long long q1 = a.a/a.b, r1 = a.a%a.b;
    long long q2 = b.a/b.b, r2 = b.a%b.b;
    if (q1 == q2) {
        return r1*b.b < r2*a.b;
    }
    return q1 < q2;
}

bool operator > (number a, number b) {
    return b < a;
}

bool operator == (number a, number b) {
    return !(a < b) && !(a > b);
}

bool operator <= (number a, number b) {
    return a < b || a == b;
}

bool operator >= (number a, number b) {
    return a > b || a == b;
}

typedef set <pair <pair <int, int>, int> > line_type;
typedef set <number, int> x_type;

class dynamic_cxhull {
    line_type lines;
    x_type X;
    vector <int> m, c;
    vector <int> id;
    public:
    dynamic_cxhull() {

    }

    void insert(int m1, int c1, int i = -1) {
        m.push_back(m1);
        c.push_back(c1);
        id.push_back(i);

        line_type::iterator l = lines.upper_bound(make_pair(make_pair(m1, c1), 1<<30)), p, q;
        if (l == lines.end()) {
            lines.insert(make_pair(make_pair(m1, c1), i));
        } else {
            q = l;
            while (true) {
                p = q ++;
                if (q == lines.end()) {
                    break;
                }
            }
        }
    }
};

int main () {
    std::ios_base::sync_with_stdio(false);
    return 0;
}
