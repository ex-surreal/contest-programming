#include <iostream>
#include <bitset>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>

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

class TreeDistanceConstruction {
public:
    vector <int> construct(vector <int> d) {
        vector <int> ret, id;
        int n = sz(d), x = -1;
        multiset <pair <int, int> > s;
        rep(i, n) {
          s.insert(mp(d[i], i));
          x = max(x, d[i]);
        }
        auto it = s.lower_bound(mp(x, -1));
        id.push_back(it->y);
        s.erase(it);
        rep(i, x) {
          auto it = s.lower_bound(mp(max(x-i-1, i+1), -1));
          if (it == s.end() || it->x != max(x-i-1, i+1)) {
            return {};
          }
          id.push_back(it->y);
          ret.push_back(id[i]);
          ret.push_back(id[i+1]);
          s.erase(it);
        }
        repe(e, s) {
          if (e.x < (x+1)/2+1) {
            return {};
          }
          ret.push_back(e.y);
          ret.push_back(id[e.x-1]);
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
			int d[]                   = {3,2,2,3};
			int expected__[]          = {1, 2, 1, 0, 2, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int d[]                   = {1,2,2,2};
			int expected__[]          = {0, 1, 0, 2, 0, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int d[]                   = {1,1,1,1};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int d[]                   = {1,1,1};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int d[]                   = {1,1};
			int expected__[]          = {0, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int d[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int d[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int d[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeDistanceConstruction().construct(vector <int>(d, d + (sizeof d / sizeof d[0])));
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
