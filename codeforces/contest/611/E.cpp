#include <iostream>
#include <algorithm>

using namespace std;

int t[200005];

void sort(int &a, int &b, int &c) {
    vector <int> temp({a, b, c});
    sort(temp.begin(), temp.end());
    a = temp[0];
    b = temp[1];
    c = temp[2];
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i ++) {
        cin >> t[i];
    }
    sort(a, b, c);
    sort(t, t+n);
    int A = 0, B = 0, C = 0;
    for (int i = 0; i < n; i ++) {
        if (t[i] <= a) {
            A ++;
        } else if (t[i] <= b) {
            B ++;
        } else if (t[i] <= c) {
            C ++;
        }
    }
    try {
        int ans = 0;
        for (int i = n-1, lim = A+B+C; i >= lim; i --) {
            if (a+b >= t[i]) {
                ans ++;
                C --;
            } else if (a+c >= t[i]) {
                ans ++;
                B --;
            } else if (b+c >= t[i]) {
                ans ++;
                A --;
            } else if (a+b+c >= t[i]) {
                ans ++;
            } else {
                throw -1;
            }
        }
        
        cout << ans + calc(A, B, C) << endl;
    } catch (int e) {
        cout << e << endl;
    }
    return 0;
}
