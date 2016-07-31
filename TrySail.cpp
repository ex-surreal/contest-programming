#include <iostream>
#include <bitset>
#include <numeric>
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

class TrySail {
public:
    int get(vector <int> strength) {
        int ret;
        bitset <256*256> dp[2][8];
        int now = 0, pre = 1;
        dp[now][0][0] = 1;
        rep(i, sz(strength)) {
            swap(now, pre);
            rep(j, 8) {
                rep(p, 256) {
                    rep(q, 256) {
                        int x = ((p^strength[i])<<8) | q;
                        int y = (p<<8) | (q^strength[i]);
                        int z = (p<<8) | q;
                        dp[now][j][z] = dp[pre][j&~1][x] || dp[pre][j&~2][y] || dp[pre][j&~4][z];
                    }
                }
            }
        }
        ret = 0;
        int x = accumulate(all(strength), 0, bit_xor <int>());
        rep(i, 256) {
            rep(j, 256) {
                int num = (i<<8) | j;
                if (dp[now][7][num]) {
                    int k = i^j^x;
                    ret = max(i+j+k, ret);
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
			int strength[]            = {2,3,3};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int strength[]            = {7,3,5,2};
			int expected__            = 17;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int strength[]            = {13,13,13,13,13,13,13,13};
			int expected__            = 26;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int strength[]            = {114,51,4,191,9,81,0,89,3};
			int expected__            = 470;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int strength[]            = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
			int expected__            = 567;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int strength[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int strength[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int strength[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TrySail().get(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
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
