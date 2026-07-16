#include <iostream>
using namespace std;

bool is_palindrome(string s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r]) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    if (is_palindrome(s)) s.pop_back();
    if (is_palindrome(s)) cout << "NO SOLUTION";
    else cout << s;
    return 0;
}
