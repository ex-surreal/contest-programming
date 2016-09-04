#include <iostream>
#include <bitset>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>

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
#define EPS 1e-9
#define INF (1<<30)

class DivisibleSetDiv1 {
    int gauss (vector < vector<double> > a) {
        int n = (int) a.size();
        int m = (int) a[0].size() - 1;
        vector<double> ans;
        vector<int> where (m, -1);
        for (int col=0, row=0; col<m && row<n; ++col) {
            int sel = row;
            for (int i=row; i<n; ++i)
                if (abs (a[i][col]) > abs (a[sel][col]))
                    sel = i;
            if (abs (a[sel][col]) < EPS)
                continue;
            for (int i=col; i<=m; ++i)
                swap (a[sel][i], a[row][i]);
            where[col] = row;

            for (int i=0; i<n; ++i)
                if (i != row) {
                    double c = a[i][col] / a[row][col];
                    for (int j=col; j<=m; ++j)
                        a[i][j] -= a[row][j] * c;
                }
            ++row;
        }

        ans.assign (m, 0);
        for (int i=0; i<m; ++i)
            if (where[i] != -1)
                ans[i] = a[where[i]][m] / a[where[i]][i];
        for (int i=0; i<n; ++i) {
            double sum = 0;
            for (int j=0; j<m; ++j)
                sum += ans[j] * a[i][j];
            if (abs (sum - a[i][m]) > EPS)
                return 0;
        }

        for (int i=0; i<m; ++i)
            if (where[i] == -1)
                return INF;
        return 1;
    }
    public:
    string isPossible(vector <int> b) {
        vector <vector <double> > a(sz(b), vector <double> (sz(b)+1, -1.0));
        rep(i, sz(b)) {
            a[i].back() = 0;
        }
        rep(i, sz(b)) {
            a[i][i] = b[i];
        }
        string ret = (gauss(a) == 0 ? "Impossible": "Possible");
        return ret;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
    using std::string;
    using std::vector;
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum != -1) {
            if (run_test_case(casenum) == -1 && !quiet) {
                std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
            }
            return;
        }

        int correct = 0, total = 0;
        for (int i=0;; ++i) {
            int x = run_test_case(i);
            if (x == -1) {
                if (i >= 100) break;
                continue;
            }
            correct += x;
            ++total;
        }

        if (total == 0) {
            std::cerr << "No test cases run." << std::endl;
        } else if (correct < total) {
            std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
        } else {
            std::cerr << "All " << total << " tests passed!" << std::endl;
        }
    }

    int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
        std::cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (expected == received) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }

        std::cerr << verdict;
        if (!info.empty()) {
            std::cerr << " (";
            for (size_t i=0; i<info.size(); ++i) {
                if (i > 0) std::cerr << ", ";
                std::cerr << info[i];
            }
            std::cerr << ")";
        }
        std::cerr << std::endl;

        if (verdict == "FAILED") {
            std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
            std::cerr << "    Received: \"" << received << "\"" << std::endl; 
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum__) {
        switch (casenum__) {
            case 0: {
                        int b[]                   = {2,1};
                        string expected__         = "Possible";

                        std::clock_t start__      = std::clock();
                        string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int b[]                   = {1,1};
                        string expected__         = "Impossible";

                        std::clock_t start__      = std::clock();
                        string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int b[]                   = {7, 7, 7};
                        string expected__         = "Possible";

                        std::clock_t start__      = std::clock();
                        string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int b[]                   = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
                        string expected__         = "Impossible";

                        std::clock_t start__      = std::clock();
                        string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int b[]                   = ;
                            string expected__         = ;

                            std::clock_t start__      = std::clock();
                            string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int b[]                   = ;
                            string expected__         = ;

                            std::clock_t start__      = std::clock();
                            string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int b[]                   = ;
                            string expected__         = ;

                            std::clock_t start__      = std::clock();
                            string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
            default:
                    return -1;
        }
    }
}


#include <cstdlib>
int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(std::atoi(argv[i]));
    }
}
// END CUT HERE
