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

class Collision {
public:
    double probability(vector <int> assignments, int ids) {
        double ret(0);
        int n = accumulate(all(assignments), 0), t = ids;
        if (n > ids) {
            return ret;
        }
        double without = 1.0, with = 1.0;
        rep(i, n) {
            without *= (ids-i)*1.0/ids;
        }
        repi(i, 1, sz(assignments)) {
            t -= assignments[i-1];
            rep(j, assignments[i]) {
                with *= 1.0*(t-j)/(ids-j);
            }
        }
        ret = with - without;
        return ret;
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int assignments[]         = {20,20};
			int ids                   = 1000;
			double expected__         = 0.2113618990410422;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int assignments[]         = {123,456};
			int ids                   = 123456;
			double expected__         = 0.3769052883184334;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int assignments[]         = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
			int ids                   = 2147483647;
			double expected__         = 0.0069090268185510555;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int assignments[]         = {1005,1005};
			int ids                   = 1000;
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int assignments[]         = ;
			int ids                   = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int assignments[]         = ;
			int ids                   = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int assignments[]         = ;
			int ids                   = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = Collision().probability(vector <int>(assignments, assignments + (sizeof assignments / sizeof assignments[0])), ids);
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
