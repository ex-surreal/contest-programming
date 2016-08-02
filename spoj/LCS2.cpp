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
    int len[2000006], link[2000006], cnt[2000006];
    int child[2000006][27];
    int state_count;
    const int alpha = 27, start_char = 'a';
    
    /**
     * @return last
     * */
    int init() {
        state_count = 0;
        len[state_count] = 0;
        cnt[state_count] = 0;
        link[state_count] = -1;
        state_count ++;
        return 0;
    }

    void add(int c, int &last, int f) {
        int cur = state_count;
        len[state_count] = len[last]+1;
        cnt[state_count] = 1<<f;
        link[state_count] = -1;
        state_count ++;
        int p = last;
        while (p != -1 && child[p][c] == 0) {
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
                int clone = state_count;
                len[state_count] = len[p]+1;
                cnt[state_count] = 0;
                link[state_count] = link[q];
                rep(k, alpha) {
                    child[state_count][k] = child[q][k];
                }
                state_count ++;
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
        int last = init(), c = 0;
        for (int i = 0; i < int(s.size()); i ++) {
            c += int(s[i] == 'z'+1);
            add(s[i]-start_char, last, c);
        }
    }
}

using namespace suffix_automaton_array;

int main () {
    std::ios_base::sync_with_stdio(false);
    string p, q;
    cin >> p;
    int t = 1;
    while (cin >> q) {
        t ++;
        p += string(1, 'z'+1) + q;
    }
    make(p);
    vector <int> C(sz(p)+1), ord(state_count);
    rep(i, state_count) {
        C[len[i]] ++;
    }
    for (int i = sz(C)-2; i >= 0; i --) {
        C[i] += C[i+1];
    }
    for (int i = state_count-1; i >= 0; i --) {
        ord[--C[len[i]]] = i;
    }
    int ans = 0;
    repe(o, ord) {
        if (link[o] != -1) {
            cnt[link[o]] |= cnt[o];
            if ((1<<t)-1 == cnt[o]) {
                ans = max(ans, len[o]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
