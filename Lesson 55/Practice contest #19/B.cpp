#include <cctype>
#include <iostream>
using namespace std;

int main() {
    string s, res;
    cin >> s;
    if (s == "" || isupper(s[0]) || s.front() == '_' || s.back() == '_') {
        cout << "Xatolik";
        return 0;
    }
    else if (s.find('_') == string::npos) {
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) {
                res += '_';
                res += tolower(s[i]);
                continue;
            }
            res += s[i];
        }
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '_') {
                i++;
                if (isupper(s[i])) {
                    cout << "Xatolik";
                    return 0;
                }
                else {
                    res += toupper(s[i]);
                }
                continue;
            }
            res += s[i];
        }
    }
    cout << res;
    return 0;
}
