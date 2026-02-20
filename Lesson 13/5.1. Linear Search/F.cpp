#include <iostream>
using namespace std;

int main() {
    int n, j = 0;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    int b[100];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 1; i < n; i++)
        if (a[i] * b[i] > a[j] * b[j]) j = i;

    cout << j + 1;
    return 0;
}