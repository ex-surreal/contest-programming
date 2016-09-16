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

/* int dp[100][100]; */
/* int solve(int a, int b, int k) { */
/*   if (dp[a][b] == -1) { */
/*     dp[a][b] = 0; */
/*     rep(i, a) { */
/*       if (!solve(i, b, k)) { */
/*         dp[a][b] = 1; */
/*         break; */
/*       } */
/*     } */
/*     rep(i, b) { */
/*       if (dp[a][b] || !solve(a, i, k)) { */
/*         dp[a][b] = 1; */
/*         break; */
/*       } */
/*     } */
/*     repi(i, 1, a+1) { */
/*       repi(j, max(1, i-k), min(b+1, i+k+1)) { */
/*         if (dp[a][b] || !solve(a-i, b-j, k)) { */
/*           dp[a][b] = 1; */
/*           break; */
/*         } */
/*       } */
/*     } */
/*   } */
/*   return dp[a][b]; */
/* } */

int main () {
  /* repi(k, 1, 30) { */
  /*   mem(dp, -1); */
  /*   vector <int> B(100001), f(100001); */
  /*   int c = 0, pre = 0; */
  /*   repi(i, 1, sz(B)) { */
  /*     if (f[i]) { */
  /*       c ++; */
  /*       continue; */
  /*     } */
  /*     B[i] = pre + c + k+2; */
  /*     if (B[i] >= sz(B)) { */
  /*       break; */
  /*     } */
  /*     f[B[i]] = 1; */
  /*     pre = B[i]; */
  /*     c = 0; */
  /*   } */
  /*   /1* repi(i, 1, 30) { *1/ */
  /*   /1*   cout << "** " << i << " " << B[i] << endl; *1/ */
  /*   /1* } *1/ */
  /*   repi(i, 1, 50) { */
  /*     repi(j, 1, 50) { */
  /*       int a = min(i, j), b = max(i, j); */
  /*       int winning = B[a] != b; */
  /*       /1* if (solve(i, j, 1) != winning) { *1/ */
  /*       /1*   cout << i << " " << j << " " << k << " " << solve(i, j, k) << endl; *1/ */
  /*       /1* } *1/ */
  /*       if (solve(i, j, k) != winning) { */
  /*         cout << i << " " << j << " " << k << endl; */
  /*       } */
  /*       /1* if (i < j && !solve(i, j, k)) { *1/ */
  /*       /1*   cout << i << " " << j << " " << k << endl; *1/ */
  /*       /1* } *1/ */
  /*     } */
  /*   } */
  /* } */
  int tst;
  scanf("%d", &tst);
  while (tst --) {
    int k, q;
    scanf("%d%d", &k, &q);
    vector <int> B(100001), f(100001);
    int c = 0, pre = 0;
    repi(i, 1, sz(B)) {
      if (f[i]) {
        c ++;
        continue;
      }
      B[i] = pre + c + k+2;
      if (B[i] >= sz(B)) {
        break;
      }
      f[B[i]] = 1;
      pre = B[i];
      c = 0;
    }
    while (q --) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (a > b) {
        swap(a, b);
      }
      if (B[a] == b) {
        printf("LOSING\n");
      } else {
        printf("WINNING\n");
      }
    }
    printf("\n");
  }
  return 0;
}
