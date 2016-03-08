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

int dp[55][55];

class CliqueParty {
    int s, e, b, k;
    vector <int> a;
    int solve(int i, int l) {
        if (i == e) {
            if (l != s && 1ll*(a[e]-a[l])*k < b) {
                return INT_MIN/5;
            }
            return 0;
        }
        int &ret = dp[i][l];
        if (ret == -1) {
            ret = solve(i+1, l);
            if (1ll*(a[i] - a[l])*k >= b) {
                ret = max(ret, solve(i+1, i)+1);
            }
        }
        return ret;
    }
public:
    int maxsize(vector <int> a, int k) {
        int ret = 0;
        sort(all(a));
        this->a = a;
        this->k = k;
        for (s = 0; s < sz(a); s ++) {
            for (e = s+1; e < sz(a); e ++) {
                mem(dp, -1);
                b = a[e] - a[s];
                ret = max(ret, solve(s+1, s)+2);
                if (solve(s+1, s) == 6) {
                    cout << s << " " << e << endl;
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
			int a[]                   = {1,2,3};
			int k                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {1,2,3};
			int k                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {4,10,5,6};
			int k                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {1,2,3,4,5,6};
			int k                     = 3;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {10,9,25,24,23,30};
			int k                     = 7;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases
      case 5: {
			int a[]                   = {748, 272, 810, 279, 467, 472, 218, 853, 552, 749, 63, 179, 831, 335, 485, 785, 675, 416, 558, 577, 531, 691, 39, 610, 431, 738, 616, 293, 717, 380, 744, 626, 463, 784};
			int k                     = 7;
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int a[]                   = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CliqueParty().maxsize(vector <int>(a, a + (sizeof a / sizeof a[0])), k);
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
		moj_harness::run_test(5);
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
