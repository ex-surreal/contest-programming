#include <string>
#include <algorithm>

using namespace std;
class big_int {
    std::string a;
    int sign;
    public:
    big_int() {}
    big_int(string b) {
        (*this) = b;
    }
    big_int(int num) {
        (*this) = num;
    }
    big_int(long long num) {
        (*this) = num;
    }
    int size() {
        return (int) a.size();
    }
    big_int inverse_sign() {
        sign *= -1;
        return (*this);
    }
    big_int normalize(int new_sign) {
        for (int i = (int) a.size() - 1; i > 0 && a[i] == '0'; i--) {
            a.erase(a.begin() + i);
        }
        sign = (a.size() == 1u && a[0] == '0') ? 1 : new_sign;
        return (*this);
    }
    void operator = (string b) {
        if ((int) b.size() == 0) {
            a = "0";
            sign = 1;
            return;
        }
        a = b[0] == '-' ? b.substr(1) : b;
        std::reverse(a.begin(), a.end());
        this->normalize(b[0] == '-' ? -1 : 1);
    }
    void operator = (long long num) {
        if (num < 0) {
            sign = -1;
            num = -num;
        } else {
            sign = 1;
        }
        a = (num != 0 ? "" : "0");
        while (num) {
            a.push_back('0' + num % 10);
            num /= 10;
        }
        this->normalize(sign);
    }
    bool operator < (const big_int & b) const {
        if (sign != b.sign) {
            return sign < b.sign;
        }
        if (a.size() != b.a.size()) {
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        }
        for (int i = (int) a.size() - 1; i >= 0; i--) {
            if (a[i] != b.a[i]) {
                return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
            }
        }
        return false;
    }
    bool operator == (const big_int & b) const {
        return a == b.a && sign == b.sign;
    }
    bool operator != (const big_int & a) const {
        return !((*this) == a);
    }
    bool operator > (const big_int & a) const {
        return !((*this) == a) && !((*this) < a);
    }
    big_int operator + (big_int b) {
        if (sign != b.sign) return (*this) - b.inverse_sign();
        big_int c;
        for (int i = 0, carry = 0; i < (int) a.size() || i < (int) b.size() || carry; i++) {
            carry += (i < (int) a.size() ? a[i] - 48 : 0) + (i < (int) b.a.size() ? b.a[i] - 48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }

    big_int operator - (big_int b) {
        if (sign != b.sign) {
            return (*this) + b.inverse_sign();
        }
        int s = sign;
        sign = b.sign = 1;
        if ((*this) < b) {
            return ((b - (*this)).inverse_sign()).normalize(-s);
        }
        big_int c;
        for (int i = 0, borrow = 0; i < (int) a.size(); i++) {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }

    big_int operator * (big_int b) {
        big_int c("0");
        for (int i = 0, k = a[i] - 48; i < (int) a.size(); i++, k = a[i] - 48) {
            while (k--) c = c + b;
            b.a.insert(b.a.begin(), '0');
        }
        return c.normalize(sign * b.sign);
    }

    big_int operator / (big_int b) {
        if (b.size() == 1 && b.a[0] == '0') {
            b.a[0] /= (b.a[0] - 48);
        }
        big_int c("0"), d;
        for (int j = 0; j < (int) a.size(); j++) {
            d.a += "0";
        }
        int d_sign = sign * b.sign;
        b.sign = 1;
        for (int i = (int) a.size() - 1; i >= 0; i--) {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b)) {
                c = c - b, d.a[i]++;
            }
        }
        return d.normalize(d_sign);
    }

    big_int operator % (big_int b) {
        if (b.size() == 1 && b.a[0] == '0') {
            b.a[0] /= (b.a[0] - 48);
        }
        big_int c("0");
        b.sign = 1;
        for (int i = (int) a.size() - 1; i >= 0; i--) {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b)) {
                c = c - b;
            }
        }
        return c.normalize(sign);
    }

    big_int pow(big_int ex) {
        big_int base = (*this), res = 1;
        while (ex > big_int(0)) {
            if (ex % big_int(2) == big_int(1)) {
                res = res * base;
            }
            base = base * base;
            ex = ex / big_int(2);
        }
        return res;
    }

    string tostr() {
        string str = a;
        if (sign < 0) {
            str.push_back('-');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

istream & operator >> (istream & i, big_int & a) {
    string s;
    i >> s;
    a = big_int(s);
    return i;
}

ostream & operator << (ostream & st, big_int a) {
    st << a.tostr();
    return st;
}
