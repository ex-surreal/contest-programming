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

namespace suffix_automaton_array {
    std::vector <int> len, link, pos;
    std::vector <std::vector <int> > child;
    const int alpha = 26, start_char = 'A';
    
    /**
     * @return last
     * */
    int init() {
        len.clear();
        link.clear();
        child.clear();
        pos.clear();
        len.push_back(0);
        pos.push_back(-1);
        link.push_back(-1);
        child.push_back(std::vector <int>(alpha, -1));
        return 0;
    }

    void add(int c, int &last, int z) {
        int cur = len.size();
        len.push_back(len[last]+1);
        link.push_back(-1);
        pos.push_back(z);
        child.push_back(std::vector <int>(alpha, -1));
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
                pos.push_back(pos[q]);
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

    void make(std::string s) {
        int last = init();
        for (int i = 0; i < int(s.size()); i ++) {
            add(s[i]-start_char, last, i);
        }
    }
}

using namespace suffix_automaton_array;

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    make(p);
    int n;
    cin >> n;
    vector <string> s(n);
    repe(&x, s) {
        cin >> x;
    }
    vector <vector <int> > C(n);
    rep(i, n) {
        C[i] = vector <int>(sz(s[i]), sz(p));
        for (int j = 0, u = 0; j < sz(s[i]); j ++) {
            u = child[u][s[i][j] - 'A'];
            if (u == -1) {
                break;
            }
            C[i][j] = pos[u];
        }
    }
    reverse(all(p));
    make(p);
    int ans = 0;
    rep(i, n) {
        for (int j = sz(s[i])-1, u = 0; j > 0; j --) {
            u = child[u][s[i][j] - 'A'];
            if (u == -1) {
                break;
            }
            if (C[i][j-1] < sz(p)-pos[u]-1) {
                ans ++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
