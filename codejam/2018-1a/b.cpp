#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_possible(
  const int R, const int B, const int C,
  int * const &M, int * const &S, int * const &P,
  const long long X
) {
  int * buf = new int [C];
  int c = 0;

  for (int i = 0; i < C; i ++) {
    if (X <= P[i]) continue;
    buf[c ++] = min((long long) M[i], (X-P[i]) / S[i]);
  }

  sort(buf, buf+c, [](int a, int b) {
    return a > b;
  });

  long long sum = 0;
  for (int i = 0; i < R && i < c; i ++) sum += buf[i];

  delete [] buf;

  return B <= sum;
}

long long bsearch(
  const int R, const int B, const int C,
  int * const &M, int * const &S, int * const &P
) {
  long long low = 0, high = 1ll << 62;
  while (low <= high) {
    long long mid = (low+high) >> 1;
    if (!is_possible(R, B, C, M, S, P, mid)) low = mid + 1;
    else high = mid - 1;
  }
  return low;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t ++) {
    int R, B, C;
    cin >> R >> B >> C;
    int * M = new int [C];
    int * S = new int [C];
    int * P = new int [C];
    for (int i = 0; i < C; i ++) {
      cin >> M[i] >> S[i] >> P[i];
    }
    cout << "Case #" << t << ": " << bsearch(R, B, C, M, S, P) << endl;
    delete [] M;
    delete [] S;
    delete [] P;
  }
  return 0;
}
