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

int nowTen;
int tenPow[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
bool comp(int a, int b) {
    return a/tenPow[nowTen]%10 < b/tenPow[nowTen]%10;
}

class ReplacingDigit {
    
    int maxPos(vector <int> &D) {
        for (int d = 8; d >= 0; d --) {
            if (D[d] > 0) {
                return d+1;
            }
        }
        return 0;
    }

    void reduce(vector <int> &A, vector <int> &D) {
        sort(all(A), comp);
        rep(i, sz(A)) {
            if (A[i] >= tenPow[nowTen]) {
                int d = maxPos(D);
                if (A[i]/tenPow[nowTen]%10 < d) {
                    A[i] -= A[i]/tenPow[nowTen]%10*tenPow[nowTen];
                    A[i] += d*tenPow[nowTen];
                    D[d-1] --;
                }
            }
        }
    }
public:
    int getMaximumStockWorth(vector <int> A, vector <int> D) {
        int ret = 0;
        for (nowTen = 6; nowTen >= 0; nowTen --) {
            reduce(A, D);

        }
        ret = accumulate(all(A), 0);
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
			int A[]                   = {100, 90};
			int D[]                   = {0, 0, 0, 0, 2, 1, 0, 0, 0};
			int expected__            = 745;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {9};
			int D[]                   = {1, 1, 1, 1, 1, 1, 1, 1, 0};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {123456};
			int D[]                   = {9, 8, 7, 6, 5, 4, 3, 2, 1};
			int expected__            = 988777;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
			int D[]                   = {11, 2, 8, 10, 7, 6, 3, 1, 3};
			int expected__            = 3297500;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int D[]                   = {111, 111, 111, 111, 111, 111, 111, 111, 111};
			int expected__            = 198;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A[]                   = ;
			int D[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A[]                   = ;
			int D[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int D[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ReplacingDigit().getMaximumStockWorth(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(D, D + (sizeof D / sizeof D[0])));
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
