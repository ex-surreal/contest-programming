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
    std::vector <int> len, link, cnt[3];
    std::vector <std::vector <int> > child;
    const int alpha = 27, start_char = 'a';
    
    /**
     * @return last
     * */
    int init() {
        len.clear();
        cnt[0].clear();
        cnt[1].clear();
        cnt[2].clear();
        link.clear();
        child.clear();
        len.push_back(0);
        cnt[0].push_back(0);
        cnt[1].push_back(0);
        cnt[2].push_back(0);
        link.push_back(-1);
        child.push_back(std::vector <int>(alpha, -1));
        return 0;
    }

    void add(int c, int &last, int f) {
        int cur = len.size();
        len.push_back(len[last]+1);
        cnt[f].push_back(1);
        cnt[(f+1)%3].push_back(0);
        cnt[(f+2)%3].push_back(0);
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
                cnt[0].push_back(0);
                cnt[1].push_back(0);
                cnt[2].push_back(0);
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

int mod = 1e9+7;

vector <int> sort(string p) {
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
    repe(o, ord) {
        if (link[o] != -1) {
            rep(f, 3) {
                cnt[f][link[o]] += cnt[f][o];
            }
        }
    }
    return ord;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string p, q, r;
    cin >> p >> q >> r;
    string g = string(1, 'z'+1);
    vector <int> ord = sort(p+g+q+g+r);
    vector <int> ans(min(sz(p), min(sz(q), sz(r)))+1, 0);
    repe(o, ord) {
        if (link[o] != -1 && len[o] < sz(ans)) {
            ans[len[o]] += 1ll*cnt[0][o]*cnt[1][o]%mod*cnt[2][o]%mod;
            ans[len[o]] %= mod;
            ans[len[link[o]]] -= 1ll*cnt[0][o]*cnt[1][o]%mod*cnt[2][o]%mod;
            ans[len[link[o]]] += mod;
            ans[len[link[o]]] %= mod;
        }
    }
    for (int i = sz(ans)-2; i > 0; i --) {
        ans[i] += ans[i+1];
        ans[i] %= mod;
    }
    rep(i, sz(ans)-1) {
        cout << ans[i+1] << " ";
    }
    return 0;
}
