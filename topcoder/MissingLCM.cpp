#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define x first
#define y second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define repi(i, a, n) for (int i = int(a); i < int(n); i++)
#define repe(i, v) for (__typeof((v).begin()) i; i != (v).end(); i++)

using namespace std;

class MissingLCM {
	vector <int> prime;
	vector <int> cnt;
	vector <int> getPrimes(int n) {
		vector <bool> isPrime(n+1, true);
		for (int i = 2; 1ll*i*i <= n; i++) {
			if (isPrime[i]) {
				for (int j = i*i; j <= n; j += i) {
					isPrime[j] = false;
				}
			}
		}
		repi (i, 2, n+1) {
			if (isPrime[i]) {
				prime.pb(i);
			}
		}
		cnt = vector <int> (prime.size(), 0);
		rep (i, sz(prime)) {
			int t = n;
			while (t >= prime[i]) {
				t /= prime[i];
				cnt[i] ++;
			}
		}
		return prime;
	}

	bool isPossible(int y) {
		rep (i, sz(prime)) {
			int t = y;
			rep (j, cnt[i]) {
				t /= prime[i];
			}
			if (t < 2) {
				return false;
			}
		}
		return true;
	}

public:
	int getMin(int N) {
		getPrimes(N);
		// rep (i, sz(prime)) {
		// 	cerr << prime[i] << " " << cnt[i] << endl;
		// }
		int low = N+1, high = 2*N;
		while (low <= high) {
			int mid = (low+high) / 2;
			if (isPossible(mid)) {
				high = mid -1;
			} else {
				low = mid + 1;
			}
		}
		return low;
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
			int N                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 4;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 5;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 42;
			int expected__            = 82;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int N                     = 999999;
			int expected__            = 1999966;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int N                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int N                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MissingLCM().getMin(N);
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
