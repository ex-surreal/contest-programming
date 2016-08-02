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

class LimitedMemorySeries2 {
    static const int mod = 1e9+7;
    long long a, b;
    long long nxt(long long x) {
        return ((x^a)+b)&((1ll<<50)-1);
    }
    long long pre(long long x) {
        return (((x|(1ll<<50))-b)^a)&((1ll<<50)-1);
    }
public:
    int getSum(int n, long long x0, long long a, long long b) {
        this->a = a, this->b = b;
        int ret = 0;
        long long x = x0;
        rep (i, n) {
            int k = 1;
            long long l = pre(x), r = nxt(x);
            while (i-k >= 0 && i+k < n && r < x && l < x) {
                k ++;
                r = nxt(r);
                l = pre(l);
            }
            ret += k - 1;
            if (ret >= mod) {
                ret -= mod;
            }
            x = nxt(x);
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
			int n                     = 6;
			long long x0              = 2;
			long long a               = 23;
			long long b               = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 100;
			long long x0              = 0;
			long long a               = 0;
			long long b               = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 234234;
			long long x0              = 1125899906842623LL;
			long long a               = 123456789123456LL;
			long long b               = 987654321549687LL;
			int expected__            = 1144970;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 10000000;
			long long x0              = 12345678912345LL;
			long long a               = 98765094309812LL;
			long long b               = 34893049812392LL;
			int expected__            = 65420804;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int n                     = 20;
			long long x0              = 6;
			long long a               = 0;
			long long b               = 0;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int n                     = ;
			long long x0              = ;
			long long a               = ;
			long long b               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			long long x0              = ;
			long long a               = ;
			long long b               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LimitedMemorySeries2().getSum(n, x0, a, b);
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
