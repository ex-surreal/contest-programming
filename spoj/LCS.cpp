#include <cstdio>
#include <vector>
#include <map>
#include <string>


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
    const int alpha = 26;
    
    /**
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
            add(s[i]-'a', last);
        }
    }
    
    int lcs(string a, string b) {
        make(a);
        int ans = 0, l = 0, u = 0;
        rep(i, sz(b)) {
            int c = b[i] - 'a';
            while (u > 0 && next[u][c] == -1) {
                u = link[u];
                l = len[u];
            }
            if (next[u][c] != -1) {
                u = next[u][c];
                l ++;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};

using namespace suffix_automaton_array;

char p[250005];
char q[250005];

int main () {
    scanf("%s%s", p, q);
    printf("%d\n", lcs(string(p), string(q)));
    return 0;
}
