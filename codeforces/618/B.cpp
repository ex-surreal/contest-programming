#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int main () {
	std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <vector <int> > adj(n, vector <int>(n, 0));
    for (auto &row: adj) {
        for (auto &elem: row) {
            cin >> elem;
        }
    }
    vector <int> ans(n, -1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < sz(adj); j ++) {
            if (sz(adj[j]) == 0) {
                continue;
            }
            if (*max_element(adj[j].begin(), adj[j].end()) <= i) {
                ans[j] = i;
                adj[j].clear();
                break;
            }
        } 
    }
    for (auto &a: ans) {
        cout << a << " ";
    }
	return 0;
}
