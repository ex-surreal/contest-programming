#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define x first
#define y second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, v) for (__typeof((v).begin()) i; i != (v).end(); i++)

using namespace std;

class UnrelatedPaths {
public:
    int maxUnrelatedPaths(vector <int> parent) {
        int ret = 0;
		int n = sz(parent) + 1;
		if (n == 0) {
			return 1;
		}
		vector <int> degree(n, 0);
		degree[0] = 1;
		rep(i, n - 1) {
			degree[i+1]++;
			degree[parent[i]]++;
		}
		rep(i, n) {
			ret += int(degree[i] == 1);
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
			int parent[]              = {0, 1, 1, 2, 3};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {0, 0, 1, 1, 2, 2};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {0, 1, 2, 3};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {0,1,1,2,2,2,4,6,5,0,10,5,12,12,10,4,16,12,5,3,20,12,11,21,9,5,1,20,15,24,6,8,15} ;
			int expected__            = 17;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {0,1,1,1,1,0,2,5,1,6,7,10,5,10,8,5,16,14,8,14,4,14,15,21,0,24,11,1,9,18,13,20,6,28,19,28,14,11,38,26,25,10,23,43} ;
			int expected__            = 19;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int parent[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int parent[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int parent[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = UnrelatedPaths().maxUnrelatedPaths(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
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
