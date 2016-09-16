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

int n;

tuple <int, int, int, int> hor(int l, int u) {
  int x = l, y = u;
  int lst = -1;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << "1 " << mid << " " << n << " " << u << endl;
    cin >> lst;
    if (lst == 0) {
      y = mid - 1;
    } else {
      x = mid + 1;
    }
  }
  int y1 = y;
  x = y1, y = u;
  while (x <= n) {
    int mid = (x+y)/2;
    cout << "? " << "1 " << y1 << " " << n << " " << mid << endl;
    cin >> lst;
    if (lst == 0) {
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  int y2 = x;
  x = 1, y = n;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << mid << " " << y1 << " " << n << " " << y2 << endl;
    if (lst == 0) {
      y = mid - 1;
    } else {
      x = mid + 1;
    }
  }
  int x1 = y;
  x = x1, y = n;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << x1 << " " << y1 << " " << mid << " " << y2 << endl;
    if (lst == 0) {
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  int x2 = x;
  return make_tuple(x1, y1, x2, y2);
}

tuple <int, int, int, int> ver(int l, int u) {
  int x = l, y = u;
  int lst = -1;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << mid << " " << "1" << " " << u << " " << n << endl;
    cin >> lst;
    if (lst == 0) {
      y = mid - 1;
    } else {
      x = mid + 1;
    }
  }
  int y1 = y;
  x = y1, y = u;
  while (x <= n) {
    int mid = (x+y)/2;
    cout << "? " << y1 << " 1" << " " << mid << " " << n << endl;
    cin >> lst;
    if (lst == 0) {
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  int y2 = x;
  x = 1, y = n;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << y1 << " " << mid << " " << y2 << " " << n << endl;
    if (lst == 0) {
      y = mid - 1;
    } else {
      x = mid + 1;
    }
  }
  int x1 = y;
  x = x1, y = n;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << y1 << " " << x1 << " " << y2 << " " << mid << endl;
    if (lst == 0) {
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  int x2 = x;
  return make_tuple(y1, x1, y2, x2);
}

int main () {
  std::ios_base::sync_with_stdio(false);
  cin >> n;
  int x = 1, y = n, lst = -1;
  while (x <= y) {
    int mid = (x+y)/2;
    cout << "? " << "1 1 " << n << " " << mid << endl;
    cin >> lst;
    if (lst == 0) {
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  cout << "? " << "1 " << x << " " << n << " " << n << endl;
  cin >> lst;
  if (lst == 0) {
    x = 1, y = n, lst = -1;
    while (x <= y) {
      int mid = (x+y)/2;
      cout << "? " << "1 1 " << mid << " " << n << endl;
      cin >> lst;
      if (lst == 0) {
        x = mid + 1;
      } else {
        y = mid - 1;
      }
    }
    int x11, y11, x12, y12;
    int x21, y21, x22, y22;
    tie(x11, y11, x12, y12) = ver(1, x);
    tie(x21, y21, x22, y22) = ver(x+1, n);
    cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " " << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
    return 0;
  }
  int x11, y11, x12, y12;
  int x21, y21, x22, y22;
  tie(x11, y11, x12, y12) = hor(1, x);
  tie(x21, y21, x22, y22) = ver(x+1, n);
  cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " " << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
  return 0;
}
