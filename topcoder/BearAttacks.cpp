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

const int mod = 1e9+7, BILLION = 1e9;

class BearAttacks {
	vector <int> prob, dp, parent;
	int pwr(int base, int ex, int mod) {
		int ret = 1;
		while (ex > 0) {
			if (ex&1) {
				ret = 1ll*base*ret%mod;
			}
			ex >>= 1;
			base = 1ll*base*base%mod;
		}
		return ret;
	}
public:
	int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH) {
		int ret = 0;
		prob = dp = parent = vector <int> (N, 0);
		int R = R0;
		repi(i, 1, N) {
			R = (1ll*A * R + B) % M;
			int MIN = 1ll*(i-1) * LOW / BILLION;
			int MAX = 1ll*(i-1) * HIGH / BILLION;
			parent[i] = MIN + (R % (MAX-MIN+1));
		}
		rep(i, N) {
			dp[i] = prob[i] = pwr(i+1, mod - 2, mod);
		}
		for (int u = N-1; u > 0; u--) {
			int w = parent[u];
			dp[w] = (dp[w] + 1ll*prob[w]*dp[u])%mod;
		}
		rep(u, N) {
			ret = (ret + prob[u]) % mod;
		}
		repi(u, 1, N) {
			int w = parent[u];
			ret = (ret + 1ll*prob[w]*dp[u]) % mod;
			ret = (ret + 1ll*dp[u]*(dp[w] - 1ll*prob[w]*dp[u]%mod + mod))%mod;
		}
		rep(i, N) {
			ret = 1ll*ret*(i+1)%mod;
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
			int N                     = 3;
			int R0                    = 0;
			int A                     = 2;
			int B                     = 3;
			int M                     = 100;
			int LOW                   = 938593850;
			int HIGH                  = 1000000000;
			int expected__            = 21;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int R0                    = 0;
			int A                     = 0;
			int B                     = 0;
			int M                     = 1;
			int LOW                   = 0;
			int HIGH                  = 0;
			int expected__            = 23;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 6;
			int R0                    = 303840291;
			int A                     = 848660283;
			int B                     = 395739574;
			int M                     = 950123456;
			int LOW                   = 0;
			int HIGH                  = 1000000000;
			int expected__            = 3856;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1;
			int R0                    = 0;
			int A                     = 0;
			int B                     = 0;
			int M                     = 1;
			int LOW                   = 0;
			int HIGH                  = 0;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 19;
			int R0                    = 384038999;
			int A                     = 938592393;
			int B                     = 692854433;
			int M                     = 1000000000;
			int LOW                   = 300000000;
			int HIGH                  = 600000000;
			int expected__            = 473263988;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int R0                    = ;
			int A                     = ;
			int B                     = ;
			int M                     = ;
			int LOW                   = ;
			int HIGH                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int R0                    = ;
			int A                     = ;
			int B                     = ;
			int M                     = ;
			int LOW                   = ;
			int HIGH                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int R0                    = ;
			int A                     = ;
			int B                     = ;
			int M                     = ;
			int LOW                   = ;
			int HIGH                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearAttacks().expectedValue(N, R0, A, B, M, LOW, HIGH);
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
