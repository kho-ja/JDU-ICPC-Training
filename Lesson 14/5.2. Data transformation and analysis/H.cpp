#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    int total = 0;
    int max_future = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > max_future) max_future = a[i];
        total += max_future;
    }

    cout << total;
    return 0;
}