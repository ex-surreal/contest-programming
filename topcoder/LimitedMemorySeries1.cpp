#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>

using namespace std;
int cnt[1 << 0xf];

class LimitedMemorySeries1 {
    static const int mod = 1e9+7;
    int getKth(int n, int x0, int a, int b, int q) {
        memset(cnt, 0, sizeof cnt);
        cnt[x0 >> 0xf] = 1;
        for (int i = 1, x = x0; i < n; i ++) {
            x = (1ll*x*a + b) % mod;
            cnt[x >> 0xf] ++;
        }
        for (int i = 1; i < (1 << 0xf); i ++) {
            cnt[i] += cnt[i-1];
        }
        int c = -1;
        for (int i = 0; i < (1 << 0xf); i ++) {
            if (cnt[i] >= q) {
                c = i;
                break;
            }
        }
        assert(c != -1);
        int qx = q - (c == 0 ? 0 : cnt[c-1]);
        memset(cnt, 0, sizeof cnt);
        if ((x0 >> 0xf) == c) {
            cnt[x0 & 0x7fff] = 1;
        }
        for (int i = 1, x = x0; i < n; i ++) {
            x = (1ll*x*a + b) % mod;
            if ((x >> 0xf) == c) {
                cnt[x & 0x7fff] ++;
            }
        }
        for (int i = 1; i < (1 << 0xf); i ++) {
            cnt[i] += cnt[i-1];
        }
        for (int i = 0; i < (1 << 0xf); i ++) {
            if (cnt[i] >= qx) {
                return (c << 0xf)|i;
            }
        }
        return 0;
    }
public:
    long long getSum(int n, int x0, int a, int b, vector <int> query) {
        long long ret = 0;
        for (auto q: query) {
            ret += getKth(n, x0, a, b, q+1);
        }
        return ret;
    }
};


int main () {
    LimitedMemorySeries1 obj;
    cout << obj.getSum(5, 123456789, 987654321, 1000000006, {0,1,2,3});
    return 0;
}
