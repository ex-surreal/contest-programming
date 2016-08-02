#include <bits/stdc++.h>
using namespace std;

string solve (int k, string s) {
vector <int> cnt(26, 0);
for (auto c: s) {
cnt[c-'a'] ++;
}
for (auto c: cnt) {
if (c % k != 0) {
return "-1";
}
}
string e = "", ret = "";
for (int i = 0; i < 26; i ++) {
e += string(cnt[i]/k, 'a'+i);
}
for (int i = 0; i < k; i ++) {
ret += e;
}
return ret;
}

int main () {
ios_base::sync_with_stdio(false);
int k;
string s;
cin >> k >> s;
cout << solve(k, s);
return 0;
}

