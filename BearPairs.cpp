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

class BearPairs {
    static const int A = 6, M = 100;
public:
    int minCost(string s, vector <int> cost, int k) {
        int ret(1<<29);
        int n = sz(s);
        int with[2][k+2][n+2][A];
        int without[2][k+2][n+2][A];
        int now = 0, pre = 1;
        rep(b, k+2) {
            rep(c, n+2) {
                rep(d, A) {
                    with[now][b][c][d] = (1<<29);
                    without[now][b][c][d] = (1<<29);
                }
            }
        }
        rep(i, A) {
            with[now][0][0][i] = 0;
            without[now][0][0][i] = 0;
        }
        rep(i, n) {
            int t = s[i] - 'a';
            rep(b, k+1) {
                rep(c, n+1) {
                    rep(d, A) {
                        rep(e, A) {
                            if (d != e || c == 0) {
                                without[now][b][c][e] = min(without[now][b][c][e], with[now][b][c][d]);
                            }
                            if (c == 0) {
                                with[now][b][c][e] = min(with[now][b][c][e], without[now][b][c][d]);
                            }
                        }
                    }
                }
            }
            swap(now, pre);
            rep(b, k+1) {
                rep(c, n+1) {
                    rep(d, A) {
                        with[now][b][c][d] = (1<<29);
                        without[now][b][c][d] = (1<<29);
                        if (d == t && c > 0) {
                            with[now][b][c][d] = min(with[now][b][c][d], with[pre][b][c-1][d] + cost[i] + -i*M);
                        } else if (d != t) {
                            with[now][b][c][d] = min(with[now][b][c][d], with[pre][b][c+1][d] + cost[i] + +i*M);
                        }
                        if (b > 0) {
                            with[now][b][c][d] = min(with[now][b][c][d], with[pre][b-1][c][d]);
                        }
                        if (d != t && c > 0) {
                            without[now][b][c][d] = min(without[now][b][c][d], without[pre][b][c-1][d] + cost[i] + -i*M);
                        } else if (d == t) {
                            without[now][b][c][d] = min(without[now][b][c][d], without[pre][b][c+1][d] + cost[i] + +i*M);
                        }
                        if (b > 0) {
                            without[now][b][c][d] = min(without[now][b][c][d], without[pre][b-1][c][d]);
                        }
                    }
                }
            }
        }
        rep(i, A) {
            ret = min(ret, with[now][k][0][i]);
            ret = min(ret, without[now][k][0][i]);
        }
        if (ret == (1<<29)) {
            ret = -1;
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
			string s                  = "aabcde";
			int cost[]                = {1, 1, 100000, 100000, 100000, 100000};
			int k                     = 2;
			int expected__            = 200402;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "cdbcadc";
			int cost[]                = {261,208,150,250,92,226,176};
			int k                     = 1;
			int expected__            = 1402;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "deebaffafdaaceaa";
			int cost[]                = {160,268,253,210,34,28,180,70,5,42,177,234,108,117,215,1};
			int k                     = 2;
			int expected__            = 2507;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "babbbabbbbababababbb";
			int cost[]                = {184,189,202,170,296,71,136,48,51,161,221,24,221,186,223,228,73,274,279,22};
			int k                     = 4;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "aaaaaaaaaaaaaaaaaa";
			int cost[]                = {237,185,24,175,107,251,299,81,282,20,150,164,240,225,166,261,164,123};
			int k                     = 4;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "acadeffbffbfccbe";
			int cost[]                = {62,113,189,161,211,150,69,60,99,212,37,274,110,265,199,192};
			int k                     = 4;
			int expected__            = 2235;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string s                  = ;
			int cost[]                = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			int cost[]                = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string s                  = ;
			int cost[]                = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearPairs().minCost(s, vector <int>(cost, cost + (sizeof cost / sizeof cost[0])), k);
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
