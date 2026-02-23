#include <iostream>
using namespace std;

int main() {
    int n, a[100], plusSum = 0, mn = 1000000000, mnID, mx = -1000000000, mxID, mntomxproduct = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            plusSum += a[i];
        }
        if (a[i] < mn) {
            mn = a[i];
            mnID = i;
        }
        if (a[i] > mx) {
            mx = a[i];
            mxID = i;
        }
    }

    int left = min(mnID, mxID), right = max(mnID, mxID);

    for (int i = left + 1; i < right; i++) {
        mntomxproduct *= a[i];
    }

    cout << plusSum << " " << mntomxproduct;
    return 0;
}