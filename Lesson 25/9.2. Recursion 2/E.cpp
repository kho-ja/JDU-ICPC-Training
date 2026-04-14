#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_template(const string& s, const string& s1) {
    if (s.empty()) return s1.empty();
    if (s1.empty()) return false;
    if (s[0] == '*') {
        return is_template(s.substr(1), s1) || is_template(s, s1.substr(1));
    }
    if (s[0] == '?' || s[0] == s1[0]) {
        return is_template(s.substr(1), s1.substr(1));
    }
    return false;
}

int main() {
    string s, s1;
    cin >> s >> s1;
    if (s.find('?') != string::npos || s.find('*') != string::npos) swap(s, s1);
    cout << (is_template(s, s1) ? "YES" : "NO") << endl;
    return 0;
}