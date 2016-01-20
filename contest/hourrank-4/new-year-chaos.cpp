#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int tree[100005];

int read(int i ) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= i&-i;
    }
    return sum;
}

void update(int i, int v) {
    while (i < 100005) {
        tree[i] += v;
        i += i&-i;
    }
}

int inversion(vector <int> &p) {
    int ans = 0;
    memset(tree, 0, sizeof tree);
    reverse(p.begin(), p.end());
    for (auto a: p) {
        ans += read(a-1);
        update(a, 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        vector <int> p(n);
        for (auto &a: p) {
            cin >> a;
        }
        int ev = 0;
        try {
            for (int i = 0; i < (int) p.size(); i ++) {
                if (p[i] - i - 1 > 2) {
                    throw -1;
                }
                ev += p[i] - i - 1;
            }
            if (ev != 0) {
                throw -1;
            }
            cout << inversion(p) << "\n";
        } catch (int e) {
            cout << "Too chaotic\n";
        }
    }
    return 0;
}
