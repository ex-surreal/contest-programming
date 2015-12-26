#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

class FarmvilleDiv2 {
public:
	int minTime(vector <int> time, vector <int> cost, int budget) {
		int ret = accumulate(time.begin(), time.end(), 0);
        vector <pair <int, int> > arr;
        for (auto i = 0u; i < time.size(); i ++) {
            arr.push_back(make_pair(cost[i], time[i]));
        }
        sort(arr.begin(), arr.end());
        for (auto a: arr) {
            if (budget < a.x) {
                break;
            }
            ret -= min(a.y, budget/a.x);
            budget -= min(a.y, budget/a.x)*a.x;
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
			int time[]                = {100};
			int cost[]                = {1};
			int budget                = 26;
			int expected__            = 74;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int time[]                = {100};
			int cost[]                = {1};
			int budget                = 101;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int time[]                = {2,1};
			int cost[]                = {1,1};
			int budget                = 3;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int time[]                = {1,2,3,4,5};
			int cost[]                = {5,4,3,2,1};
			int budget                = 15;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int time[]                = {100,100,100,100,100,100,100,100,100,100};
			int cost[]                = {2,4,6,8,10,1,3,5,7,9};
			int budget                = 5000;
			int expected__            = 50;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int time[]                = {30,40,20,10};
			int cost[]                = {10,20,30,40};
			int budget                = 5;
			int expected__            = 100;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int time[]                = ;
			int cost[]                = ;
			int budget                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int time[]                = ;
			int cost[]                = ;
			int budget                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int time[]                = ;
			int cost[]                = ;
			int budget                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FarmvilleDiv2().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), budget);
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
