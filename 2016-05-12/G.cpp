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

int kmp(char * p, string q) {
    vector <int> pi(sz(q), 0);
    repi(i, 1, sz(q)) {
        int k = pi[i-1];
        while (k > 0 && q[i] != q[k]) {
            k = pi[k-1];
        }
        pi[i] = k + (q[i] == q[k]);
    }
    for(int i = 0, j = 0; p[i]; i ++) {
        while(j > 0 && q[j] != p[i]) {
            j = pi[j-1];
        }
        if(q[j] == p[i]) {
            j ++;
        }
        if(j == sz(q)) {
            return i - sz(q) + 1;
        }
    }
    return -1;
}

char *s;

int main () {
    std::ios_base::sync_with_stdio(false);
    string p, q;
    getline(cin, p);
    getline(cin, q);
    stringstream sin(q);
    s = new char[sz(p)+1];
    strcpy(s, p.c_str());
    string w;
    int now = 0;
    while (sin >> w) {
        int t = kmp(s, w);
        if (t == -1) {
            cout << "I HAVE FAILED!!!\n";
            return 0;
        } else {
            repi(i, now, now+t) {
                if (p[i] != ' ') {
                    p[i] = '_';
                }
            }
            now += t+sz(w);
            s += t+sz(w);
            if (*s) {
                s[0] = ' ';
            }
        }
    }
    repi(i, now, sz(p)) {
        if (p[i] != ' ') {
            p[i] = '_';
        }
    }
    cout << p << "\n";
    return 0;
}
