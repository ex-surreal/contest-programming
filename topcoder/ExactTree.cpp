#include <iostream>
#include <cstdlib>
#include <ctime>
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
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define rep(i, n) for (int i=0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

class ExactTree {
public:
	int getTree(int n, int m, int r) {
        vector <vector <int> > f(n+1, vector <int>(m));
        vector <vector <int> > g(n+1, vector <int>(m));
        repi(r, 1, m) {
            f[0][r] = g[0][r] = 1<<29;
        }
        repi(t, 1, n+1) {
            rep(r, m) {
                int x = t*(n-t);
                f[t][r] = x+g[t-1][(r-x%m+m)%m];
                g[t][r] = 1<<29;
                repi(j, 1, t+1) {
                    rep(r1, m) {
                        g[t][r] = min(g[t][r], f[j][r1] + g[t-j][(r-r1+m)%m]);
                    }
                }
            }
        }
		return f[n][r] == (1<<29) ? -1 : f[n][r];
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
			int n                     = 4;
			int m                     = 100;
			int r                     = 9;
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 4;
			int m                     = 100;
			int r                     = 10;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 4;
			int m                     = 100;
			int r                     = 0;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 6;
			int m                     = 2;
			int r                     = 0;
			int expected__            = 28;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 6;
			int m                     = 2;
			int r                     = 1;
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 25;
			int m                     = 100;
			int r                     = 0;
			int expected__            = 700;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int n                     = 50;
			int m                     = 97;
			int r                     = 89;
			int expected__            = 2708;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int m                     = ;
			int r                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int m                     = ;
			int r                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			int m                     = ;
			int r                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ExactTree().getTree(n, m, r);
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
