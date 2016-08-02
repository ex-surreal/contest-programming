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

class LCMGCD {
    void make(int x, int a[]) {
        a[2] = a[3] = 0;
        while (x > 0) {
            if (x % 2 == 0) {
                a[2] ++;
                x /= 2;
            }
            if (x % 3 == 0) {
                a[3] ++;
                x /= 3;
            }
        }
    }
public:
    string isPossible(vector <int> x, int t) {
        string ret = "Impossible";
        int T[4];
        make(t, T);
        int p[55][4];
        rep(i, x) {
            make(x[i], p[i]);
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
			int x[]                   = {2,3};
			int t                     = 6;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {4,9};
			int t                     = 6;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {6,12,24,18,36,72,54,108,216};
			int t                     = 36;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {6,27,81,729};
			int t                     = 6;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int t                     = 1;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27};
			int t                     = 72;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x[]                   = {100663296, 544195584, 229582512, 59049};
			int t                     = 60466176;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int x[]                   = {2,4,8,16,32,64};
			int t                     = 256;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int x[]                   = ;
			int t                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x[]                   = ;
			int t                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int x[]                   = ;
			int t                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LCMGCD().isPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), t);
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
