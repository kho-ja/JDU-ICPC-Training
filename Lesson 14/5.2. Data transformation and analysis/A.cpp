//* reverse the array
// #include <iostream>
// using namespace std;

// int main() {
//     int a[1000], n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     for (int l = 0, r = n - 1; l < r; l++, r--) {
//         swap(a[l], a[r]);
//     }
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
//     return 0;
// }

//* just print in reverse order
// #include <iostream>
// using namespace std;

// int main() {
//     int a[1000], n;
//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = n - 1; i >= 0; i--) cout << a[i] << " ";
//     return 0;
// }

//* input array in reverse order
#include <iostream>
using namespace std;

int main() {
    int a[1000], n;
    cin >> n;
    for (int i = n - 1; i >= 0; i--) cin >> a[i];
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}