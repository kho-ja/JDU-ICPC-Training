// #include <iostream>
// using namespace std;

// int main() {
//     int n, odd[100], even[100], oddCount = 0, evenCount = 0;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         if (x % 2 == 0) {
//             even[evenCount++] = x;
//         } else {
//             odd[oddCount++] = x;
//         }
//     }
//     for (int i = 0; i < oddCount; i++) {
//         cout << odd[i] << " ";
//     }
//     cout << "\n";
//     for (int i = 0; i < evenCount; i++) {
//         cout << even[i] << " ";
//     }
//     cout << "\n";
//     cout << (oddCount <= evenCount ? "YES" : "NO");
//     return 0;
// }

//* you do not need to store the even numbers count
#include <iostream>
using namespace std;

int main() {
    int n, a[100], oddCount = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            oddCount++;
            cout << a[i] << " ";
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            cout << a[i] << " ";

    cout << (oddCount <= n - oddCount ? "YES" : "NO");
    return 0;
}