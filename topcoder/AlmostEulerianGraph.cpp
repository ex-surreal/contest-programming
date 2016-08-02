#include <iostream>
#include <vector>

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

class AlmostEulerianGraph {
    static const int mod = 1e9+7;
    vector <vector <int> > C;
    vector <int> two;
    void pre_calc() {
        C = vector <vector <int> >(2005, vector <int>(2005));
        rep(i, 2005) {
            C[i][0] = 1;
            repi(j, 1, i+1) {
                C[i][j] = C[i-1][j]+C[i-1][j-1];
                if (C[i][j] >= mod) {
                    C[i][j] -= mod;
                }
            }
        }
        two = vector <int>(4000005, 1);
        repi(i, 1, 4000005) {
            two[i] = 2*two[i-1];
            if (two[i] >= mod) {
                two[i] -= mod;
            }
        }
    }
    
    int eular(int n) {
        return two[(n-2)*(n-1)/2];
    }
public:
    int calculateGraphs(int n) {
        int ret = 0;
        pre_calc();
        vector <int> d(n+1, 0);
        repi(i, 2, n+1) {
            repi(j, 1, i) {
                d[i] += 1ll*C[i-1][j-1]*eular(i-j)%mod*((eular(j)-d[j]+mod)%mod)%mod;
                d[i]%= mod;
            }
        }
        ret = 1ll*(eular(n)-d[n]+mod)%mod*(n*(n-1)/2 + 1)%mod;
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
			int n                     = 3;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = AlmostEulerianGraph().calculateGraphs(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = AlmostEulerianGraph().calculateGraphs(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 42;
			int expected__            = 29010676;

			std::clock_t start__      = std::clock();
			int received__            = AlmostEulerianGraph().calculateGraphs(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AlmostEulerianGraph().calculateGraphs(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int n                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AlmostEulerianGraph().calculateGraphs(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AlmostEulerianGraph().calculateGraphs(n);
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
