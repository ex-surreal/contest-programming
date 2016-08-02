#include <bits/stdc++.h>

using namespace std;

int is_nice(string &a) {
    if (a[0] != '1') {
        throw a;
    }
    int ret = 0;
    for (int i = 1; i < int(a.size()); i ++) {
        if (a[i] != '0') {
            throw a;
        }
        ret ++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string prefix = "1", suffix = "";
    int zero = 0;
    for (int i = 0; i < n; i ++) {
        string q;
        cin >> q;
        if (q == "0") {
            zero = 1;
        }
        try {
            suffix += string(is_nice(q), '0');
        } catch (string a) {
            prefix = a;
        }
    }
    if (zero) {
        cout << "0\n";
        return 0;
    }
    cout << prefix + suffix << "\n";
    return 0;
}
