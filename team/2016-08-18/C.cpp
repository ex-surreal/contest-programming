#include <iostream>
#include <cstdio>
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

#define get(x) ((x) < d[s/2] ? id[(x)] : s-1-id[n/(x)])

int id[100005];
long long d[9000];
double dp[9000];
vector <int> prime;

void make(int n = 200005) {
    vector <bool> is(n, true);
    repi(i, 2, n) {
        if (is[i]) {
            prime.push_back(i);
            for (int j = i+i; j < n; j += i) {
                is[j] = false;
            }
        }
    }
}

vector <long long> pr;
vector <int> cnt;
int s;

void back(int i, long long num) {
    if (i < 0) {
        d[s ++] = num;
        return;
    }
    rep(j, cnt[i]+1) {
        back(i-1, num);
        num *= pr[i];
    }
}

int main () {
    int tst;
    make();
    scanf("%d", &tst);
    while (tst --) {
        long long n;
        scanf("%lld", &n);
        long long t = n;
        cnt.clear();
        pr.clear();
        for (int i = 0; 1ll*prime[i]*prime[i] <= t; i ++) {
            if (t % prime[i]) {
                continue;
            }
            cnt.push_back(0);
            pr.push_back(prime[i]);
            while (t % prime[i] == 0) {
                t /= prime[i];
                cnt.back() ++;
            }
        }
        if (t > 1) {
            cnt.push_back(1);
            pr.push_back(t);
        }
        s = 0;
        back(sz(cnt)-1, 1);
        sort(d, d+s);
        rep(i, (s-1)/2+1) {
            id[d[i]] = i;
        }
        rep(i, s) {
            int c = 0;
            repi(j, 1, i) {
                if (d[i] % d[j] == 0) {
                    c ++;
                }
            }
            dp[i] = 0.0;
            repi(j, 1, i) {
                if (d[i] % d[j] == 0) {
                    int k = get(d[i]/d[j]);
                    double t = max(dp[j], dp[k]);
                    dp[i] += (t+1)/c;
                }
            }
        }
        printf("%.10lf\n", dp[s-1]);
    }
    return 0;
}
