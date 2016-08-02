#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>

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

class BearPasswordLexic {
public:
    string findPassword(vector <int> x) {
        string ret = "";
        vector <int> v;
        for (int i = sz(x); i > 0; i --) {
            if (x[i-1] < 0) {
                return "";
            }
            while (x[i-1]) {
                v.pb(i);
                for (int j = i, k = 1; j > 0; j --, k ++) {
                    x[j-1] -= k;
                }
            }
        }
        if (accumulate(all(v), 0) != sz(x)) {
            return "";
        }
        sort(all(v));
        int i = 0, j = sz(v) - 1, now = 0;
        while (i <= j) {
            if (!now) {
                ret += string(v[j], 'a');
                j --;
            } else {
                ret += string(v[i], 'b');
                i ++;
            }
            now ^= 1;
        }
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
			int x[]                   = {5,0,0,0,0};
			string expected__         = "ababa";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {4,2,1,0};
			string expected__         = "aaab";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {3,1,1};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {4,3,2,1};
			string expected__         = "aaaa";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {0};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {4,0,3,2};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int x[]                   = {8, 3, 1, 0, 0, 0, 0, 0};
			string expected__         = "aabbaabab";

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int x[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BearPasswordLexic().findPassword(vector <int>(x, x + (sizeof x / sizeof x[0])));
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
