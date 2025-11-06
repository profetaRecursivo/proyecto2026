#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct BigInteger {
    static const int base = 1000000000;
    static const int base_digits = 9;

    vector<int> a;
    int sign;

    BigInteger(): sign(1) {}
    BigInteger(ll v) { *this = v; }
    BigInteger(const string &s) { read(s); }

    BigInteger& operator=(ll v) {
        sign = 1;
        if (v < 0) sign = -1, v = -v;
        a.clear();
        while (v > 0) {
            a.push_back(v % base);
            v /= base;
        }
        return *this;
    }

    BigInteger operator-() const {
        BigInteger res = *this;
        if (!res.isZero()) res.sign = -sign;
        return res;
    }

    bool isZero() const { return a.empty() || (a.size() == 1 && a[0] == 0); }

    static int absCompare(const BigInteger &x, const BigInteger &y) {
        if (x.a.size() != y.a.size()) return x.a.size() < y.a.size() ? -1 : 1;
        for (int i = (int)x.a.size() - 1; i >= 0; --i)
            if (x.a[i] != y.a[i]) return x.a[i] < y.a[i] ? -1 : 1;
        return 0;
    }

    bool operator<(const BigInteger &v) const {
        if (sign != v.sign) return sign < v.sign;
        int cmp = absCompare(*this, v);
        return sign == 1 ? (cmp < 0) : (cmp > 0);
    }
    bool operator>(const BigInteger &v) const { return v < *this; }
    bool operator<=(const BigInteger &v) const { return !(v < *this); }
    bool operator>=(const BigInteger &v) const { return !(*this < v); }
    bool operator==(const BigInteger &v) const { return sign == v.sign && a == v.a; }
    bool operator!=(const BigInteger &v) const { return !(*this == v); }

    void trim() {
        while (!a.empty() && a.back() == 0) a.pop_back();
        if (a.empty()) sign = 1;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -1;
            ++pos;
        }
        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; ++j)
                x = x * 10 + (s[j] - '0');
            a.push_back(x);
        }
        trim();
    }

    friend ostream& operator<<(ostream &out, const BigInteger &v) {
        if (v.sign == -1 && !v.isZero()) out << '-';
        if (v.a.empty()) out << 0;
        else {
            out << v.a.back();
            char buf[16];
            for (int i = (int)v.a.size() - 2; i >= 0; --i) {
                snprintf(buf, sizeof(buf), "%09d", v.a[i]);
                out << buf;
            }
        }
        return out;
    }

    friend istream& operator>>(istream &in, BigInteger &v) {
        string s;
        in >> s;
        v.read(s);
        return in;
    }

    // ---- helpers para suma/resta absoluta ----
    static BigInteger addAbs(const BigInteger &x, const BigInteger &y) {
        BigInteger res;
        ll carry = 0;
        size_t n = max(x.a.size(), y.a.size());
        res.a.resize(n);
        for (size_t i = 0; i < n; ++i) {
            ll cur = carry;
            if (i < x.a.size()) cur += x.a[i];
            if (i < y.a.size()) cur += y.a[i];
            res.a[i] = int(cur % base);
            carry = cur / base;
        }
        if (carry) res.a.push_back(int(carry));
        return res;
    }

    static BigInteger subAbs(const BigInteger &x, const BigInteger &y) {
        // assume |x| >= |y|
        BigInteger res;
        ll carry = 0;
        res.a.resize(x.a.size());
        for (size_t i = 0; i < x.a.size(); ++i) {
            ll cur = x.a[i] - carry - (i < y.a.size() ? y.a[i] : 0);
            if (cur < 0) cur += base, carry = 1;
            else carry = 0;
            res.a[i] = int(cur);
        }
        res.trim();
        return res;
    }

    // ---- operadores no mutantes (usados internamente y por compatibilidad) ----
    BigInteger operator+(const BigInteger &v) const {
        if (sign == v.sign) {
            BigInteger res = addAbs(*this, v);
            res.sign = sign;
            return res;
        }
        if (absCompare(*this, v) >= 0) {
            BigInteger res = subAbs(*this, v);
            res.sign = sign;
            return res;
        } else {
            BigInteger res = subAbs(v, *this);
            res.sign = v.sign;
            return res;
        }
    }

    BigInteger operator-(const BigInteger &v) const {
        if (sign == v.sign) {
            if (absCompare(*this, v) >= 0) {
                BigInteger res = subAbs(*this, v);
                res.sign = sign;
                return res;
            } else {
                BigInteger res = subAbs(v, *this);
                res.sign = -v.sign;
                return res;
            }
        }
        BigInteger res = addAbs(*this, v);
        res.sign = sign;
        return res;
    }

    BigInteger operator*(const BigInteger &v) const {
        BigInteger res;
        res.a.assign(a.size() + v.a.size(), 0);
        for (size_t i = 0; i < a.size(); ++i) {
            ll carry = 0;
            for (size_t j = 0; j < v.a.size() || carry; ++j) {
                ll cur = res.a[i + j] + 1LL * a[i] * (j < v.a.size() ? v.a[j] : 0) + carry;
                res.a[i + j] = int(cur % base);
                carry = cur / base;
            }
        }
        res.sign = sign * v.sign;
        res.trim();
        return res;
    }

    BigInteger operator/(int v) const {
        BigInteger res = *this;
        if (v < 0) res.sign = -res.sign, v = -v;
        ll rem = 0;
        for (int i = (int)res.a.size() - 1; i >= 0; --i) {
            ll cur = res.a[i] + rem * base;
            res.a[i] = int(cur / v);
            rem = cur % v;
        }
        res.trim();
        return res;
    }

    int operator%(int v) const {
        if (v < 0) v = -v;
        ll m = 0;
        for (int i = (int)a.size() - 1; i >= 0; --i)
            m = (a[i] + m * base) % v;
        return int(m * sign);
    }

    // ---- operadores compuestos (mutantes) ----

    // += BigInteger
    BigInteger& operator+=(const BigInteger &v) {
        if (sign == v.sign) {
            *this = addAbs(*this, v);
            this->sign = sign; // mantiene signo
        } else {
            int cmp = absCompare(*this, v);
            if (cmp >= 0) {
                *this = subAbs(*this, v);
                // sign no cambia
            } else {
                *this = subAbs(v, *this);
                this->sign = v.sign;
            }
        }
        return *this;
    }

    // += ll (útil)
    BigInteger& operator+=(ll v) {
        BigInteger tmp(v);
        return *this += tmp;
    }

    BigInteger& operator-=(const BigInteger &v) {
        if (sign != v.sign) {
            *this = addAbs(*this, v);
            // sign mantiene
        } else {
            int cmp = absCompare(*this, v);
            if (cmp >= 0) {
                *this = subAbs(*this, v);
                // sign no cambia
            } else {
                *this = subAbs(v, *this);
                this->sign = -this->sign;
            }
        }
        return *this;
    }

    BigInteger& operator-=(ll v) {
        BigInteger tmp(v);
        return *this -= tmp;
    }

    // *= BigInteger (naive O(n*m))
    BigInteger& operator*=(const BigInteger &v) {
        *this = (*this) * v;
        return *this;
    }

    // *= ll
    BigInteger& operator*=(ll m) {
        bool neg = false;
        if (m < 0) neg = true, m = -m;
        if (m == 0 || isZero()) {
            a.clear();
            sign = 1;
            return *this;
        }
        ll carry = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            ll cur = carry + 1LL * a[i] * m;
            a[i] = int(cur % base);
            carry = cur / base;
        }
        while (carry) {
            a.push_back(int(carry % base));
            carry /= base;
        }
        if (neg) sign = -sign;
        trim();
        return *this;
    }

    // /= int (ya estaba no mutante; ahora mutante)
    BigInteger& operator/=(int v) {
        *this = (*this) / v;
        return *this;
    }

    // %= int (mutante)
    BigInteger& operator%=(int v) {
        int r = (*this) % v;
        *this = r;
        return *this;
    }

    // ---- conversores y utilidades adicionales ----
    ll toLongLong() const {
        ll res = 0;
        for (int i = (int)a.size() - 1; i >= 0; --i)
            res = res * base + a[i];
        return res * sign;
    }
};