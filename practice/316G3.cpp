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
    std::vector <int> len, link, cnt[11];
    std::vector <std::vector <int> > child;
    const int alpha = 27, start_char = 'a';
    
    /**
     * @return last
     * */
    int init() {
        len.clear();
        link.clear();
        child.clear();
        len.push_back(0);
        link.push_back(-1);
        rep(i, 11) {
            cnt[i].pb(0);
        }
        child.push_back(std::vector <int>(alpha, -1));
        return 0;
    }

    void add(int c, int &last, int f) {
        int cur = len.size();
        len.push_back(len[last]+1);
        rep(i, 11) {
            cnt[i].pb(f == i);
        }
        link.push_back(-1);
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
                rep(i, 11) {
                    cnt[i].pb(0);
                }
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
        for (int i = 0, c = 0; i < int(s.size()); i ++) {
            c += int(s[i] == 'z'+1);
            add(s[i]-start_char, last, c);
        }
    }
}

using namespace suffix_automaton_array;

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    int n;
    cin >> n;
    vector <int> l(n), r(n);
    rep(i, n) {
        string q;
        cin >> q >> l[i] >> r[i];
        p += string(1, 'z'+1)+q;
    }
    make(p);
    vector <int> C(sz(p)+1), ord(sz(len));
    repe(l, len) {
        C[l] ++;
    }
    for (int i = sz(C)-2; i >= 0; i --) {
        C[i] += C[i+1];
    }
    for (int i = sz(len)-1; i >= 0; i --) {
        ord[--C[len[i]]] = i;
    }
    long long ans = 0;
    repe(o, ord) {
        if (link[o] != -1) {
            bool flag = true;
            rep(i, n) {
                if (cnt[0][o] == 0) {
                    flag = false;
                    break;
                }
                if (!(l[i] <= cnt[i+1][o] && cnt[i+1][o] <= r[i])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans += len[o] - len[link[o]];
            }
            rep(i, n+1) {
                cnt[i][link[o]] += cnt[i][o];
            }
        }
    }
    cout << ans;
    return 0;
}
