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

const int limit = 100005;
long long tree[limit];

long long read(int id) {
    long long ret = 0;
    while (id > 0) {
        ret += tree[id];
        id -= id&-id;
    }
    return ret;
}

void update(int id, long long val) {
    while (id < limit) {
        tree[id] += val;
        id += id&-id;
    }
}

class SettingShield {
public:
    long long getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
        long long ret;
        vector <int> left(h), right(h), protection(n);
        vector <pair <pair <int, int>, int> > sweep;
        protection[0] = val0[0];
        repi(i, 1, n) {
            protection[i] = (1ll*a[0] * protection[i-1] + b[0]) % m[0];
        }
        left[0] = val0[1];
        right[0] = val0[2];
        repi(i, 1, h) {
            left[i] = min(n-1ll, (1ll*a[1] * left[i-1] + b[1]) % m[1]);
            int dist = right[i-1] - left[i-1];
            right[i] = min(n-1, left[i] + (1ll*a[2] * dist + b[2]) % m[2]);
        }
        rep(i, h) {
            update(left[i]+1, 1);
            update(right[i]+2, -1);
            sweep.pb(mp(left[i], -1), i);
            sweep.pb(mp(right[i], 0), i);
        }
        int spe = 0;
        rep(i, 1, n+1) {
            if (read(i) == 0) {
                spe = max(spe, protection[i-1]);
            }
        }
        int last = 0;
        mem(tree, 0);
        rep(i, n) {
            protection[i] -= spe;
            update(i+1, protection[i] - last);
            last = protection[i];
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
			int n                     = 3;
			int h                     = 3;
			int t                     = 10;
			int val0[]                = {4, 0, 1};
			int a[]                   = {1, 1, 1};
			int b[]                   = {3, 1, 1};
			int m[]                   = {6, 10, 10};
			long long expected__      = 8;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int h                     = 1;
			int t                     = 10;
			int val0[]                = {4, 0, 1};
			int a[]                   = {1, 1, 1};
			int b[]                   = {3, 1, 1};
			int m[]                   = {6, 10, 10};
			long long expected__      = 40;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 6;
			int h                     = 3;
			int t                     = 2;
			int val0[]                = {4, 1, 3};
			int a[]                   = {2, 4, 3};
			int b[]                   = {3, 2, 2};
			int m[]                   = {20, 9, 4};
			long long expected__      = 22;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 12;
			int h                     = 6;
			int t                     = 4;
			int val0[]                = {4, 3, 7};
			int a[]                   = {2, 4, 5};
			int b[]                   = {3, 8, 7};
			int m[]                   = {40, 23, 13};
			long long expected__      = 108;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 50;
			int h                     = 77;
			int t                     = 4;
			int val0[]                = {4, 11, 30};
			int a[]                   = {9, 40, 7};
			int b[]                   = {33, 8, 12};
			int m[]                   = {20000, 200, 13};
			long long expected__      = 79111;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 555;
			int h                     = 120;
			int t                     = 4;
			int val0[]                = {10000000, 301, 520};
			int a[]                   = {9999999, 9999998, 9999997};
			int b[]                   = {9995999, 0, 9919999};
			int m[]                   = {1999999, 9993999, 9299999};
			long long expected__      = 40000000;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int n                     = 501;
			int h                     = 2;
			int t                     = 2;
			int val0[]                = {10000000, 500, 500};
			int a[]                   = {10000000, 10000000, 10000000};
			int b[]                   = {0, 0, 500};
			int m[]                   = {1000003, 10000000, 10000000};
			long long expected__      = 10000000;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int h                     = ;
			int t                     = ;
			int val0[]                = ;
			int a[]                   = ;
			int b[]                   = ;
			int m[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int h                     = ;
			int t                     = ;
			int val0[]                = ;
			int a[]                   = ;
			int b[]                   = ;
			int m[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			int h                     = ;
			int t                     = ;
			int val0[]                = ;
			int a[]                   = ;
			int b[]                   = ;
			int m[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SettingShield().getOptimalCost(n, h, t, vector <int>(val0, val0 + (sizeof val0 / sizeof val0[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
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
