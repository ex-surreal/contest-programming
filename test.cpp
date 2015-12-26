#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(x) int((x).size())

int minimalSteps(int a, int b, int newA, int newB) {
    if (a > newA || b > newB) return -1;
    int i = 0;
    while (newA >= (a<<i) && newB >= (b<<i) && newA-(a<<i) == newB-(b<<i)) {
        i ++;
    }
    if (!(newA >= (a<<i)) && newB >= (b<<i))return -1;
    int dt = newA - (a<<i);
    int res = i;
    while (dt) {
        res ++;
        dt &= (1<<i)-1;
    }
    return res;
}

int main () {
	std::ios_base::sync_with_stdio(false);
    cout << minimalSteps(1, 27, 19, 123);	
	return 0;
}
