#include <string>
#include <vector>

using namespace std;

vector <int> len, link;
vector <vector <int> > child;
const int alpha = 26, start_char = 'a';

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

void make(string s) {
    int last = init();
    for (int i = 0; i < int(s.size()); i ++) {
        add(s[i]-start_char, last);
    }
}
