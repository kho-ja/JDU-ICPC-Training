#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (string(s.size(), 'x') == s || s.size() < 3) {
        cout << "Hech kim";
        return 0;
    }
    int curr = 0, mxcr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') {
            curr++;
        }
        if (curr > mxcr) mxcr = curr;
    }
    if (mxcr >= 3) {
        cout << "Birinchi";
    }
    else if (mxcr >= 2) {
        cout << "Birinchi";
    }
    else if (mxcr >= 1) {
        cout << "Ikkinchi";
    }
    else {
        cout << "Birinchi";
    }
    return 0;
}
