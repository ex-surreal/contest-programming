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

int A[200005];
int B[200005];

int read(int *tree, int id) {
    int ret = 0;
    while (id > 0) {
        ret += tree[id];
        id -= id&-id;
    }
    return ret;
}

void update(int *tree, int id, int val) {
    while (id < 200005) {
        tree[id] += val;
        id += id&-id;
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    rep(i, q) {
        int o, d, x;
        cin >> o >> d;
        if (o == 1) {
            cin >> x;
            int ax = read(A, d) - read(A, d-1);
            int bx = read(B, d) - read(B, d-1);
            update(A, d, min(a-ax, x));
            update(B, d, min(b-bx, x));
        } else {
            cout << read(B, d-1) + read(A, n) - read(A, d+k-1) << "\n";
        }
    }
    return 0;
}
