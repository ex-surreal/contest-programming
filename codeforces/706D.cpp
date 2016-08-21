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

vector <int> cnt;
vector <vector <int> > nxt;

void init() {
    cnt.push_back(0);
    nxt.push_back({-1, -1});
}

void add(int s) {
    for (int i = 30, u = 0; i >= 0; i --) {
        int b = (s>>i)&1;
        if (nxt[u][b] == -1) {
            nxt[u][b] = sz(cnt);
            cnt.push_back(0);
            nxt.push_back({-1, -1});
        }
        u = nxt[u][b];
        cnt[u] ++;
    }
}

void remove(int s) {
    for (int i = 30, u = 0; i >= 0; i --) {
        int b = (s>>i)&1;
        u = nxt[u][b];
        cnt[u] --;
    }
}

int get(int t) {
    int ret = 0;
    for (int i = 30, u = 0; i >= 0; i --) {
        int b = (t>>i)&1;
        if (nxt[u][b^1] != -1 && cnt[nxt[u][b^1]]) {
            u = nxt[u][b^1];
            ret |= 1<<i;
        } else {
            u = nxt[u][b];
        }
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    init();
    add(0);
    int q;
    cin >> q;
    rep(i, q) {
        string o;
        int s;
        cin >> o >> s;
        if (o == "+") {
            add(s);
        } else if (o == "-") {
            remove(s);
        } else {
            cout << get(s) << "\n";
        }
    }
    return 0;
}
