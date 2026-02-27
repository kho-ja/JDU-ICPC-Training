#include <iostream>
using namespace std;

int digital_root(int n) {
    return (n - 1) % 9 + 1;
}

bool is_happy(string s) {
    int sum = 0, sumr = 0;
    for (char c : s) sum += c - '0';
    for (int i = 0; i < s.size() - 1; i++) {
        sumr += s[i] - '0';
        if (digital_root(sum - sumr) == digital_root(sumr)) return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (is_happy(s) ? "YES" : "NO");
    return 0;
}