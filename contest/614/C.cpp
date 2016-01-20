#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const double pi = acos(-1.0);

typedef pair <int, int> point;

ostream & operator << (ostream &o, pair <int, int> a) {
    o << "(" << a.x << ", " << a.y << ")";
    return o;
}

long long sqdis(point a, point b) {
    return 1ll*(a.x-b.x)*(a.x-b.x) + 1ll*(a.y-b.y)*(a.y-b.y);
}

double dis(point a, point b) {
    return sqrt(1.0*sqdis(a, b));
}

point sub(point a, point b) {
    return make_pair(a.x-b.x, a.y-b.y);
}

long long cross(point a, point b) {
    return 1ll*a.x*b.y - 1ll*a.y*b.x;
}

long long cross(point o, point a, point b) {
    return cross(sub(a, o), sub(b, o));
}

long long dot(point a, point b) {
    return 1ll*a.x*b.x + 1ll*a.y*b.y;
}

long long dot(point o, point a, point b) {
    return dot(sub(a, o), sub(b, o));
}

double get_min_dis(point o, point a, point b) {
    if (dot(a, o, b) < 0 || dot(b, o, a) < 0) {
        return min(sqdis(o, a), sqdis(o, b));
    }
    return 1.0*cross(a, o, b)*cross(a, o, b)/sqdis(a, b);
}

double get_max_dis(point o, point a, point b) {
    return max(sqdis(a, o), sqdis(b, o));
}

int main() {
    int n;
    int a, b;
    cin >> n >> a >> b;
    vector <point> p(n);
    for (auto &x: p) {
        cin >> x.x >> x.y;
    }
    double minDis = 1e15, maxDis = 0;
    for (int i = 0; i < n; i ++) {
        minDis = min(
            get_min_dis(make_pair(a, b), p[i], p[(i+1)%n]),
            minDis
        );
        maxDis = max(
            get_max_dis(make_pair(a, b), p[i], p[(i+1)%n]),
            maxDis
        );
    }
    cout.precision(20);
    cout.setf(ios::fixed);
    cout << pi*(maxDis - minDis) << endl;
    return 0;
}
