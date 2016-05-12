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

namespace suffix_automaton_array {
    vector <int> len, link;
    vector <vector <int> > next;
    const int alpha = 10;
    
    /**
     * 
     * @return last
     * */
    int init() {
        len.clear();
        link.clear();
        next.clear();
        len.push_back(0);
        link.push_back(-1);
        next.push_back(vector <int>(alpha, -1));
        return 0;
    }

    void add(int c, int &last) {
        int cur = len.size();
        len.push_back(len[last]+1);
        link.push_back(-1);
        next.push_back(vector <int>(alpha, -1));
        int p = last;
        while (p != -1 && next[p][c] == -1) {
            next[p][c] = cur;
            p = link[p];
        }
        if (p == -1) {
            link[cur] = 0;
        } else {
            int q = next[p][c];
            if (len[p]+1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = len.size();
                len.push_back(len[p]+1);
                link.push_back(link[q]);
                next.push_back(next[q]);
                while (p != -1 && next[p][c] == q) {
                    next[p][c] = clone;
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
            add(s[i]-'0', last);
        }
    }
};

using namespace suffix_automaton_array;

int now;

tuple<bool, string> back(int u, int l) {
    if (l == now) {
        return make_tuple(false, "");
    }
    string ret = string(now-l, '9');
    bool f = false;
    repi(c, (l == 0), 10) {
        if (f) {
            break;
        }
        if (suffix_automaton_array::next[u][c] == -1) {
            ret = min(ret, to_string(c)+string(now-l-1, '0'));
            f = true;
        } else {
            bool t;
            string k;
            tie(t, k) = back(suffix_automaton_array::next[u][c], l+1);
            //cout << u << " " << l << " " << k << endl;
            if (t) {
                ret = min(ret, to_string(c)+k);
            }
            f = f || t;
        }
    }
    return make_tuple(f, ret);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string p;
    cin >> p;
    if (p.find("0") == unsigned(-1)) {
        cout << "0\n";
        return 0;
    }
    make(p);
    repi(i, 1, 10000) {
        bool f;
        string q;
        now = i;
        tie(f, q) = back(0, 0);
        if (f) {
            cout << q << "\n";
            return 0;
        }
    }
    return 0;
}
