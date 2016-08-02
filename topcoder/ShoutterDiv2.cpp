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

#define in(a, b, c) ((a) <= (b) && (b) <= (c))

class ShoutterDiv2 {
public:
    int count(vector <int> s, vector <int> t) {
        int ret = 0;
        for (int i = 0; i < sz(s); i ++) {
            for (int j = 0; j < i; j ++) {
                if (in(s[i], s[j], t[i]) || in(s[i], t[j], t[i]) || in(s[j], s[i], t[j]) || in(s[j], t[i], t[j])) {
                    ret ++;
                }
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
			int s[]                   = {1, 2, 4};
			int t[]                   = {3, 4, 6};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int s[]                   = {0};
			int t[]                   = {100};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int s[]                   = {0,0,0};
			int t[]                   = {1,1,1};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int s[]                   = {9,26,8,35,3,58,91,24,10,26,22,18,15,12,15,27,15,60,76,19,12,16,37,35,25,4,22,47,65,3,2,23,26,33,7,11,34,74,67,32,15,45,20,53,60,25,74,13,44,51};
			int t[]                   = {26,62,80,80,52,83,100,71,20,73,23,32,80,37,34,55,51,86,97,89,17,81,74,94,79,85,77,97,87,8,70,46,58,70,97,35,80,76,82,80,19,56,65,62,80,49,79,28,75,78};
			int expected__            = 830;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int s[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int s[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int s[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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
