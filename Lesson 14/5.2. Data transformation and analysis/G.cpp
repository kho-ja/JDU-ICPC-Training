// #include <iostream>
// using namespace std;

// int main() {
//     int n, a[100], plusSum = 0, mn = 1000000000, mnID, mx = -1000000000, mxID, mntomxproduct = 1;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         if (a[i] > 0) {
//             plusSum += a[i];
//         }
//         if (a[i] < mn) {
//             mn = a[i];
//             mnID = i;
//         }
//         if (a[i] > mx) {
//             mx = a[i];
//             mxID = i;
//         }
//     }

//     int left = min(mnID, mxID), right = max(mnID, mxID);

//     for (int i = left + 1; i < right; i++) {
//         mntomxproduct *= a[i];
//     }

//     cout << plusSum << " " << mntomxproduct;
//     return 0;
// }

// you do not need to store mn and mx, indexes are enough
#include <iostream>
using namespace std;

int main() {
    int n, a[100], mn = 0, mx = 0, plusSum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            plusSum += a[i];
        }
        if (i == 0 || a[i] < a[mn]) {
            mn = i;
        }
        if (i == 0 || a[i] > a[mx]) {
            mx = i;
        }
    }

    int left = min(mn, mx), right = max(mn, mx);

    long long mntomxproduct = 1;
    for (int i = left + 1; i < right; i++) {
        mntomxproduct *= a[i];
    }

    cout << plusSum << " " << mntomxproduct;
    return 0;
}