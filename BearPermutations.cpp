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

class BearPermutations {
public:
    int countPermutations(int N, int S, int MOD) {
        int ret;
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
			int N                     = 3;
			int S                     = 1;
			int MOD                   = 71876209;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			int S                     = 0;
			int MOD                   = 1000003;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 4;
			int S                     = 1;
			int MOD                   = 483128897;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int S                     = 3;
			int MOD                   = 907283243;
			int expected__            = 82;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 5;
			int S                     = 100;
			int MOD                   = 101;
			int expected__            = 19;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 20;
			int S                     = 30;
			int MOD                   = 3;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int S                     = ;
			int MOD                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int S                     = ;
			int MOD                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int S                     = ;
			int MOD                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearPermutations().countPermutations(N, S, MOD);
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
