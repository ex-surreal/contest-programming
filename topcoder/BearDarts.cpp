#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

class BearDarts {
public:
	long long count(vector <int> w) {
		long long ret = 0;
		map <pair <int, int>, int> cnt;
		for (int i = 0; i < int(w.size()); i ++) {
			for (int j = i+1; j < int(w.size()); j ++) {
				int g = __gcd(w[i], w[j]);
				ret += cnt[make_pair(w[i]/g, w[j]/g)];
			}
			for (int j = 0; j < int(i); j ++) {
				int g = __gcd(w[i], w[j]);
				cnt[make_pair(w[i]/g, w[j]/g)] ++;
			}
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int w[]                   = {6,8,4,3,6};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int w[]                   = {3,4,12,1};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int w[]                   = {42,1000000,1000000,42,1000000,1000000};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int w[]                   = {1,1,1,1,1};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int w[]                   = {1,2,3,4,5,6,5,4,3,2,1};
			long long expected__      = 22;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int w[]                   = {33554432, 33554432, 67108864, 134217728};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int w[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int w[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int w[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BearDarts().count(vector <int>(w, w + (sizeof w / sizeof w[0])));
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
