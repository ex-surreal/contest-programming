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

class Sunnygraphs {
    void dfs(int u, int c, vector <vector <int> > &B, vector <int> &comp) {
        comp[u] = c;
        rep(v, sz(B)) {
            if (B[u][v] && comp[v] == -1) {
                dfs(v, c, B, comp);
            }
        }
    }
public:
    long long count(vector <int> a) {
        long long ret = 0;
        int n = sz(a);
        vector <vector <int> > B(n+1, vector <int>(n+1, 0));
        rep(u, n) {
            int v = a[u];
            B[u][v] = B[v][u] = 1;
        }
        vector <int> comp(n+1, -1);
        dfs(0, 0, B, comp);
        if (comp[0] == comp[1]) {
            ret = 1ll << n;
            int s = 0;
            rep(i, n) {
                s += comp[i] == -1;
            }
            rep(i, n) {
                int t = a[i];
                a[i] = n;
                B = vector <vector <int> >(n+1, vector <int>(n+1, 0));
                rep(u, n) {
                    int v = a[u];
                    B[u][v] = B[v][u] = 1;
                }
                comp = vector <int> (n+1, -1);
                dfs(i, 0, B, comp);
                int x = 0;
                rep(j, n) {
                    x += comp[j] == 0;
                }
                if (comp[0] != comp[1]) {
                    ret -= 1ll << (s+x-1);
                }
                a[i] = t;
            }
        } else {
            dfs(1, 1, B, comp);
            int x = 0, y = 0;
            rep(i, n) {
                x += comp[i] == 0;
                y += comp[i] == 1;
            }
            ret = ((1ll<<x)-1)*((1ll<<y)-1)*(1ll << (n-(x+y)));
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int a[]                   = {1,0};
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {2,2,0};
			long long expected__      = 7;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {2,3,0,1};
			long long expected__      = 9;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {2,2,3,4,3};
			long long expected__      = 30;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
			long long expected__      = 2198754820096LL;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
