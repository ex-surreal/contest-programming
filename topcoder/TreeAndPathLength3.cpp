#include <vector>
#include <cmath>

using namespace std;

class TreeAndPathLength3 {
public:
    vector <int> construct(int s) {
        int x = sqrt(s);
        vector <int> ret;
        for (int i = 1; i <= x; i ++) {
            ret.push_back(0);
            ret.push_back(i);
            ret.push_back(i);
            ret.push_back(x+i);
        }
        int now = 2*x + 1;
        ret.push_back(0); 
        ret.push_back(now);
        int rem = s - x*x;
        while (rem > 0) {
            ret.push_back(2*x);
            ret.push_back(++now);
            rem --;
        }
        return ret;
    }
};

#include <iostream>

int main () {
    TreeAndPathLength3 obj;
    int n;
    cin >> n;
    vector <int> ans = obj.construct(n);
    for (auto x: ans) {
        cout << x << " ";
    } cout << endl;
    return 0;
}
