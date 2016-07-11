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

class BiconnectedDiv1 {
public:
    int minimize(vector <int> w1, vector <int> w2) {
        int ret = 0;
        vector <int> dp(sz(w1));
        for (int i = sz(w2) - 2; i > 0; i --) {
            dp[i] = dp[i+1]+w1[i];
            if (i < sz(w2) - 1) {
                dp[i] = max(dp[i], dp[i+2]+w2[i]);
            }
            if (i+1 < sz(w1)-1) {
                dp[i] = max(dp[i], dp[i+2]+w1[i]+w1[i+1]);
            }
        }
        ret = accumulate(all(w1), 0) + accumulate(all(w2), 0) - dp[1];
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
			int w1[]                  = {1,2};
			int w2[]                  = {3};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int w1[]                  = {3,0,4};
			int w2[]                  = {1,2};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int w1[]                  = {3,3,3,3};
			int w2[]                  = {3,6,3};
			int expected__            = 18;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int w1[]                  = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
			int w2[]                  = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
			int expected__            = 46729;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int w1[]                  = ;
			int w2[]                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int w1[]                  = ;
			int w2[]                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int w1[]                  = ;
			int w2[]                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BiconnectedDiv1().minimize(vector <int>(w1, w1 + (sizeof w1 / sizeof w1[0])), vector <int>(w2, w2 + (sizeof w2 / sizeof w2[0])));
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
