#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

vector <pair <string, string> > D;
string s;
vector <int> lcp;
int dp[10004], n, m;

void make_lcp () {
    lcp = vector <int> (D.size(), 0);
    for (int i = 1; i < int(D.size()); i ++) {
        int l = min(D[i].x.size(), D[i-1].x.size());
        while (lcp[i] < l && D[i].x[lcp[i]] == D[i-1].x[lcp[i]]) {
            lcp[i] ++;
        }
    }
}

string tolower(string a) {
    for (auto &c: a) {
        c = tolower(c);
    }
    return a;
}

int cmp(int a, int b) {
    string p = s.substr(a, D[b].x.size());
    if (p == D[b].x) {
        return 0;
    } else if (p < D[b].x) {
        return -1;
    }
    return 1;
}

int b_search(int i) {
    int low = 0, high = m-1;
    while (low <= high) {
        int mid = (high+low)/2;
        if (cmp(i, mid) > 0) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ((low >= m || cmp(i, low)) ? -1 : low);
}

bool is_prefix(int a, int b) {
    return lcp[b] == int(D[b-1].x.size()) &&
        s.substr(a+lcp[b], int(D[b].x.size())-lcp[b]) == D[b].x.substr(lcp[b]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> m;
    D.resize(m);
    for (auto &w: D) {
        cin >> w.y;
        w.x = tolower(w.y);
        reverse(w.x.begin(), w.x.end());
    }
    sort(D.begin(), D.end());
    make_lcp();
    dp[n] = 0;
    for (int i = n-1; i >= 0; i --) {
        dp[i] = -1;
        for (int j = b_search(i); j >= 0 && j < m && dp[i] == -1; j ++) {
            int t = cmp(i, j);
            if (t < 0) {
                break;
            } else if (t == 0) {
                dp[i] = (dp[i+int(D[j].x.size())] == - 1 ? -1 : j); 
            }
        }
    }
    assert(dp[0] != -1);
    for (int i = 0; i < n; i += D[dp[i]].x.size()) {
        cout << D[dp[i]].y << " ";
    }
    return 0;
}
