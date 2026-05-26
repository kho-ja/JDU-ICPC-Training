#include <iostream>
using namespace std;

int main() {
    int n, mn = 2e9, mxl;
    cin >> n;
    if (n == 1) {
        cout << 1 << " " << 1;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int num = (n + i - 1) / i;
        if (num + i < mn) {
            mn = num + i;
            mxl = i;
        }
    }
    cout << mxl << " " << mn - mxl << endl;
    return 0;
}
