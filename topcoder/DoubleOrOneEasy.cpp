#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

class DoubleOrOneEasy {
public:
	int minimalSteps(int a, int b, int newA, int newB) {
		int ret = INT_MAX;
        if (a > b) {
            swap(a, b);
            swap(newA, newB);
        }
        for (int i = 0; i <= 30 && (a*(1ll<<i)) <= newA; i ++) {
            if (1ll*(b-a)*(1<<i) == newB-newA) {
                int x = newA - a*(1<<i);
                int c = i, j = i;
                while (j >= 0) {
                    c += x/(1<<j);
                    x -= (x/(1<<j))*(1<<j);
                    j --;
                }
                ret = min(ret, c);
            }
        }
        if (ret == INT_MAX) {
            ret = -1;
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int a                     = 100;
			int b                     = 1000;
			int newA                  = 101;
			int newB                  = 1001;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 100;
			int b                     = 1000;
			int newA                  = 202;
			int newB                  = 2002;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 2;
			int b                     = 2;
			int newA                  = 1;
			int newB                  = 1;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 1;
			int b                     = 111111111;
			int newA                  = 8;
			int newB                  = 888888888;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 1;
			int b                     = 111111111;
			int newA                  = 9;
			int newB                  = 999999999;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int a                     = 1;
			int b                     = 20;
			int newA                  = 16;
			int newB                  = 92;
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int a                     = 1;
			int b                     = 27;
			int newA                  = 19;
			int newB                  = 123;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			int a                     = 1;
			int b                     = 20;
			int newA                  = 16;
			int newB                  = 35;
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = DoubleOrOneEasy().minimalSteps(a, b, newA, newB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
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
