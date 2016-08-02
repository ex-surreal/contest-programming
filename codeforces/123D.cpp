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
    std::vector <int> len, link, cnt;
    std::vector <std::vector <int> > child;
    const int alpha = 26, start_char = 'a';
    
    /**
     * @return last
     * */
    int init() {
        len.clear();
        cnt.clear();
        link.clear();
        child.clear();
        len.push_back(0);
        cnt.push_back(0);
        link.push_back(-1);
        child.push_back(std::vector <int>(alpha, -1));
        return 0;
    }

    void add(int c, int &last) {
        int cur = len.size();
        len.push_back(len[last]+1);
        cnt.push_back(1);
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
                cnt.push_back(0);
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
            add(s[i]-start_char, last);
        }
    }
}

using namespace suffix_automaton_array;

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
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
            cnt[link[o]] += cnt[o];
            ans += 1ll*cnt[o]*(cnt[o]+1)/2*(len[o]-len[link[o]]);
        }
    }
    cout << ans;
    return 0;
}
