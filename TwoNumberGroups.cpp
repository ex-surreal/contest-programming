#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define rep(i, n) for (int i=0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

int dp[1005][1005];

class TwoNumberGroups {
	vector <int> prime;
	void makePrime(int n = (int)sqrt(1e9)) {
		vector <bool> flag(n+1, false);
		repi(i, 2, n+1) {
			if (!flag[i]) {
				prime.pb(i);
				for (int j = 2*i; j <= n; j += i) {
					flag[j] = true;
				}
			}
		}
	}
public:
	int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB) {
		int ret;
		rep(i, sz(A)) {
			rep(j, sz(B)) {
				dp[i][j] = abs(A[i]-B[j]);
			}
		}
		makePrime();
		rep(i, sz(prime)) {
			
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
			int A[]                   = {1};
			int numA[]                = {2};
			int B[]                   = {3,7};
			int numB[]                = {1,1};
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {100};
			int numA[]                = {2};
			int B[]                   = {1};
			int numB[]                = {1};
			int expected__            = 28;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {5,1};
			int numA[]                = {1,1};
			int B[]                   = {12,999999894};
			int numB[]                = {1,1};
			int expected__            = 202073;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1};
			int numA[]                = {1};
			int B[]                   = {1};
			int numB[]                = {100000};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {11795180,41472124,44285836,84280940,117000811,150317409,154188370,167804776,225797581, 240995620,301931440,306528163,327332717,333523124,341325123,350292524,400857064,401290197, 426573408,427972026,448467719,563926065,574489831,579516358,609409829,659343788,678481187, 775710113,806992032,831437250,839580344,842388073,869876247,899553191,902366903,975081878};
			int numA[]                = {1188,1769,1782,1757,1527,4958,3083,4439,3621,3958,2655,2250,2079,3885,3598, 3236,3035,2286,7340,4127,3126,2904,2592,3082,3789,2776,3907,2368,4005,4863, 4482,3307,2459,1436,1656,2007};
			int B[]                   = {11795180,41472124,44285836,84280940,117000811,150317409,154188370,167804776,225797581,240995620, 301931440,306528163,327332717,333523124,341325123,350292524,400857064,401290197,426573408, 427972026,448467719,563926065,574489831,579516358,609409829,659343788,678481187,775710113, 806992032,831437250,839580344,842388073,869876247,899553191,902366903,942362007,975081878};
			int numB[]                = {3024,902,798,2,1426,4959,3082,4439,3622,3958,2653,2249,2081,3884,3599, 3237,3033,2285,7340,4125,3127,2904,2592,3082,3789,2775,3907,2369,4006, 4863,4483,3307,623,2303,2642,1757,2107};
			int expected__            = 601548244;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A[]                   = ;
			int numA[]                = ;
			int B[]                   = ;
			int numB[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A[]                   = ;
			int numA[]                = ;
			int B[]                   = ;
			int numB[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int numA[]                = ;
			int B[]                   = ;
			int numB[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroups().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
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
