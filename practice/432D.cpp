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

#include <string>
#include <vector>
#include <map>

using namespace std;

namespace suffix_automaton_array {
    vector <int> len, link;
    vector <vector <int> > child;
    const int alpha = 26;
    
    /**
     * @return last
     * */
    int init() {
        len.clear();
        link.clear();
        child.clear();
        len.push_back(0);
        link.push_back(-1);
        child.push_back(vector <int>(alpha, -1));
        return 0;
    }

    void add(int c, int &last) {
        int cur = len.size();
        len.push_back(len[last]+1);
        link.push_back(-1);
        child.push_back(vector <int>(alpha, -1));
        int p = last;
        while (p != -1 && child[p][c] == -1) {
            child[p][c] = cur;
            p = link[p];
        }
        if (p == -1) {
            link[cur] = 0;
        } else {
            int q = child[p][c];
            if (len[p]+1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = len.size();
                len.push_back(len[p]+1);
                link.push_back(link[q]);
                child.push_back(child[q]);
                while (p != -1 && child[p][c] == q) {
                    child[p][c] = clone;
                    p = link[p];
                }
                link[cur] = link[q] = clone;
            }
        }
        last = cur;
    }

    void make(string &s) {
        int last = init();
        for (int i = 0; i < int(s.size()); i ++) {
            add(s[i]-'A', last);
        }
    }
};

using namespace suffix_automaton_array;

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    make(p);
    vector <bool> ter(sz(len), false);
    for (int u = sz(len)-1; u != 0; u = link[u]) {
        ter[u] = true;
    }
    vector <int> cnt(sz(p)+1, 0);
    repe(l, len) {
        cnt[l] ++;
    }
    for (int i = sz(cnt)-1; i >= 0; i --) {
        cnt[i] += cnt[i+1];
    }
    vector <int> ord(sz(len));
    for (int i = sz(len)-1; i > 0; i --) {
        ord[--cnt[len[i]]] = i;
    }
    vector <int> dp(sz(len), 1);
    repe(o, ord) {
        dp[link[o]] += dp[o];
    }
    int u = 0;
    rep(i, sz(p)) {
        u = child[u][p[i]-'A'];
        if (ter[u]) {
            cout << i+1 << " " << dp[u] << "\n";
        }
    }
    return 0;
}
