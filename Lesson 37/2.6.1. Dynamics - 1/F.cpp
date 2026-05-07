#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct BigInt {
    vector<int> digits;
    int sign; // -1, 0, 1
    void clear_leading_zeros() {
        while (!digits.empty() && digits.back() == 0) digits.pop_back();
        if (digits.empty()) sign = 0;
    }
    BigInt() {
        sign = 0;
    }
    BigInt(string s) {
        if (s.front() == '-') {
            *this = BigInt(s.substr(1));
            sign = -sign;
        }
        else if (s.front() == '+') {
            *this = BigInt(s.substr(1));
        }
        else {
            sign = 1;
            for (int i = (int)s.size() - 1; i >= 0; i--)
                digits.push_back(s[i] - '0');
            clear_leading_zeros();
        }
    }
    BigInt(int n) {
        *this = BigInt(::to_string(n));
    }
    string to_string() {
        string s = "";
        if (sign == -1) s += '-';
        if (sign == 0) s += '0';
        for (int i = (int)digits.size() - 1; i >= 0; i--)
            s += char(digits[i] + '0');
        return s;
    }
    BigInt operator -() {
        BigInt res = *this;
        res.sign = -res.sign;
        return res;
    }
    BigInt friend operator +(BigInt a, BigInt b) {
        if (a.sign == 0) return b;
        if (b.sign == 0) return a;
        if (b.sign == -1) return a - (-b);
        if (a.sign == -1) return b - (-a);
        BigInt c;
        c.sign = 1;
        int carry = 0;
        for (size_t i = 0; i < a.digits.size() || i < b.digits.size() || carry; i++) {
            int sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            c.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return c;
    }
    BigInt friend operator +=(BigInt &a, BigInt b) {
        a = a + b;
        return a;
    }
    BigInt friend operator -(BigInt a, BigInt b) {
        if (b.sign == 0) return a;
        if (a.sign == 0) return -b;
        if (b.sign == -1) return a + (-b);
        if (a.sign == -1) return -((-a) + b);
        if (a < b) return -(b - a);
        for (int i = 0; i < (int)a.digits.size(); i++) {
            a.digits[i] -= (i < (int)b.digits.size() ? b.digits[i] : 0);
            if (a.digits[i] < 0) {
                a.digits[i] += 10;
                a.digits[i + 1]--;
            }
        }
        a.clear_leading_zeros();
        return a;
    }
    bool friend operator <(BigInt a, BigInt b) {
        if (a.sign != b.sign) return a.sign < b.sign;
        if (a.sign == 0) return false;
        if (a.digits.size() != b.digits.size())
            return a.digits.size() * a.sign < b.digits.size() * b.sign;
        for (int i = (int)a.digits.size() - 1; i >= 0; i--)
            if (a.digits[i] != b.digits[i])
                return a.digits[i] * a.sign < b.digits[i] * b.sign;
        return false;
    }
    BigInt friend operator *(BigInt a, int b) {
        if (b == 0 || a.sign == 0) return 0;
        if (b < 0) {
            a.sign = -a.sign;
            b = -b;
        }
        long long carry = 0;
        for (int i = 0; i < (int)a.digits.size() || carry; i++) {
            if (i < (int)a.digits.size()) carry += 1LL * a.digits[i] * b;
            if (i < (int)a.digits.size()) a.digits[i] = carry % 10;
            else a.digits.push_back(carry % 10);
            carry /= 10;
        }
        return a;
    }
    void operator *=(int b) {
        *this = *this * b;
    }
};
istream& operator >>(istream& cin, BigInt& a) {
    string s;
    cin >> s;
    a = BigInt(s);
    return cin;
}

ostream& operator <<(ostream& cout, BigInt a) {
    cout << a.to_string();
    return cout;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<BigInt> dp(n + 1);
    dp[0] = BigInt("1");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++)
            dp[i] += dp[i - j];
    cout << dp[n];
    return 0;
}
