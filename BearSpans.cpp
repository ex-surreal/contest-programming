#include <iostream>
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

vector <vector <int> > G;
int w;

class BearSpans {

    int find(int i, int j, int k, int s) {
        /* cout << i << " " << j << " " << k << " " << w << " " << s << endl; */
        if (i >= j || k <= 0) {
            return 0;
        }
        if (k == 1) {
            repi(l, i, j) {
                G[l+1][l] = G[l][l+1] = l-i+s+1;
            }
            return j-i;
        }
        G[(i+j)/2+1][(i+j)/2] = G[(i+j)/2][(i+j)/2+1] = w --;
        int p = find(i, (i+j)/2, k-1, s);
        int q = find((i+j)/2+1, j, k-1, s+p);
        if (p && q) {
            return p+q;
        }
        return 0;
    }
public:
    vector <int> findAnyGraph(int n, int m, int k) {
        vector <int> ret(2*m);
        G = vector <vector <int> > (n, vector <int>(n));
        w = n-1;
        if (!find(0, n-1, k, 0)) {
            return {-1};
        }
        rep(i, n) {
            rep(j, i) {
                if (m >= n && G[i][j] == 0) {
                    G[i][j] = G[j][i] = m --;
                }
            }
        }
        if (m != n-1) {
            return {-1};
        }
        /* rep(i, n) { */
        /*     rep(j, n) { */
        /*         cout << G[i][j] << " "; */
        /*     } cout << endl; */
        /* } */
        rep(i, n) {
            rep(j, i) {
                if (G[i][j] == 0) {
                    continue;
                }
                ret[2*G[i][j]-2] = i+1;
                ret[2*G[i][j]-1] = j+1;
                /* cout << i << " " << j << " " << G[i][j] << endl; */
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
			int n                     = 17;
			int m                     = 22;
			int k                     = 1;
			int expected__[]          = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n                     = 9;
			int m                     = 12;
			int k                     = 3;
			int expected__[]          = {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int n                     = 9;
			int m                     = 12;
			int k                     = 7;
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int n                     = 1000;
			int m                     = 999;
			int k                     = 970;
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int n                     = 2;
			int m                     = 1;
			int k                     = 1;
			int expected__[]          = {1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int n                     = 3;
			int m                     = 2;
			int k                     = 1;
			int expected__[]          = {1, 2, 1, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 6: {
			int n                     = 3;
			int m                     = 3;
			int k                     = 2;
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int m                     = ;
			int k                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int m                     = ;
			int k                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			int m                     = ;
			int k                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BearSpans().findAnyGraph(n, m, k);
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
		moj_harness::run_test(1);
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
