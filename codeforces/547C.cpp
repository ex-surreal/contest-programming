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

int cnt[500005];
int P[500005];
int C[500005];
int a[200005];
bool flag[200005];

int main () {
	std::ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	rep(i, n) {
		cin >> a[i];
		C[a[i]]++;
		flag[i] = true;
	}
	repi(i, 2, 500005) {
		if (P[i] == 1) {
			continue;
		}
		int now = 0;
		for (int j = i; j < 500005; j += i) {
			cnt[j] += now * (P[i] == 0 ? 1 : -1);
			now += C[j];
		}
	}
	cnt[1] = C[1] * (n - 1);
	int cum = C[0], total = 0;
	repi(i, 1, 500005) {
		cnt[i] = cum - cnt[i];
		cum += C[i];
		total += cnt[i];
	}
	rep(i, q) {
		int x;
		cin >> x;
		if (flag[x]) {
			flag[x] = false;
			total -= cnt[a[x]]/C[a[x]];
		}
		cout << () << "\n";
	}
	return 0;
}
