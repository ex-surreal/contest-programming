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
    stack <int> S;
    S.push(1);
    for (int i= 0; i < n-1; i ++) {
        int cur = 1;
        while (!S.empty() && S.top() == cur) {
            S.pop();
            cur ++;
        }
        S.push(cur);
    }
    vector <int> ans;
    while (!S.empty()) {
        ans.pb(S.top());
        S.pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto a: ans) {
        cout << a << " ";
    }
	return 0;
}
