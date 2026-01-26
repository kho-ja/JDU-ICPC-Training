// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     int M1, M2, M3;
//     cin >> M1 >> M2 >> M3;

//     if (M1 < 94 || M1 > 727 ||
//         M2 < 94 || M2 > 727 ||
//         M3 < 94 || M3 > 727) {
//         cout << "Error";
//     } else {
//         cout << max({M1, M2, M3});
//     }
// }

#include <iostream>
using namespace std;

int main() {
    int M1, M2, M3;
    cin >> M1 >> M2 >> M3;

    if (M1 > M2) swap(M1, M2);
    if (M1 > M3) swap(M1, M3);
    if (M2 > M3) swap(M2, M3);
    if (M1 < 94 || M3 > 727) {
        cout << "Error";
    } else {
        cout << M3;
    }
}