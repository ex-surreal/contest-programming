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
 
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
struct Bigint {
    // representations and structures
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise
 
    // constructors
    Bigint() {} // default constructor
    Bigint( string b ) { (*this) = b; } // constructor for string
 
    // some helpful methods
    int size() { // returns number of digits
        return a.size();
    }
    Bigint inverseSign() { // changes the sign
        sign *= -1;
        return (*this);
    }
    Bigint normalize( int newSign ) { // removes leading 0, fixes sign
        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
            a.erase(a.begin() + i);
        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }
 
    // assignment operator
    void operator = ( string b ) { // assigns a string to Bigint
        a = b[0] == '-' ? b.substr(1) : b;
        reverse( a.begin(), a.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
    }
 
    // conditional operators
    bool operator < ( const Bigint &b ) const { // less than operator
        if( sign != b.sign ) return sign < b.sign;
        if( a.size() != b.a.size() )
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )
            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator == ( const Bigint &b ) const { // operator for equality
        return a == b.a && sign == b.sign;
    }

 

    // mathematical operators
    Bigint operator + ( Bigint b ) { // addition operator overloading
        if( sign != b.sign ) return (*this) - b.inverseSign();
        Bigint c;
        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {
            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator - ( Bigint b ) { // subtraction operator overloading
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign; sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ ) {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator * ( Bigint b ) { // multiplication operator overloading
        Bigint c("0");
        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {
            while(k--) c = c + b; // ith digit is k, so, we add k times
            b.a.insert(b.a.begin(), '0'); // multiplied by 10
        }
        return c.normalize(sign * b.sign);
    }
    Bigint operator / ( Bigint b ) { // division operator overloading
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0"), d;
        for( int j = 0; j < a.size(); j++ ) d.a += "0";
        int dSign = sign * b.sign; b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- ) {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator % ( Bigint b ) { // modulo operator overloading
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0");
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- ) {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }

 

    // output method
    void print() {
        if( sign == -1 ) putchar('-');
        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
    }

    string tostr() {
        string ret = "";
        if( sign == -1 ) ret += "-";
        for( int i = a.size() - 1; i >= 0; i-- ) ret.push_back(a[i]);
        return ret;
    }
};

istream & operator >> (istream & i, Bigint & a) {
    string s;
    i >> s;
    a = Bigint(s);
    return i;
}

ostream & operator << (ostream & st, Bigint a) {
    st << a.tostr();
    return st;
}

vector <bool> term;
vector <map <char, int> > to;
vector <int> link;

void init() {
    term.clear();
    to.clear();
    link.clear();
    term.push_back(false);
    to.push_back(map <char, int>());
    link.push_back(-1);
}

void add_str(string &p) {
    int u = 0;
    for (int i = 0; i < int(p.size()); i ++) {
        if (!to[u].count(p[i])) {
            to[u][p[i]] = link.size();
            term.push_back(false);
            to.push_back(map <char, int>());
            link.push_back(-1);
        }
        u = to[u][p[i]];
    }
    term[u] = u;
}

void push_link() {
    vector <int> Q(link.size());
    int fr = 0, bk = 0;
    Q[bk ++] = 0;
    while (fr < bk) {
        int u = Q[fr ++];
        for (auto x: to[u]) {
            int v = x.second;
            char c = x.first;
            int j = link[u];
            while (j != -1 && !to[j].count(c)) {
                j = link[j];
            }
            link[v] = 0;
            if (j != -1) {
                link[v] = to[j][c];
            }
            Q[bk ++] = v;
        }
    }
}

Bigint dp[2][105][2];

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> p;
    string s;
    cin >> s;
    init();
    rep(i, p) {
        string q;
        cin >> q;
        add_str(q);
    }
    push_link();
    int now = 0, pre = 1;
    rep(i, 2) {
        rep(j, 105) {
            rep(k, 2) {
                dp[i][j][k] = string("0");
            }
        }
    }
    rep(i, sz(link)) {
        if (term[i]) {
            dp[now][i][0] = string("1");
        }
    }
    repi(i, 1, m+1) {
        swap(now, pre);
        rep(j, sz(link)) {
            dp[now][j][1] = dp[pre][0][1]*to_string(n-sz(to[j]));
            dp[now][j][0] = dp[pre][0][0]*to_string(n-sz(to[j]));
            repe(x, to[j]) {
                dp[now][j][1] = dp[now][j][1] + dp[pre][x.y][0];
                dp[now][j][0] = dp[now][j][0] + dp[pre][x.y][0];
            }
        }
    }
    cout << dp[now][0][1] << "\n";
    return 0;
}
