#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool seen = false;
    for (auto c: s) {
        if (!seen && c != '9') {
            cout << '9';
            seen = true;
        } else cout << c;
    }
    return 0;
}
