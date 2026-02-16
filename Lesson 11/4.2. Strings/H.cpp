#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 26; i++) {
        if (s1.find(s2) != string::npos) {
            cout << s1;
            return 0;
        }
        for (char &c : s1) {
            c = c == 'A' ? 'Z' : c - 1;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}