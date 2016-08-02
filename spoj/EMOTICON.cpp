#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
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

vector <bool> term;
vector <map <char, int> > to;
vector <int> link;

void init() {
    term.clear();
    to.clear();
    link.clear();
    term.push_back(false);
    to.push_back(map <char, int>());
    link.push_back(-1);
}

void add_str(string p) {
    int u = 0;
    for (int i = 0; i < int(p.size()); i ++) {
        if (!to[u].count(p[i])) {
            to[u][p[i]] = link.size();
            term.push_back(false);
            to.push_back(map <char, int>());
            link.push_back(-1);
        }
        u = to[u][p[i]];
    }
    term[u] = u;
}

void push_link() {
    vector <int> Q(link.size());
    int fr = 0, bk = 0;
    Q[bk ++] = 0;
    while (fr < bk) {
        int u = Q[fr ++];
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

int dp[2][8008];
char buff[100];

int main () {
    ios_base::sync_with_stdio(false);
    while (true) {
        int n, m;
        cin.getline(buff, sizeof buff);
        stringstream sin(buff);
        sin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }
        init();
        rep(i, n) {
            cin.getline(buff, sizeof buff);
            add_str(string(buff));
        }
        push_link();
        string p = "", sp = "";
        rep(i, m) {
            cin.getline(buff, sizeof buff);
            p += sp + string(buff);
            sp = " ";
        }
        mem(dp, 0);
        int now = 0, pre = 1;
        for (int i = sz(p)-1; i >= 0; i --) {
            swap(now, pre);
            rep(j, sz(link)) {
                dp[now][j] = dp[pre][0] + 1;
                if (!to[j].count(p[i])) {
                    dp[now][j] = min(dp[now][j], dp[pre][0]);
                    continue;
                }
                if (to[j].count(p[i]) && !term[to[j][p[i]]]) {
                    dp[now][j] = min(dp[now][j], dp[pre][to[j][p[i]]]);
                }
            }
        }
        cout << dp[now][0] << "\n";
    }
    return 0;
}
