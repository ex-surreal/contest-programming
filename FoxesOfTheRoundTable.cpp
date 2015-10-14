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

class FoxesOfTheRoundTable {
	bool isPossible(int d, vector <int> &h, vector <int> &ord) {
		vector <int> l(1, 0), r(1, 0);
		repi(i, 1, sz(h) - 1) {
			if (h[i] - h[l.back()] <= d && h[i] - h[r.back()] <= d) {
				if (h[l.back()] < h[r.back()]) {
					l.pb(i);
				} else {
					r.pb(i);
				}
			} else if (h[i] - h[l.back()] <= d) {
				l.pb(i);
			} else if (h[i] - h[r.back()] <= d) {
				r.pb(i);
			} else {
				return false;
			}
		}
		if (h.back() - h[l.back()] > d || h.back() - h[r.back()] > d) {
			return false;
		}
		reverse(r.begin(), r.end());
		r.pop_back();
		l.pb(sz(h) - 1);
		l.insert(l.end(), r.begin(), r.end());
		ord = l;
		return true;
	}
public:
	vector <int> minimalDifference(vector <int> h) {
		vector <int> ret;
		vector <int> id;
		rep(i, sz(h)) {
			id.pb(i);
		}
		rep(i, sz(h)) {
			repi(j, i+1, sz(h)) {
				if (h[i] > h[j]) {
					swap(h[i], h[j]);
					swap(id[i], id[j]);
				}
			}
		}
		int high = 1000, low = 0;
		while (low <= high) {
			int mid = (high+low) >> 1;
			if (isPossible(mid, h, ret)) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		rep(i, sz(ret)) {
			ret[i] = id[ret[i]];
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
			int h[]                   = {1,99,50,50};
			int expected__[]          = {0, 3, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int h[]                   = {123,456,789};
			int expected__[]          = {0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int h[]                   = {10,30,40,50,60};
			int expected__[]          = {0, 1, 4, 3, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int h[]                   = {1,2,3,4,8,12,13,14 };
			int expected__[]          = {0, 1, 2, 3, 5, 6, 7, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int h[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			int expected__[]          = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int h[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int h[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int h[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FoxesOfTheRoundTable().minimalDifference(vector <int>(h, h + (sizeof h / sizeof h[0])));
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
