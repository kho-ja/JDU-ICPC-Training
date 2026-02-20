#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    int x, mn = a[0];
    cin >> x;

    for (int i = 1; i < n; i++)
        if (abs(a[i] - x) < abs(mn - x)) mn = a[i];
        else if (abs(a[i] - x) == abs(mn - x) && a[i] < mn) mn = a[i];

    cout << mn;
    return 0;
}