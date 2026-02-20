#include <iostream>
using namespace std;

int main() {
    int n, x, mx = -1001, mn = 1001;
    cin >> n;
    int a[1001];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
    }

    for (int i = 0; i < n; i++)
        if (a[i] == mx) cout << mn << " ";
        else cout << a[i] << " ";

    return 0;
}