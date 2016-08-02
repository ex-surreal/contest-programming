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

vector <vector <int> > adj;
vector <double> ans;
vector <int> cnt;

void dfs(int u) {
    repe(v, adj[u]) {
        ans[v] = ans[u]+1+ 0.5*(cnt[u]-cnt[v]-1);
        dfs(v);
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> parent(n);
    cnt.resize(n);
    ans.resize(n);
    adj.resize(n);
    repi(i, 1, n) {
        cin >> parent[i];
        parent[i] --;
        adj[parent[i]].pb(i);
    }
    for (int i = n-1; i > 0; i --) {
        cnt[i] ++;
        cnt[parent[i]] += cnt[i];
    }
    cnt[0] ++;
    ans[0] = 1;
    dfs(0);
    cout.precision(10);
    cout.setf(ios::fixed);
    repe(a, ans) {
        cout << a << " ";
    }
    return 0;
}
