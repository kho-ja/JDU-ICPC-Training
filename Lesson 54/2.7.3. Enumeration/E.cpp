#include <iostream>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    if (m > n) cout << 0;
    else if (m == 0) cout << 1;
    else if (m == 1) cout << n;
    else {
        int k = (n - m + 1) / (m - 1);
        cout << (n - m + 1) * (k + 1) - (m - 1) * k * (k + 1) / 2;
    }
    return 0;
}
