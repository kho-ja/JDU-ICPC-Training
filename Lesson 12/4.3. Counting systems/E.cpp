// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s;
//     getline(cin, s);

//     int mx = -1;

//     for (char c : s) {
//         int x = 0;

//         if (isdigit(c)) {
//             x = c - '0';
//             if (x > mx) mx = x;
//         }
//         else if (c >= 'A' && c <= 'Z') {
//             x = c - 'A' + 10;
//             if (x > mx) mx = x;
//         }
//         else {
//             cout << -1 << "\n";
//             return 0;
//         }
//     }

//     int base = max(mx + 1, 2);
//     if (base > 36) cout << -1 << "\n";
//     else cout << base << "\n";

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int r = 2;
    getline(cin, s);

    for (char c : s) {
        if (isdigit(c)) r = max(r, c - 47);
        else if (c >= 'A' && c <= 'Z') r = max(r, c - 54);
        else {
            r = -1;
            break;
        }
    }

    cout << r << "\n";
    return 0;
}