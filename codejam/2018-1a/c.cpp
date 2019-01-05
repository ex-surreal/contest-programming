#include <iostream>
#include <list>
#include <cmath>

using namespace std;

typedef list <pair <int, double> > List;

class CookieCutter {
private:
  int * width, * height;
  int p, limit, n;

  List merge(const List &S, const int L, const double R) {
    auto i = S.begin(), j = S.begin();
    int last = -1;
    List ans;
    while (i != S.end()) {
      int l1 = i->first, l2 = j->first+L;
      double r1 = i->second, r2 = j->second+R;
      if (last < 0) last = min(l1, l2);

      if (r1 < r2) i ++;
      else j ++;

      if (min(r1, r2) < max(l1, l2)) {
        if (last <= limit) ans.push_back({last, min(r1, r2)});
        last = -1;
      }
    }
    while (j != S.end()) {
      if (last < 0) last = j->first+L;
      if (last <= limit) ans.push_back({last, j->second+R});
      last = -1;
      j ++;
    }
    return ans;
  }

public:
  CookieCutter(
    const int N, const int P,
    int * const &W, int * const &H
  ): p(P), n(N) {
    limit = p;
    width = new int [n];
    height = new int[n];
    for (int i = 0; i < n; i ++) {
      width[i] = min(W[i], H[i]);
      height[i] = max(W[i], H[i]);
      limit -= 2 * (width[i] + height[i]);
    }
  }

  ~CookieCutter() {
    delete [] width;
    delete [] height;
  }

  void testMerge(int t, int l) {
    srand(clock());
    int tmp = limit;
    limit = l;
    List S, T;
    S = {{0, 0.0}};
    while (t --) {
      int w = rand() % 250 + 1;
      int h = w + rand() % (251-w);
      cout << "== " << w << " " << h << " " << 2*w << " " << 2*sqrt(w*w + h*h) << endl;
      T = merge(S, 2*w, 2*sqrt(w*w + h*h));
      S = T;
      for (auto &x: S) {
        cout << "(" << x.first << ", " << x.second << "), ";
      } cout << endl;
    }
    limit = tmp;
  }

  double maxEdge() {
    double ans = 0;
    List S = {{0, 0.0}};
    for (int i = 0; i < n; i ++) {
      int L = 2 * width[i];
      double R = 2 * sqrt(width[i]*width[i] + height[i]*height[i]);
      auto T = merge(S, L, R);
      S.clear();
      S = T;
    }
    for (auto &x: S) {
      if (x.second >= limit) {
        ans = p;
        break;
      } else {
        ans = max(ans, x.second + p-limit);
      }
    }
    return ans;
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t ++) {
    cout.precision(10);
    cout.setf(ios::fixed);
    int N, P;
    cin >> N >> P;
    int * W = new int [N];
    int * H = new int [N];
    for (int i = 0; i < N; i ++) {
      cin >> W[i] >> H[i];
    }
    CookieCutter cutter(N, P, W, H);
    cout << "Case #" << t << ": " << cutter.maxEdge() << endl;
    delete [] W;
    delete [] H;
  }
  return 0;
}
