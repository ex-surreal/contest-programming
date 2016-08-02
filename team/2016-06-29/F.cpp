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

int merge(int a, int b, int c, vector <int> &v, vector <int> &t) {
    int i = a, j = b + 1, k = a;
    int ret = 0;
    while (i <= b && j <= c) {
        if (v[i] > v[j]) {
            ret += b-i+1;
            t[k++] = v[j++];
        } else {
            t[k++] = v[i++];
        }
    }
    while (i <= b) {
        t[k++] = v[i++];
    }
    while (j <= c) {
        t[k++] = v[j++];
    }
    repi(i, a, c+1) {
        v[i] = t[i];
    }
    return ret;
}

int merge_sort(int i, int j, vector <int> &v, vector <int> &t) {
    if (j <= i) {
        return 0;
    }
    int ret = merge_sort(i, (i+j)/2, v, t) + merge_sort((i+j)/2+1, j, v, t);
    ret += merge(i, (i+j)/2, j, v, t);
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int n;
        cin >> n;
        map <string, int> id;
        rep(i, n) {
            string p;
            cin >> p;
            id[p] = i;
        }
        vector <int> v(n), t(n);
        rep(i, n) {
            string p;
            cin >> p;
            v[i] = id[p];
        }
        cout << merge_sort(0, n-1, v, t) << "\n";
    }
    return 0;
}
