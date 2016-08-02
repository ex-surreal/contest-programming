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

string add(string a, string b) {
    int c = 0;
    string ret = "";
    for (int i = sz(a)-1; i >= 0; i--) {
        int s = a[i]+b[i]-2*'0'+c;
        ret.pb(s%10+'0');
        c = s/10;
    }
    if (c > 0) {
        ret.pb('0'+c);
    }
    reverse(all(ret));
    return ret;
}

bool creeper(string s) {
    int cnt[10] = {0};
    repe(c, s) {
        cnt[c-'0'] ++;
    }
    return (cnt[1] == 1 && cnt[2] == 1 && cnt[3] > 1 && cnt[4] == 4 && accumulate(cnt+1, cnt+5, 0) == sz(s)) || (cnt[5] == 2 && cnt[6] > 1 && cnt[7] == 4 && cnt[6]+cnt[5]+cnt[7] == sz(s));
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst --) {
        int cas, m;
        string s;
        cin >> cas >> m >> s;
        reverse(all(s));
        map <string, bool> seen;
        string ans;
        try {
            rep(i, m) {
                if (seen[s]) {
                    cout << cas << " R " << i+1 << "\n";
                    throw -1;
                }
                //cout << "**** " << s << endl;
                if (creeper(s)) {
                    cout << cas << " C " << i+1 << "\n";
                    throw -1;
                }
                ans = s;
                seen[s] = true;
                string t = s;
                reverse(all(t));
                t = add(s, t);
                sort(all(t));
                while (sz(t) > 1 && t[0] == '0') {
                    t = t.substr(1);
                }
                s = t;
            }
            cout << cas << " " << ans << "\n";
        } catch (int ex) {
            // Do nothing
        }
    }
    return 0;
}
