#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

#define sq(a) (1ll*(a)*(a))
#define point pair <int, int>

long long dis(point a, point b) {
    return sq(a.x-b.x) + sq(a.y-b.y);
}

point sub(point a, point b) {
    return mp(a.x-b.x, a.y-b.y);
}

long long cross(point a, point b) {
    return 1ll*a.x*b.y - 1ll*a.y*b.x;
}

long long cross(point o, point a, point b) {
    return cross(sub(a, o), sub(b, o));
}

int main () {
	std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <point> p(n);
    for (auto &q: p) {
        cin >> q.x >> q.y;
    }
    int a = 0, b = 1, c = -1;
    for (int i = 1; i < n; i ++) {
        if (dis(p[i], p[a]) < dis(p[a], p[b])) {
            b = i;
        }
    }
    for (int i = 1; i < n; i ++) {
        if (cross(p[a], p[i], p[b]) == 0) {
            continue;
        }
        if (c == -1 || dis(p[b], p[i]) < dis(p[b], p[c])) {
            c = i;
        }
    }
    cout << a+1 << " " << b+1 << " " << c+1;
	return 0;
}
