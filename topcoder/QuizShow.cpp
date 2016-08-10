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

class QuizShow {
public:
    int wager(vector <int> scores, int wager1, int wager2) {
        int ret(0);
        int prob = 0;
        rep(w, scores[0]+1) {
            int c = 0;
            for (int i = -1; i < 2; i += 2) {
                for (int j = -1; j < 2; j += 2) {
                    for (int k = -1; k < 2; k += 2) {
                        c += int(scores[0]+i*w > scores[1]+j*wager1 && scores[0]+i*w > scores[2]+k*wager2);
                    }
                }
            }
            if (c > prob) {
                ret = w;
                prob = c;
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
			int scores[]              = { 100, 100, 100 };
			int wager1                = 25;
			int wager2                = 75;
			int expected__            = 76;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int scores[]              = { 10, 50, 60 };
			int wager1                = 30;
			int wager2                = 41;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int scores[]              = { 10, 50, 60 };
			int wager1                = 31;
			int wager2                = 41;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int scores[]              = { 2, 2, 12 };
			int wager1                = 0;
			int wager2                = 10;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int scores[]              = { 10000, 10000, 10000 };
			int wager1                = 9998;
			int wager2                = 9997;
			int expected__            = 9999;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int scores[]              = { 5824, 4952, 6230 };
			int wager1                = 364;
			int wager2                = 287;
			int expected__            = 694;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int scores[]              = ;
			int wager1                = ;
			int wager2                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int scores[]              = ;
			int wager1                = ;
			int wager2                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int scores[]              = ;
			int wager1                = ;
			int wager2                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = QuizShow().wager(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])), wager1, wager2);
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
