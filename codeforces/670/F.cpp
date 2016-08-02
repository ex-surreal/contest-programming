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

int cnt[10];

int len(int x) {
    int ret = 0;
    while (x > 0) {
        x /= 10;
        ret ++;
    }
    return ret;
}

int min_pos(int first) {
    repi(i, first, 10) {
        if (cnt[i]) {
            return i;
        }
    }
    return -1;
}

string go(string q, bool f = true) {
    bool q_printed = false, first = f;
    int t;
    string ret = "";
    while (!q_printed) {
        string k = "";
        if ((t = min_pos(first)) == q[sz(k)] - '0') {
            k.pb(t+'0');
            first = false;
            cnt[t] --;
            if (t == min_pos(first)) {
                while (sz(k) < sz(q) && cnt[t] > 0 && t == q[sz(k)] - '0') {
                    k.pb(t+'0');
                    cnt[t] --;
                }
            }
        }
        //cout << endl << "*** " << k << " " << min_pos(first) << " " << q << " ***" << endl;
        if (t == -1) {
            ret += min(k+q, q+k);
            q_printed = true;
        } else {
            if (q == k) {
                ret += q+k;
                q_printed = true;
            } else {
                if ((t = min_pos(first)) > q[sz(k)] - '0') {
                    ret += min(k+q, q+k);
                    q_printed = true;
                } else {
                    ret += k;
                    if (sz(k) == 0) {
                        ret.pb(t+'0');
                        cnt[t] --;
                    }
                }
            }
        }
        first = false;
    }
    while ((t = min_pos(0)) != -1) {
        ret += string(cnt[t], '0'+t);
        cnt[t] = 0;
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    string p, q;
    cin >> p >> q;
    sort(all(p));
    if (p == "01") {
        cout << 0;
        return 0;
    }
    repe(c, p) {
        cnt[c-'0'] ++;
    }
    repe(c, q) {
        cnt[c-'0'] --;
    }
    int l = -1;
    repi(x, 1, sz(p)+1) {
        if (len(x)+x == sz(p)) {
            l = x;
            break;
        }
    }
    while (l > 0) {
        cnt[l%10] --;
        l /= 10;
    }
    if (q[0] != '0') {
        string f = q;
        rep(i, 10) {
            f += string(cnt[i], i+'0');
        }
        string t = go(q);
        cout << min(f, t);
    } else {
        int t = min_pos(1);
        cnt[t] --;
        cout << t;
        cout << go(q, false);
    }
    return 0;
}
