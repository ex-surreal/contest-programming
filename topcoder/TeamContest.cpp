#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int dp[45][45][46];

class TeamContest {
	vector <int> leftOut;
	int ourStrength;
	int solve(int i, int j, int k) {
		if (j-i+1 == k) {
			return 0;
		}
		if (j-i+1 < k) {
			return -1000;
		}
		int &ret = dp[i][j][k];
		if (ret == -1) {
			ret = max(solve(i+1, j, k - (k > 0)), solve(i, j-1, k - (k > 0)));
			if (leftOut[i] + leftOut[j] > ourStrength) {
				ret = max(ret, solve(i+1, j-1, k+1)+1);
			}
		}
		return ret;
	}
public:
	int worstRank(vector <int> strength) {
		vector <int> firstThree(strength.begin(), strength.begin()+3);
		leftOut = vector <int> (strength.begin()+3, strength.end());
		ourStrength = *max_element(firstThree.begin(), firstThree.end()) + 
			*min_element(firstThree.begin(), firstThree.end());
		sort(leftOut.begin(), leftOut.end());
		memset(dp, -1, sizeof dp);
		return solve(0, sz(leftOut)-1, 0) + 1;
	}
};

int main () {
	std::ios_base::sync_with_stdio(false);
	TeamContest teamContest;
	cout << teamContest.worstRank(vector <int>({5, 7, 3, 5, 7, 3, 5, 7, 3}));
	return 0;
}