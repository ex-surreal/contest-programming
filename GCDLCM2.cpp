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

int last[10000007];
int P[10000007];

class GCDLCM2 {
    static const int mod = 1e9+7;
    void calLast(int n = 10000007) {
        for (int i = 2; i < n; i ++) {
            if (last[i] == 0) {
                for (int j = i; j < n; j += i) {
                    last[j] = i;
                }
            }
        }
    }
    vector <int> generate(vector <int> start, vector <int> d, vector <int> cnt) {
        vector <int> ret;
        rep(i, sz(start)) {
            rep(j, cnt[i]) {
                ret.pb(start[i] + j * d[i]);
            }
        }
        return ret;
    }
    void factorize(vector <int> a) {
        repe(x, a) {
            while (x > 1) {
                int t = last[x], c = 1;
                while (x % t == 0) {
                    c = c*t;
                    x /= t;
                }
                P[c] ++;
            }
        }
    }

    int count(int t) {
        long long p = t;
        int sum = 0;
        while (p <= 10000000) {
            sum += P[p];
            p *= last[t];
        }
        return sum;
    }

    int getmin(int t) {
        int sum = 1;
        while (t > 1) {
            t /= last[t];
            if (P[t] > 0) {
                sum = t;
                break;
            }
        }
        return sum;
    }

public:
    int getMaximalSum(vector <int> start, vector <int> d, vector <int> cnt) {
        int ret = 0;
        vector <int> a = generate(start, d, cnt);
        repi(i, 1, sz(a)) {
            bool go = true;
            
            if (!go) {
                break;
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
			int start[]               = {1};
			int d[]                   = {1};
			int cnt[]                 = {3};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int start[]               = {3};
			int d[]                   = {0};
			int cnt[]                 = {5};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int start[]               = {2};
			int d[]                   = {2};
			int cnt[]                 = {4};
			int expected__            = 32;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int start[]               = {1, 2};
			int d[]                   = {2, 3};
			int cnt[]                 = {2, 2};
			int expected__            = 33;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int start[]               = {5 ,6};
			int d[]                   = {23, 45};
			int cnt[]                 = {50000, 50000};
			int expected__            = 804225394;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int start[]               = ;
			int d[]                   = ;
			int cnt[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int start[]               = ;
			int d[]                   = ;
			int cnt[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int start[]               = ;
			int d[]                   = ;
			int cnt[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GCDLCM2().getMaximalSum(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(d, d + (sizeof d / sizeof d[0])), vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
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
		moj_harness::run_test(2);
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
