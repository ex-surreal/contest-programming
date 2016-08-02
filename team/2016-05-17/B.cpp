#include <bits/stdc++.h>

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

string get_str(int k, string p) {
    string ret = "";
    rep(i, k) {
        ret += p;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int n;
        cin >> n;
        map <string, int> cnt;
        rep(i, n) {
            string p;
            cin >> p;
            cnt[p] ++;
        }
        string c = "";
        c += get_str(cnt["aa"]/2, "aa");
        c += get_str(min(cnt["ab"], cnt["ba"]), "ab");
        c += get_str(cnt["bb"], "bb");
        c += get_str(min(cnt["ab"], cnt["ba"]), "ba");
        c += get_str(cnt["aa"]/2, "aa");

        string d = "";
        d += get_str(min(cnt["ab"], cnt["ba"]), "ab");
        d += get_str(cnt["bb"]/2, "bb");
        d += get_str(cnt["aa"], "aa");
        d += get_str(cnt["bb"]/2, "bb");
        d += get_str(min(cnt["ab"], cnt["ba"]), "ba");

        if (sz(c) > sz(d) || (sz(c) == sz(d) && c < d)) {
            cout << c << "\n";
        } else {
            cout << d << "\n";
        }

    }
    return 0;
}
