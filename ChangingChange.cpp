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

int fact[1<<20], inv[1<<20], mod = 1e9+7;

template<class type> type pwr(type base, type expo, type mod) {
	type ret(1);
	while (expo > 0) {
		if (expo&1) {
			ret = 1ll*ret*base%mod;
		}
		base = 1ll*base*base%mod;
		expo >>= 1;
	}
	return ret;
}

void calFact(int n = 1<<20) {
	fact[0] = 1;
	repi(i, 1, n) {
		fact[i] = 1ll*i*fact[i-1]%mod;
	}
	inv[n-1] = pwr(fact[n-1], mod-2, mod);
	for (int i = n-2; i >= 0; i--) {
		inv[i] = 1ll*inv[i+1]*(i+1)%mod;
	}
}

int comb(int n, int r) {
	return 1ll*fact[n]*inv[r]%mod*inv[n-r]%mod;
}

class ChangingChange {
public:
	vector <int> countWays(vector <int> dp, vector <int> v, vector <int> r) {
		vector <int> ret(sz(v), 0);
		int D = sz(dp) - 1;
		calFact();
		rep(i, sz(ret)) {
			for (int j = 0; D >= j*v[i]; j++) {
				ret[i] = (ret[i] + 1ll*(1-((j&1)<<1))*comb(r[i]-1+j, j)*dp[D-j*v[i]])%mod;
				ret[i] = (ret[i] + mod)%mod;
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int ways[]                = {1, 4, 6};
			int valueRemoved[]        = {1, 1, 1};
			int numRemoved[]          = {1, 2, 3};
			int expected__[]          = {3, 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int ways[]                = {1, 2, 1, 0, 0, 0, 0, 0, 7};
			int valueRemoved[]        = {8, 8, 1, 1};
			int numRemoved[]          = {1, 7, 1, 2};
			int expected__[]          = {6, 0, 7, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int ways[]                = {1, 2, 3, 6, 9, 14};
			int valueRemoved[]        = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
			int numRemoved[]          = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
			int expected__[]          = {9, 10, 11, 12, 13, 6, 8, 8, 10, 12 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int ways[]                = {1, 0};
			int valueRemoved[]        = {1, 1};
			int numRemoved[]          = {1, 1000000};
			int expected__[]          = {1000000006, 999000007 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int ways[]                = {1, 2, 3, 6, 9, 14};
			int valueRemoved[]        = {1, 3, 5};
			int numRemoved[]          = {1000000, 4, 2};
			int expected__[]          = {34955525, 2, 12 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int ways[]                = ;
			int valueRemoved[]        = ;
			int numRemoved[]          = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int ways[]                = ;
			int valueRemoved[]        = ;
			int numRemoved[]          = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int ways[]                = ;
			int valueRemoved[]        = ;
			int numRemoved[]          = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChangingChange().countWays(vector <int>(ways, ways + (sizeof ways / sizeof ways[0])), vector <int>(valueRemoved, valueRemoved + (sizeof valueRemoved / sizeof valueRemoved[0])), vector <int>(numRemoved, numRemoved + (sizeof numRemoved / sizeof numRemoved[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
