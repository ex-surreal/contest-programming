#include <bits/stdc++.h>

using namespace std;

int fun(long long l, long long r, long long k) {
    long long ans = 1;
    while (ans < l) ans *= k;
    while (l <= ans && ans <= r) {
        if (ans*k/k != ans && ans >= l && ans <= r) {
            throw k;
        }
        ans *= k;
    }
    return 0;
}

int main() {
    int k = 2;

    while (k < 10000000) {
        try {
            fun(1ll, 100000000000000ll, k);
        } catch (long long j) {
            cout << j << endl;
            return 0;
        }
        k ++;
    }
    return 0;
}
