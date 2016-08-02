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

tuple<int, int, int> get_max(int x) {
    int a = 1, b = 1, c = 1;
    repi(i, 1, 20) {
        repi(j, i, 20) {
            repi(k, j, 20) {
                if (i*j*k <= x && i*j*k > a*b*c) {
                    tie(a, b, c) = make_tuple(i, j, k);
                }
            }
        }
    }
    return make_tuple(a, b, c);
}

#define nc3(n) ((n)*((n)-1)/2*((n)-2)/3)

int max_nc3(int x) {
    repi(n, 1, x+5) {
        if (nc3(n) > x) {
            return n-1;
        }
    }
    return -1;
}

tuple<int, vector <pair<int, int> > > for_q2(int p) {
    int n = 0;
    vector <pair <int, int> > edge;
    while (p > 0) {
        int t = max_nc3(p);
        rep(i, t) {
            edge.pb(mp(n+1, n+2+i));
        }
        p -= nc3(t);
        n += t+1;
    }
    return make_tuple(n, edge);
}

tuple<int, vector <pair<int, int> > > solve(int p, int q) {
    if (q == 2) {
        return for_q2(p);
    }
    int n = 0, l = 0, st = 0;
    vector <pair <int, int> > edge;
    while (p > 0) {
        if (l == 0) {
            st = n+1;
            int t = 3*q-6;
            n += t;
            rep(i, t) {
                edge.pb(mp(st+i, st+(i-1+t)%t));
            }
        }
        int a[3];
        tie(a[0], a[1], a[2]) = get_max(p);
        p -= a[0]*a[1]*a[2];
        rep(i, 3) {
            int u = st+l + i*(q-2);
            rep(j, a[i]) {
                edge.pb(mp(u, n+1+j));
            }
            n += a[i];
        }
        l ++;
        l %= q-2;
    }
    return make_tuple(n, edge);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int p, q;
    cin >> p >> q;
    int n;
    vector <pair <int, int> > edge;
    tie(n, edge) = solve(p, q);
    cout << n << " " << sz(edge) << "\n";
    repe(e, edge) {
        cout << e.x << " " << e.y << "\n";
    }
    return 0;
}
