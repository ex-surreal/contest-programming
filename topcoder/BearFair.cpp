#include <iostream>
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

class BearFair {
public:
    string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
        vector <pair <int, int> > p = {mp(0, 0), mp(b, n)};
        rep(i, sz(upTo)) {
            p.push_back(mp(upTo[i], quantity[i]));
        }
        sort(all(p));
        vector <vector <vector <bool> > > dp(sz(p), vector <vector <bool> >(n/2+1, vector <bool>(n/2+1)));
        dp[0][0][0] = true;
        repi(i, 1, sz(p)) {
            int e = p[i].x/2 - p[i-1].x/2;
            int o = (p[i].x+1)/2 - (p[i-1].x+1)/2;
            int c = p[i].y-p[i-1].y;
            rep(j, n/2+1) {
                rep(k, n/2+1) {
                    rep(l, c+1) {
                        int m = c-l;
                        if (l <= j && m <= k && l <= e && m <= o) {
                            dp[i][j][k] = dp[i][j][k] || dp[i-1][j-l][k-m];
                        }
                    }
                }
            }
        }
        return dp[sz(p)-1][n/2][n/2] ? "fair" : "unfair";
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
			int n                     = 4;
			int b                     = 6;
			int upTo[]                = {3,6};
			int quantity[]            = {2,4};
			string expected__         = "fair";

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 4;
			int b                     = 6;
			int upTo[]                = {3,6};
			int quantity[]            = {2,3};
			string expected__         = "unfair";

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 2;
			int b                     = 6;
			int upTo[]                = {1,2,3};
			int quantity[]            = {1,1,2};
			string expected__         = "unfair";

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 50;
			int b                     = 1000;
			int upTo[]                = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248, 186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357};
			int quantity[]            = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
			string expected__         = "fair";

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 4;
			int b                     = 1000;
			int upTo[]                = {400,600};
			int quantity[]            = {4,0};
			string expected__         = "unfair";

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int b                     = ;
			int upTo[]                = ;
			int quantity[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int b                     = ;
			int upTo[]                = ;
			int quantity[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int b                     = ;
			int upTo[]                = ;
			int quantity[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BearFair().isFair(n, b, vector <int>(upTo, upTo + (sizeof upTo / sizeof upTo[0])), vector <int>(quantity, quantity + (sizeof quantity / sizeof quantity[0])));
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
