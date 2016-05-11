#include <string>
#include <vector>
#include <map>

using namespace std;

namespace suffix_automaton_array {
    vector <int> len, link;
    vector <vector <int> > next;
    const int alpha = 26;
    
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
            add(s[i]-'a', last);
        }
    }
};

namespace suffix_automaton_map {
    vector <int> len, link;
    vector <map <char, int> > next;
    
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
        next.push_back(map <char, int>());
        return 0;
    }

    void add(char c, int &last) {
        int cur = len.size();
        len.push_back(len[last]+1);
        link.push_back(-1);
        next.push_back(map <char, int>());
        int p = last;
        while (p != -1 && next[p].find(c) == next[p].end()) {
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
            add(s[i], last);
        }
    }
};

int main() {
    string p = "default";
    suffix_automaton_map::make(p);
    suffix_automaton_array::make(p);
    return 0;
}
