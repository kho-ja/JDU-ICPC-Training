#include <iostream>
using namespace std;

int main() {
    int n, mx;
    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    mx = max(a[1], a[n - 2]) + a[0] + a[n - 1];
    for (int i = 1; i < n - 1; i++) mx = max(mx, a[i - 1] + a[i] + a[i + 1]);

    cout << mx;
    return 0;
}