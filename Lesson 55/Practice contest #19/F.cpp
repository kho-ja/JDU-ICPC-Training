#include <iostream>
using namespace std;
using ll = long long;

int main() {
    string s = string(20, 'A'), a;
    cout << "? " << s << "\n";
    bool end = false;
    while (!end) {
        cin >> a;
        bool changed = false;
        for (int i = 0; i < 20; i++) {
            if (a[i] == '0') {
                s[i] = char(1+s[i]);
                changed = true;
            }
        }
        if (!changed) {
            end = true;
            cout << "! " << s << "\n";
            cout.flush();
        }
        else {
            cout << "? " << s << "\n";
        }
    }
    return 0;
}
